/*
 * Patient.cpp
 *
 * Class Description: Models a walk-in clinic patient.
 * Class Invariant: Each patient has a unique care card number.
 *                  This care card number must have 10 digits.
 *                  This care card number cannot be modified.
 *
 * Author:shahriar kabir nooh 301353204, hazem hisham taha el megharbel 301355345
 * Date:13th Jan 2019
 */

// You can add #include statements if you wish.
#include <iostream>
#include <string>
#include "Patient.hpp"

// Default Constructor
// Description: Create a patient with a care card number of "0000000000".
// Postcondition: All data members set to "To be entered",
//                except the care card number which is set to "0000000000".
Patient::Patient() {
    
    this->setName("To be entered");
    this->setEmail("To be entered");
    this->setPhone("To be entered");
    this->setAddress("To be entered");
    this->careCard="0000000000";
    
}

// Parameterized Constructor
// Description: Create a patient with the given care card number.
// Postcondition: If aCareCard does not have 10 digits, then care card is set to "0000000000".
//                All other data members set to "To be entered".
Patient::Patient(string aCareCard) {
    
    this->setName("To be entered");
    this->setEmail("To be entered");
    this->setPhone("To be entered");
    this->setAddress("To be entered");
    if(aCareCard.length()!=10)
        this->careCard="0000000000";
    else
        this->careCard=aCareCard;
    
}

//Assignment Operator
//Description: Assigns patient onto another
//Postcondition: *this Patient is replaced with the assigned Patient in the parameter
Patient& Patient::operator = (const Patient& aPatient)
{
    this->setName(aPatient.getName());
    this->setEmail(aPatient.getEmail());
    this->setPhone(aPatient.getPhone());
    this->setAddress(aPatient.getAddress());
    this->careCard = aPatient.getCareCard();
    return *this;
}

string Patient::getName()const
{
    return this->Name;
}
string Patient::getEmail()const
{
    return this->email;
}
string Patient::getPhone()const
{
    return this->phoneNumber;
}
string Patient::getAddress()const
{
    return this->address;
}
string Patient::getCareCard()const
{
    return this->careCard;
}
void Patient::setAddress(const string anAddress)
{
    this->address=anAddress;
}
void Patient::setPhone(const string aPhone)
{
    this->phoneNumber=aPhone;
}
void Patient:: setEmail(const string anEmail)
{
    this->email=anEmail;
}
void Patient::setName(const string aName)
{
    this->Name=aName;
}
// Overloaded Operators
// Description: Comparison operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if both Patient objects have the same care card number.
bool Patient::operator == (const Patient & rhs) {
    
    // Compare both Patient objects
    if (this->careCard == rhs.getCareCard() )
        return true;
    else
        return false;
    
} // end of operator ==

// Description: Greater than operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if the care card number of "this" Patient object is > the care card
//              number of "rhs" Patient object
bool Patient::operator > (const Patient & rhs) {
    
    // Compare both Patient objects
    if (this->careCard > rhs.getCareCard() )
        return true;
    else
        return false;
    
} // end of operator >


// Description: Prints the content of "this".
ostream & operator<<(ostream & os, const Patient & p)
{
    os<<p.getCareCard()<<" "<<"-"<<" "<<"Patient: "<<p.getName()<<", "<<p.getAddress()<<", "<<p.getPhone()<<", "<<p.getEmail()<<endl;
    return os;
} // end of operator<<

// end of Patient.cpp
