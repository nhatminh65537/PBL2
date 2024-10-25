#include<iostream>
#include<string>
#include "Member.h"
using namespace std;

Member::Member()
{
    ID = "";
    firstName = "";
    lastName = "";
    phoneNumber = "";
    userName = "";
}

Member::~Member()
{
    //
}

int checkName(string name)
{
    for(int i = 0; i < name.length(); i++)
    {
        if(name[i] == ' ') continue;
        if(name[i] < 'A' || name[i] > 'z' || (name[i] > 'Z' && name[i] < 'a'))
        {
            cout << "Invalid Name" << endl;
            return 0;
        }
    }
    return 1;
}

Member& Member::setFirstName(string firstName)
{
    if(!checkName(firstName)) return *this;   //return ???
    this->firstName = firstName;
    return *this;
}

string Member::getFirstName()
{
    return firstName;
}

Member& Member::setLastName(string lastName)
{
    if(!checkName(lastName)) return *this;
    this->lastName = lastName;
    return *this;
}

string Member::getLastName()
{
    return lastName;
}

Member& Member::setPhoneNumber(string phoneNumber)
{
    for(int i = 0; i < phoneNumber.length(); i++)
    {
        if(phoneNumber[i] < '0' || phoneNumber[i] > '9' || phoneNumber.length() != 10)
        {
            cout << "Invalid Phone Number" << endl;
            return *this;
        }
    }
    this->phoneNumber = phoneNumber;
    return *this;
}

string Member::getPhoneNumber()
{
    return phoneNumber;
}

Member& Member::setUserName(string userName)
{
    this->userName = userName;
    return *this;
}

string Member::getUserName()
{
    return userName;
}

int checkAge(string ID)
{
    int year = atoi(ID.substr(3, 2).c_str());
    if(ID[3] == '0' || ID[3] == '1') year += 1900;
    else year += 2000;

    if(year > 2024 || year < 1900)
        return 0;
    else return year;
}

int Member::getAge()
{
    return checkAge(this->ID);
}

int Member::getGender()
{
    if((this->ID[3] - '0') % 2 == 0) return 1;       // 1 = male
    else return 0;
}

Member& Member::setID(string ID)
{
    for(int i = 0; i < ID.length(); i++)
    {
        if(ID[i] < '0' || ID[i] > '9' || i > 8 )
        {
            cout << "Invalid ID" << endl;
            return *this;
        }
    }

    if(ID[0] > '2' || ID[3] > '3' || checkAge(ID) == 0)   
    {
        cout << "Invalid ID" << endl;     // check year from get_age function
        return *this;
    }

    this->ID = ID;
    return *this;
}

string Member::getID()
{
    return ID;
}