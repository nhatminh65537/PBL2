#ifndef MEMBER_H
#define MEMBER_H
#include <string>
#include "Identifiable.h"

using namespace std;

class Member : public Identifiable {
    public:
        Member();
        virtual ~Member();

        string GetFirstName();
        void SetFirstName(const string& val);
        string GetLastName();
        void SetLastName(const string& val);
        bool GetGender();
        void SetGender(const bool& val);
        int GetAge();
        void SetAge(const int& val);
        string GetPhoneNumber();
        void SetPhoneNumber(const string& val);
        string GetUserName();
        void SetUserName(const string& val);
        string GetPassword();
        void SetPassword(const string& val);

    protected:

    private:
        string firstName;
        string lastName;
        bool gender;
        int age;
        string phoneNumber;
        string username;
        string password;
};

#endif // MEMBER_H
