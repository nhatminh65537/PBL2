#include "Member.h"

Member::Member(const string& firstName, const string& lastName, bool gender , int age, const string& phoneNumber, const string& username, const string& password)
    : firstName(firstName), lastName(lastName), gender(gender), age(age), phoneNumber(phoneNumber), username(username), password(password)
{ 
}
Member::Member()
{
    //ctor
}

Member::~Member()
{
    //dtor
}

