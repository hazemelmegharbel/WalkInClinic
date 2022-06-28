/*
 * walkIn.cpp
 *
 *
 *
 * Author:shahriar kabir nooh 301353204, hazem hisham taha el megharbel 301355345
 * Date:13th Jan 2019
 */
#include <iostream>
#include "Patient.hpp"
#include "List.hpp"
using namespace std;

bool isFoundLetter(const string& t)
{
    for(int i=0;i<t.length();i++)
    {
        if((t[i]>=65&&t[i]<=90)||(t[i]>=97&&t[i]<=122))
            return true;
    }
    return false;
}
bool isFoundDigit(const string& t)
{
    for(int i=0;i<t.length();i++)
    {
        if(t[i]>=48&&t[i]<=57)
            return true;
    }
    return false;
}
bool allDigit(const string& t)
{
    for(int i=0;i<t.length();i++)
    {
        if(!(t[i]>=48&&t[i]<=57))
            return false;
    }
    return true;
}
bool allLetters(const string& t)
{
    for(int i=0;i<t.length();i++)
    {
        if(!((t[i]>=65&&t[i]<=90)||(t[i]>=97&&t[i]<=122)))
            return false;
    }
    return true;
}
bool isPhone(const string& p)
{
    if(p.length() != 12)
        return false;
    
    int count = 0;
    for(int i = 0; i < p.length(); i++)
    {
        if(p[i] == 45)
            count++;
    }
    if(count != 2)
        return false;
    
    return true;
}
bool isEmail(const string& e)
{
    int size = e.length();
    for(int i = 0; i < size; i++)
        if(e[i] >= 65 && e[i] <= 90)
            return false;
    
    int count = 0;
    int count2=0;
    for(int i = 0; i < size; i++)
    {
        if(e[i] == 64)
            count++;
    }
    for(int i = 0; i < size; i++)
    {
        if(e[i] == 46)
            count2++;
    }
    if(count == 1)
        return true;
    else
        return false;
}
void print(const List& members)
{
    cout << endl << endl;
    cout << "---------------------" << endl;
    cout << "CURRENT PATIENT LIST:" << endl;
    if (members.getElementCount() == 0)
        cout << "No patients inserted into the list." << endl;
    else
        cout << members;
    cout << "---------------------" << endl;
    cout << endl << endl;
}


