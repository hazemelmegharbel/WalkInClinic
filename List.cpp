//
//  List.cpp
//  Patient
//
//  Created by Hisham Elmegharbel on 1/13/19.
//  Copyright © 2019 Hisham Elmegharbel. All rights reserved.
//

#include "List.hpp"
#include "Patient.hpp"
#include "string"
// Default constructor
List::List()
{
    this->elementCount = 0;
    this->capacity = 5;
}

// Description: Returns the total element count currently stored in List.
int  List::getElementCount() const
{
    return this->elementCount;
}

// Description: Insert an element.
// Precondition: newElement must not already be in data collection.
// Postcondition: newElement inserted and elementCount has been incremented.
bool List::insert(const Patient& newElement)
{
    bool flag = false;
    if(this->getElementCount() > MAX_ELEMENTS)
        return flag;
    else
    {
        if(this->search(newElement)!=nullptr)
            return flag;
        else if(this->getElementCount()==0)
        {
            this->elements[0] = newElement;
            this->elementCount++;
            this->capacity--;
            flag = true;
            return flag;
        }
        else
        {
            for(int i = 0; i < MAX_ELEMENTS; i++)
            {
                if(this->elements[i].getCareCard() > newElement.getCareCard())
                {
                    for(int j = this->MAX_ELEMENTS-1; j > i; j--)
                    {
                        this->elements[j] = this->elements[j-1];
                    }
                    this->elements[i] = newElement;
                    flag = true;
                    this->elementCount++;
                    this->capacity--;
                    return flag;
                }
            }
            if(flag==false)
            {
                for(int i=0;i<MAX_ELEMENTS;i++)
                {
                    if(this->elements[i].getCareCard()=="0000000000")
                    {
                        elements[i]=newElement;
                        this->elementCount++;
                        this->capacity--;
                        flag=true;
                        break;
                    }
                }
            }
        }
        return flag;
    }
}
// Description: Remove an element.
// Postcondition: toBeRemoved is removed and elementCount has been decremented.
bool List::remove( const Patient& toBeRemoved )
{
    bool flag = false;
    
    if(this->getElementCount() == 0)
        return flag;
    else
    {
        int index;
        Patient test;
        for(int i = 0; i < MAX_ELEMENTS; i++)
        {
            if(this->elements[i] == toBeRemoved)
            {
                index = i;
                for(int j = index + 1; j < this->elementCount; j++)
                    this->elements[j-1] = this->elements[j];
                this->elements[elementCount -1] = test;
                this->elementCount--;
                this->capacity++;
                flag = true;
                return flag;
            }
            else
                continue;
        }
        return flag;
    }
}

// Description: Remove all elements.
void List::removeAll()
{
    Patient temp;
    for(int i=0;i<MAX_ELEMENTS;i++)
    {
        this->elements[i]=temp;
    }
    this->elementCount=0;
    this->capacity=MAX_ELEMENTS;
}

// Description: Search for target element.
//              Returns a pointer to the element if found,
//              otherwise, returns NULL.
Patient* List::search(const Patient& target)
{
    for(int i=0;i<MAX_ELEMENTS;i++)
    {
        if(this->elements[i]==target)
            return &(this->elements[i]);
    }
    return nullptr;
}
int List::getMAX_ELEMENTS()
{
    return List::MAX_ELEMENTS;
}
ostream& operator<<(ostream& os, const List& p)
{
    for(int i=0;i<p.getElementCount();i++)
    {
        os<<p.elements[i];
    }
    return os;
}

