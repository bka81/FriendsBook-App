/*
* MyADTTestDriver.cpp
*
* Description: Driver program for testing myADT class
* Author: Beyzanur Kuyuk
* Last modified on: 31 May, 2024
*/
#include <iostream>
#include "MyADT.h"     // Header file of MyADT file
#include "Profile.h"   // Header file of Profile class


using std::cout;
using std::cin;
using std::endl;


void MyADTTest();

int main(void)
{
    MyADTTest();

    return 0;
}

void MyADTTest()
{

    //Testing the deafult constructor: 
    cout<<endl;

    cout<<"Creating the MyADT data collection called 'adt_1'"<<endl;
    MyADT adt_1 = MyADT();
    
    cout<<"Creating the following profiles to use for test cases:"<<endl<<endl;

    cout<<"amedo, Ahmet Mushin, ahmed@gmail.com, August 2, 2023"<<endl;
    cout<<"abcreally, Xiao Wong, xw123@coldmail.com, March 2 2003"<<endl;
    cout<<"beyzak, beyznaur kuyuk, bnk@gmail.com, March 25, 2004"<<endl;
    cout<<"karahan, karahan kuyuk, karahan@gmail.com, April 2, 1999"<<endl;
    cout<<"zeynep, zeynep kuyuk, zeynep@gmail.com, December 4, 2007"<<endl;
    cout<<"caane, Cane Jale, Jale@gmail.com, September 23, 2000"<<endl;
    cout<<"selin53894, Selin Gulizar, selg@gmail.com, October 19, 2010"<<endl;
    cout<<"juleps, Kiraz Satar, satar33@gmail.com, May 3, 1995"<<endl<<endl;

    cout<<"Creating the following profiles whose usernames all start with 'b' in addition to profile 'beyzak'"<<endl<<endl;
    cout<<"boru, Bire Mesum, biree@gmail.com, August 14, 2015"<<endl;
    cout<<"besme, Besmel Olga, besga@gmail.com, May 2, 2000"<<endl;
    cout<<"betty54, Betty William, willia@gmail.com, March 1, 1999"<<endl;
    cout<<"boram45, Boray Tosun, borayy@gmail.com, June 4, 1995"<<endl;
    cout<<"batimm66, Bailey Smith, bayyss@gmail.com, July 26, 1990"<<endl;
    cout<<endl;


    //Create profile objects for test use:
    Profile profile1 = Profile ("amedo", "Ahmet Mushin", "ahmed@gmail.com", "August 2, 2023");
    Profile profile2 = Profile ("abcreally", "Xiao Wong", "xw123@coldmail.com", "March 2 2003");
    Profile profile3 = Profile ("beyzak", "beyznaur kuyuk", "bnk@gmail.com", "March 25, 2004");
    Profile profile4 = Profile ("karahan", "karahan kuyuk", "karahan@gmail.com", "April 2, 1999");
    Profile profile5 = Profile ("zeynep", "zeynep kuyuk", "zeynep@gmail.com", "December 4, 2007");
    Profile profile6 = Profile ("cane", "Cane Jale", "Jale@gmail.com", "September 23, 2000");
    Profile profile7 = Profile ("selin53894", "Selin Gulizar", "selg@gmail.com", "October 19, 2010");
    Profile profile8 = Profile ("juleps", "Kiraz Satar", "satar33@gmail.com", "May 3, 1995");
    
    Profile profile9 = Profile ("boru", "Bire Mesum", "biree@gmail.com", "August 14, 2015");
    Profile profile10 = Profile ("besme", "Besmel Olga", "besga@gmail.com", "May 2, 2000");
    Profile profile11 = Profile ("betty54", "Betty William", "willia@gmail.com", "March 1, 1999");
    Profile profile12 = Profile ("boram45", "Boray Tosun", "borayy@gmail.com", "June 4, 1995");
    Profile profile13 = Profile ("batimm66", "Bailey Smith", "bayyss@gmail.com", "July 26, 1990");
    
    cout<<endl;

    //Testing the insert method: 
    cout<<"Inserting some of the created profiles into the data collection adt_1"<<endl;
    adt_1.insert(profile1);
    adt_1.insert(profile2);
    adt_1.insert(profile3);
    adt_1.insert(profile4);
    adt_1.insert(profile5);
    adt_1.insert(profile6);
    adt_1.insert(profile7);
    adt_1.insert(profile8);

    cout<<endl;

    cout<<"Printing the data collection adt_1"<<endl<<endl;
    

    cout<<"Expected result (Inserted profiles should be printed in order): "<<endl<<endl;

    cout<<"abcreally, Xiao Wong, xw123@coldmail.com, born on March 2 2003"<<endl;
    cout<<"amedo, Ahmet Mushin, ahmed@gmail.com, born on August 2, 2023"<<endl;
    cout<<"beyzak, beyznaur kuyuk, bnk@gmail.com, born on March 25, 2004"<<endl;
    cout<<"cane, Cane Jale, Jale@gmail.com, born on September 23, 2000"<<endl;
    cout<<"juleps, Kiraz Satar, satar33@gmail.com, born on May 3, 1995"<<endl;
    cout<<"karahan, karahan kuyuk, karahan@gmail.com, born on April 2, 1999"<<endl;
    cout<<"selin53894, Selin Gulizar, selg@gmail.com, born on October 19, 2010"<<endl;
    cout<<"zeynep, zeynep kuyuk, zeynep@gmail.com, born on December 4, 2007"<<endl<<endl;

    cout<<"Actual result: "<<endl<<endl;
    adt_1.print();
    

    cout<<endl;

    //Testing the search method:
    cout<<"Testing the search method: "<<endl<<endl;
    cout<<"Searching for the profile with username: cane (expected result)"<<endl;
    
    Profile *profile2p = adt_1.search(profile6);
    cout<<"The search method is expected to return a pointer"<<endl<<endl;
    cout<<"Here is the pointer address to the profile found (actual result): "<<profile2p<<endl;
    cout<<"Here is the profile found (actual result): "<< *profile2p <<endl;
    

    //Testing the remove method:
    cout<<"Testing the remove method: "<<endl<<endl;
    cout<<"Removing the profile with username 'zeynep'"<<endl;
    cout<<"Expected result: "<<endl<<endl;
    
    cout<<"abcreally, Xiao Wong, xw123@coldmail.com, born on March 2 2003"<<endl;
    cout<<"amedo, Ahmet Mushin, ahmed@gmail.com, born on August 2, 2023"<<endl;
    cout<<"beyzak, beyznaur kuyuk, bnk@gmail.com, born on March 25, 2004"<<endl;
    cout<<"cane, Cane Jale, Jale@gmail.com, born on September 23, 2000"<<endl;
    cout<<"juleps, Kiraz Satar, satar33@gmail.com, born on May 3, 1995"<<endl;
    cout<<"karahan, karahan kuyuk, karahan@gmail.com, born on April 2, 1999"<<endl;
    cout<<"selin53894, Selin Gulizar, selg@gmail.com, born on October 19, 2010"<<endl<<endl;

    adt_1.remove(profile5);
    cout<<"The data collection MyADT after the removal of 'zeynep' (actual result): "<<endl<<endl;
    adt_1.print();
    
    cout<<endl;

    //Testing the getElementCount method: 
    unsigned int myElementCount = adt_1.getElementCount();

    cout<<"Testing the getElementCount method, after removing the last element, expected result: 7"<<endl;
    cout<<"Actual result: "<<myElementCount<<" elements stored. "<<endl<<endl;

    //Testing the copy constructor: 
    cout<<"Copying the contents of data collection adt_1 into the data collection adt_2: "<<endl<<endl;
    MyADT adt_2 = MyADT(adt_1);
    cout<<"Printing the contents of adt_2 to see if it matches with adt_1 above (expected result)"<<endl<<endl;

    adt_2.print();
    

    cout<<endl;


    //Testing the removeAll method: 

    cout<<"Remove everything from data collection adt_1 to test the removeAll method, expected result: nothing should be printed."<<endl;
    
    adt_1.removeAll();

    cout<<"adt_1 after removing everything (actual result): "<<endl;
    adt_1.print();
   

    cout<<endl;

    
    //Testing whether elementCount[i] are meeting the requirement of storing at most MAX_ELEMENTS
    cout<<"Inserting the profiles whose usernames all start with 'b' to the data collection adt_1: "<<endl;
    adt_1.insert(profile9);
    adt_1.insert(profile10);
    adt_1.insert(profile11);
    adt_1.insert(profile12);
    adt_1.insert(profile13);
    adt_1.insert(profile3); //username 'beyzak' should not be inserted into the data collection as it would
                            //make elementCount[1] exceed MAX_ELEMENTS
    cout<<endl;
    cout<<"Printing the data collection adt_1: "<<endl;
    cout<<"Expected result('beyzak' should not be printed): "<<endl<<endl;

    cout<<"batimm66, Bailey Smith, bayyss@gmail.com, born on July 26, 1990"<<endl;
    cout<<"besme, Besmel Olga, besga@gmail.com, born on May 2, 2000"<<endl;
    cout<<"betty54, Betty William, willia@gmail.com, born on March 1, 1999"<<endl;
    cout<<"boram45, Boray Tosun, borayy@gmail.com, born on June 4, 1995"<<endl;
    cout<<"boru, Bire Mesum, biree@gmail.com, born on August 14, 2015"<<endl<<endl;

    cout<<"Actual result: "<<endl<<endl;
    adt_1.print();
    cout<<endl;

    cout<<"Testing to see if the copy constructor has created a shallow copy or a deep copy: "<<endl;
    cout<<"printing the data collection adt_2: "<<endl<<endl;
    adt_2.print();
    cout<<endl;

    cout<<"If the copy constructor was successful with deep copying, then the result above should be: "<<endl;
    cout<<endl;
    cout<<"abcreally, Xiao Wong, xw123@coldmail.com, born on March 2 2003"<<endl;
    cout<<"amedo, Ahmet Mushin, ahmed@gmail.com, born on August 2, 2023"<<endl;
    cout<<"beyzak, beyznaur kuyuk, bnk@gmail.com, born on March 25, 2004"<<endl;
    cout<<"cane, Cane Jale, Jale@gmail.com, born on September 23, 2000"<<endl;
    cout<<"juleps, Kiraz Satar, satar33@gmail.com, born on May 3, 1995"<<endl;
    cout<<"karahan, karahan kuyuk, karahan@gmail.com, born on April 2, 1999"<<endl;
    cout<<"selin53894, Selin Gulizar, selg@gmail.com, born on October 19, 2010"<<endl<<endl;

    //Extra testing:

    cout<<"Removing the profiles with usernames 'juleps' and 'karahan' from the data collection adt_2:"<<endl;
    adt_2.remove(profile4);
    adt_2.remove(profile8);

    cout<<"Printing adt_2 after the removal: "<<endl<<endl;

    adt_2.print();
    cout<<endl;

    cout<<"The element count after the removal of the two usernames should be 5"<<endl;
    cout<<"Actual element count after removal: "<<adt_2.getElementCount()<<endl<<endl;

    //End of testing
    return;
}