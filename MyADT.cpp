/*
 * MyADT.cpp
 * 
 * Class Description: A linear data collection ADT.
 *                    Its concrete data structure (CDT) is not expandable.  
 *                    This signifies that when this data collection becomes full,
 *                    you do not have to resize its data structure (not in this Assignment 1).  
 * 
 * Class Invariant: Data collection with the following characteristics:
 *                  - This is a value-oriented data collection and 
 *                    the elements are kept in ascending sort order of search key.
 *                  - Each element is unique (no duplicates). 
 *
 * Author: AL and Beyzanur Kuyuk
 * Last modified on: May 24, 2024
 */


#include <iostream>
#include <cctype>
#include "MyADT.h"     // Header file of MyADT file
#include "Profile.h"   // Header file of Profile class

using std::cout;
using std::endl;

    
// Default constructor.
MyADT::MyADT() {
   // cout << "MyADT::default constructor executed!" << endl;   // For testing purposes ...
   // You can also use the above cout to figure out when this constructor is executed.
   // If you do uncomment it, make sure to comment it out again before you submit your Assignment 1.
 
   
   for (unsigned int i=0; i<MAX_ALPHA;i++)
   {
        elements[i]=nullptr;
        elementCount[i]=0;
   }
   
}  

// Copy constructor - Covered in Lab 3
MyADT::MyADT(const MyADT& rhs) {
   // cout << "MyADT::copy constructor executed!" << endl; // For testing purposes ... 
   // You can also use the above cout to figure out when this constructor is executed.
   // If you do uncomment it, make sure to comment it out again before you submit your Assignment 1.

   //copy element count for each element : 
   for (unsigned int i = 0; i<MAX_ALPHA ; i++)
   {
    elementCount[i] = rhs.elementCount[i];
    if (elementCount[i]>0)
    {
        elements[i] = new Profile[MAX_ELEMENTS];

        //copy each profile object from the array:
        for (unsigned int j=0; j<elementCount[i]; j++) 
        {
            elements[i][j] = rhs.elements[i][j];
        }
    }
    else //array is empty:
    {
        elements[i] = nullptr;
    }
   }
   

   
}  

// Overloaded assignment operator - Covered in Lab 4
// Therefore, we shall not be overloading this operator in our Assignment 1
// MyADT & MyADT::operator=(const MyADT& rhs) { }
	
// Destructor - Covered in Lab 3
// Description: Destroys this object, releasing heap-allocated memory.
MyADT::~MyADT() {
   // cout << "MyADT::destructor" << endl;  // For testing purposes ...
   // You can also use the above cout to figure out when this destructor is executed.
   // If you do uncomment it, make sure to comment it out again before you submit your Assignment 1.
  
   

    for(unsigned int i=0; i< MAX_ALPHA; i++)
    {
    if (elements[i]!=nullptr)
    {
        delete[]elements[i];
        elements[i]=nullptr;
        elementCount[i]=0;
    }
    }

}  

// Description: Returns the total number of elements currently stored in the data collection MyADT.  
unsigned int MyADT::getElementCount() const{
    unsigned int totalElements=0;
    for (unsigned int i = 0; i< MAX_ALPHA; i++)
    {
        totalElements+=elementCount[i];
    }
    return totalElements;

}
   




// Description: Inserts an element in the data collection MyADT.
//              Returns "true" when the insertion is successfull, otherwise "false".
// Precondition: newElement must not already be in the data collection MyADT.  
// Postcondition: newElement inserted, MyADT's class invariants are still true
//                and the appropriate elementCount has been incremented.
// Time Efficiency: O(m)
bool MyADT::insert(const Profile& newElement) {
 
   char key = newElement.getSearchKey();
   int idx = key - 'a';

   //Check if the array  at elements[idx] is full:
   if (elementCount[idx]>=MAX_ELEMENTS)
   {
    return false;
   }

   //Check if the new element is already in the array:
   for(unsigned int i = 0; i<elementCount[idx]; i++)
   {
    if(elements[idx][i]==newElement)
    {
        return false;
    }
   }

   // Allocate memory for the new array
   if(elements[idx]==nullptr)
   {
    elements[idx]=new Profile[MAX_ELEMENTS];
   }

   // Determine where to insert the element
   unsigned int position;
   for(position = 0; position < elementCount[idx];position++)
   {
    if(elements[idx][position] > newElement)
    {
        break;
    }
   }
   //shift the elements to the right to insert at the correct position (ascending order)
   
   for (unsigned int k = elementCount[idx]; k > position; k--)
   {
    elements[idx][k] = elements[idx][k-1]; 

   }
   elements[idx][position]=newElement;
   elementCount[idx]++;

   
   return true;
   
}  