int main()
{
    char input;
    List members;
    cout<<"WELCOME TO THE WALK-IN CLINIC!"<<endl<<endl;
    do
    {
        cout<<"What would you like to do today?"<<endl<<endl;
        cout<<"To see your current Patient lists, enter 'p'"<<endl<<endl;
        cout<<"To add a new Patient, enter 'e'"<<endl<<endl;
        cout<<"To search for a Patient, enter 's'"<<endl<<endl;
        cout<<"To remove a Patient, enter 'r'"<<endl<<endl;
        cout<<"To modify any given field of a Patient, enter 'm'"<<endl<<endl;
        cout<<"To remove all Patients in your List, enter 'R'"<<endl<<endl;
        cout<<"To exit the program, enter 'x'"<<endl<<endl;
        cout<<"Your input: ";
        cin>>input;
        cout<<endl;
        
        if(input=='p')
        {
            print(members);
        }
        else if(input=='e')
        {
            if(members.getElementCount()>=members.getMAX_ELEMENTS())
                cout<<"Your List is currently full. Please remove a few Patients to add more."<<endl;
            else
            {
                string CareCard;
                cout<<"Please enter a 10-digit CareCard number for this patient"<<endl;
                cin >> CareCard;
                cout<<endl;
                while(CareCard.length() != 10)
                {
                    cout<<"Wrong input format. Please enter a valid 10-digit CareCard number for this patient"<<endl;
                    cin >> CareCard;
                    cout<<endl;
                }
                while(!(allDigit(CareCard)))
                {
                    cout<<"Wrong input format. Please enter a valid 10-digit CareCard number for this patient"<<endl;
                    cin >> CareCard;
                    cout<<endl;
                }
                Patient b(CareCard);
                while(members.search(b)!=nullptr)
                {
                    cout<<"Patient with the given CareCard already exists. Please enter a valid 10-digit CareCard"<<endl;
                    cin>>CareCard;
                    Patient temp(CareCard);
                    b=temp;
                    cout<<endl;
                }
                char ans;
                cout<<"Do you wish to enter the name now or later on? Enter 1 for yes or 0 for no"<<endl;
                cin>>ans;
                cout<<endl;
                while(ans<48||ans>49)
                {
                    cout<<"Incorrect answer. Please answer with 1 for yes or 0 for no"<<endl;
                    cin>>ans;
                    cout<<endl;
                }
                if(ans==49)
                {
                    string fname;
                    string lname;
                    cout<<"Enter the patient's first name: "<<endl;
                    cin>>fname;
                    cout<<endl;
                    while(!(allLetters(fname)))
                    {
                        cout<<"Incorrect format. Please enter a first name that consists of letters"<<endl;
                        cin>>fname;
                        cout<<endl;
                    }
                    cout<<"Enter the patient's last name (DO NOT include spaces): "<<endl;
                    cin>>lname;
                    cout<<endl;
                    while(!(allLetters(lname)))
                    {
                        cout<<"Incorrect format. Please enter a last name that consists of letters"<<endl;
                        cin>>lname;
                        cout<<endl;
                    }
                    b.setName(fname+" "+lname);
                }
                
                cout<<"Do you wish to enter the phone number now or later on? Enter 1 for yes or 0 for no"<<endl;
                cin>>ans;
                cout<<endl;
                
                while(ans<48||ans>49)
                {
                    cout<<"Incorrect answer. Please answer with 1 for yes or 0 for no"<<endl;
                    cin>>ans;
                    cout<<endl;
                }
                
                if(ans==49)
                {
                    string phone;
                    cout<<"Enter the Patients phone number (format: XXX-XXX-XXXX, hyphens included)"<<endl;
                    cin>>phone;
                    cout<<endl;
                    while(!(isPhone(phone)))
                    {
                        cout<<"Incorrect format. Please enter a valid phone number (format: XXX-XXX-XXXX, hyphens included)"<<endl;
                        cin>>phone;
                        cout<<endl;
                    }
                    
                    b.setPhone(phone);
                }
                
                cout<<"Do you wish to enter the email address now or later on? Enter 1 for yes or 0 for no"<<endl;
                cin>>ans;
                cout<<endl;
                
                while(ans<48||ans>49)
                {
                    cout<<"Incorrect answer. Please answer with 1 for yes or 0 for no"<<endl;
                    cin>>ans;
                    cout<<endl;
                }
                
                if(ans==49)
                {
                    string email;
                    cout<<"Enter the Patients email address"<<endl;
                    cin>>email;
                    cout<<endl;
                    while(!(isEmail(email)))
                    {
                        cout<<"Incorrect format. Please enter a valid email address"<<endl;
                        cin>>email;
                        cout<<endl;
                    }
                    
                    b.setEmail(email);
                }
                cout<<"Do you wish to enter the address now or later on? Enter 1 for yes or 0 for no"<<endl;
                cin>>ans;
                cout<<endl;
                while(ans<48||ans>49)
                {
                    cout<<"Incorrect answer. Please answer with 1 for yes or 0 for no"<<endl;
                    cin>>ans;
                }
                if(ans==49)
                {
                    string stnbr;
                    string stname1;
                    string stname2;
                    string city;
                    
                    cout<<"Enter the street number"<<endl;
                    cin>>stnbr;
                    cout<<endl;
                    while(!(allDigit(stnbr)))
                    {
                        cout<<"Incorrect format. Enter a valid street number"<<endl;
                        cin>>stnbr;
                        cout<<endl;
                    }
                    cout<<"Enter the street name (Just the name of the street)"<<endl;
                    cin>>stname1;
                    cout<<endl;
                    while(!(allLetters(stname1)))
                    {
                        cout<<"Incorrect format. Enter a valid street name"<<endl;
                        cin>>stname1;
                        cout<<endl;
                    }
                    cout<<"Enter the street name (st,dr,ave,way,etc...)"<<endl;
                    cin>>stname2;
                    cout<<endl;
                    while(!(allLetters(stname2)))
                    {
                        cout<<"Incorrect format. Enter a valid street name"<<endl;
                        cin>>stname2;
                        cout<<endl;
                    }
                    cout<<"Enter a city"<<endl;
                    cin>>city;
                    cout<<endl;
                    while(!(allLetters(city)))
                    {
                        cout<<"Incorrect format. Enter a valid city"<<endl;
                        cin>>city;
                        cout<<endl;
                    }
                    b.setAddress(stnbr+" "+stname1+" "+stname2+" "+city);
                }
                if(members.insert(b))
                    cout<<"Patient successfully added!"<<endl;
            }
        }
        else if(input=='r')
        {
            if(members.getElementCount()==0)
                cout<<"Your List is empty. Please add some Patients before removing."<<endl;
            else
            {
                string cc;
                cout<<"Please enter the 10-digit CareCard number for this patient"<<endl;
                cin >> cc;
                cout<<endl;
                while(cc.length() != 10)
                {
                    cout<<"Wrong input format. Please enter a valid 10-digit CareCard number for this patient"<<endl;
                    cin >> cc;
                    cout<<endl;
                }
                while(!(allDigit(cc)))
                {
                    cout<<"Wrong input format. Please enter a valid 10-digit CareCard number for this patient"<<endl;
                    cin >> cc;
                    cout<<endl;
                }
                Patient temp(cc);
                Patient* u=members.search(temp);
                while(u==nullptr)
                {
                    cout<<"That Patient doest exist. Enter the CareCard number again"<<endl;
                    cin>>cc;
                    cout<<endl;
                    Patient temp2(cc);
                    u=members.search(temp2);
                }
                Patient temp3(cc);
                if(members.remove(temp3))
                    cout<<"Patient successfully removed"<<endl;
            }
        }
        else if(input=='s')
        {
            string carecard;
            cout<<"Please enter the 10-digit CareCard number for this patient"<<endl;
            cin >> carecard;
            cout<<endl;
            while(carecard.length() != 10)
            {
                cout<<"Wrong input format. Please enter a valid 10-digit CareCard number for this patient"<<endl;
                cin >> carecard;
                cout<<endl;
            }
            while(!(allDigit(carecard)))
            {
                cout<<"Wrong input format. Please enter a valid 10-digit CareCard number for this patient"<<endl;
                cin >> carecard;
                cout<<endl;
            }
            Patient temp(carecard);
            Patient* u=members.search(temp);
            while(u==nullptr)
            {
                cout<<"That Patient doest exist. Enter the CareCard number again"<<endl;
                cin>>carecard;
                Patient temp2(carecard);
                u=members.search(temp2);
            }
            cout<<"Here's the patients information: "<<*u;
        }
        else if (input == 'm') //MODIFY
        {
            if(members.getElementCount()==0)
                cout<<"List is empty. Please add some Patients to modify first."<<endl;
            else
            {
                cout << "Which one of the following would you like to modify?" << endl;
                print(members);
                string cc;
                cout << "To modify a patient detail, a CareCard number is required." << endl;
                cout << "Please enter a valid CareCard number: ";
                cin >> cc;
                while (cc.length() != 10)
                {
                    cout << "Wrong input format. Please enter a valid 10-digit CareCard number for this patient: " << endl;
                    cin >> cc;
                }
                while (!(allDigit(cc)))
                {
                    cout << "Wrong input format. Please enter a valid 10-digit CareCard number for this patient: " << endl;
                    cin >> cc;
                }
                
                Patient temp(cc);
                Patient* tempPointer = members.search(temp);
                while (tempPointer == nullptr)
                {
                    cout << "That Patient does not exist. Please enter the CareCard number again: " ;
                    cin >> cc;
                    Patient temp(cc);
                    tempPointer = members.search(temp);
                }
                //MODIFY MENU
                cout << "Patient found. Opening MODIFY MENU: " << endl;
                cout << endl;
                char input2;
                do
                {
                    cout << "To modify name, enter 'n'" << endl;
                    cout << "To modify address, enter 'a'" << endl;
                    cout << "To modify phone number, enter 'p'" << endl;
                    cout << "To modify email, enter 'e'" << endl;
                    cout << "To exit Modify Menu, enter 'o'" << endl;
                    cout << "Your input: ";
                    cin >> input2;
                    cout << endl;
                    //NAME
                    if (input2 == 'n')
                    {
                        string fname;
                        string lname;
                        cout << "Enter the patient's first name: ";
                        cin >> fname;
                        while (!(allLetters(fname)))
                        {
                            cout << "Incorrect format. Please enter a first name that consists of letters: ";
                            cin >> fname;
                        }
                        cout << "Enter the patient's last name: ";
                        cin >> lname;
                        while (!(allLetters(lname)))
                        {
                            cout << "Incorrect format. Please enter a last name that consists of letters: ";
                            cin >> lname;
                        }
                        tempPointer->setName(fname + " " + lname);
                        
                        cout << endl;
                        cout << "Name modification complete." << endl;
                        cout << endl;
                    }
                    //ADDRESS
                    else if (input2 == 'a')
                    {
                        string stnbr;
                        string stname1;
                        string stname2;
                        string city;
                        
                        cout << "Enter the street number: ";
                        cin >> stnbr;
                        while (!(allDigit(stnbr)))
                        {
                            cout << "Incorrect format. Enter a valid street number: ";
                            cin >> stnbr;
                        }
                        cout << "Enter the street name (first part): ";
                        cin >> stname1;
                        while (!(allLetters(stname1)))
                        {
                            cout << "Incorrect format. Enter a valid street name (first part): ";
                            cin >> stname1;
                        }
                        cout << "Enter the street name (second part): ";
                        cin >> stname2;
                        while (!(allLetters(stname2)))
                        {
                            cout << "Incorrect format. Enter a valid street name (second part): ";
                            cin >> stname2;
                        }
                        cout << "Enter a city";
                        cin >> city;
                        while (!(allLetters(city)))
                        {
                            cout << "Incorrect format. Enter a valid city: ";
                            cin >> city;
                        }
                        tempPointer->setAddress(stnbr + " " + stname1 + " " + stname2 + " " + city);
                        
                        cout << endl;
                        cout << "Address modification complete." << endl;
                        cout << endl;
                    }
                    //PHONE
                    else if (input2 == 'p')
                    {
                        string phone;
                        cout << "Enter the Patients phone number (format: XXX-XXX-XXXX, please include hyphens): ";
                        cin >> phone;
                        while (!(isPhone(phone)))
                        {
                            cout << "Incorrect format. Please enter a valid phone number (format: XXX-XXX-XXXX, please include hyphens): ";
                            cin >> phone;
                        }
                        tempPointer->setPhone(phone);
                        
                        cout << endl;
                        cout << "Phone number modification complete." << endl;
                        cout << endl;
                    }
                    //EMAIL
                    else if (input2 == 'e')
                    {
                        string email;
                        cout << "Enter the Patients email address: ";
                        cin >> email;
                        while (!(isEmail(email)))
                        {
                            cout << "Incorrect format. Please enter a valid email address: ";
                            cin >> email;
                        }
                        tempPointer->setEmail(email);
                        
                        cout << endl;
                        cout << "Email address modification complete." << endl;
                        cout << endl;
                    }
                    
                } while (input2 != 'o');
                cout << "Modification successfull! Print to find out!" << endl;
                cout << endl;
            }
        }
        else if(input=='R')
        {
            if(members.getElementCount()==0)
                cout<<"Your List is empty. Please make sure to add Patients before removing them all."<<endl;
            else
            {
                cout<<"Removing "<<members.getElementCount()<<" Patients..."<<endl;
                members.removeAll();
                cout<<"Remove successful"<<endl;
            }
        }
        if(input!='m'&&input!='r'&&input!='x'&&input!='e'&&input!='p'&&input!='s'&&input!='R')
            cout<<"Incorrect input, please choose one of the following options:"<<endl;
        else
        {
            cout<<endl<<endl;
            cout<<"Do you want to perform another operation to your list? Answer with a 0 for no or 1 for yes"<<endl;
            char t;
            cin>>t;
            cout<<endl;
            while(t<48||t>49)
            {
                cout<<"Incorrect answer. Please answer with 1 for yes or 0 for no"<<endl;
                cin>>t;
                cout<<endl;
            }
            if(t==48)
                input='x';
        }
    }while (input!='x');
    cout<<endl<<endl<<"Thanks for coming!!"<<endl;
    return 0;
}