// Description: Removes an element from the data collection MyADT. 
//              Returns "true" when the removal is successfull, otherwise "false".    
// Precondition: The data collection MyADT is not empty.  
// Postcondition: toBeRemoved (if found) is removed, MyADT's class invariants are still true
//                and the appropriate elementCount is decremented.
// Time Efficiency: O(m)
bool MyADT::remove(const Profile& toBeRemoved) {

   char key = toBeRemoved.getSearchKey();
   int idx = key -'a';

   //Check if the data collection MyADT is empty : 
   if(getElementCount() == 0)
   {
    return false; 
   }
   //Check if the corresponding array to the key is empty:
   if(elementCount[idx] == 0)
   {
    return false; 
   }
   
   //Determine the position of the element to be removed:
   unsigned int position; 
   bool found = false; 
   for(position = 0; position < elementCount[idx];position++)
   {
    if(elements[idx][position] == toBeRemoved)
    {
        found = true;
        break;
    }
   }
   if(!found) // if element not found
   {
    return false;
   }
   for(unsigned int j = position; j < elementCount[idx]-1 ; j++)
   {
    elements[idx][j]=elements[idx][j+1];
   }
   elementCount[idx]--;
   return true;

   
}  

// Description: Removes all elements from the data collection MyADT. 
// Precondition: The data collection MyADT is not empty. 
// Postcondition: MyADT reverts back to its initialization state, i.e., 
//                the state it is in once it has been constructed (once
//                the default constructor has executed). 
// Time Efficiency: O(n)
void MyADT::removeAll() {
    
    //Check if the data collection MyADT is empty:
    if(getElementCount()==0)
    {
        return; //the collection is already empty, no need to remove anything
    }
    for(unsigned int i=0; i< MAX_ALPHA; i++)
    {
        if (elements[i]!=nullptr)
        {
            delete[]elements[i];
            elements[i]=nullptr;
            elementCount[i]=0;
        }
    }
    
    


}   

// Description: Searches for target element in the data collection MyADT. 
//              Returns a pointer to the element if found, otherwise, returns nullptr.
// Precondition: The data collection MyADT is not empty.
// Time Efficiency: O(log m)
Profile* MyADT::search(const Profile& target) {
    
    char key = target.getSearchKey();
    unsigned int idx = key - 'a'; 

    //check if the array where the element is suppose to be stored is empty: 
    if (elementCount[idx]==0)
    {
        return nullptr;
    }
    unsigned int left = 0; 
    unsigned int right = elementCount[idx]-1;
    while (left<=right)
    {
        unsigned int mid  = left + (right-left)/2;
        if(elements[idx][mid]==target)
        {
            return &elements[idx][mid]; //return a pointer to the element found
        }
        else 
        {
            if(elements[idx][mid] < target )
            {
                left = mid + 1; //search the right half
            }
            else 
            {
                right = mid - 1; //search the left half
            }
        }
    }
    return nullptr; //element not found

}  


// Description: Prints all elements stored in the data collection MyADT in ascending order of search key.
// ***For Testing Purposes - Not part of this class' public interface.***
// Time Efficiency: O(n)
void MyADT::print() {
  
    for (unsigned int i = 0; i<MAX_ALPHA; i++ )
    {
        if (elementCount[i]!=0)
        {
            for (unsigned int j = 0; j<elementCount[i]; j++)
            {
                cout << elements[i][j];
            }
        }
    }

} 

//  End of implementation file