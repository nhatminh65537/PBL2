#ifndef MEMBER_H
#define MEMBER_H
#include <string>
#include "Identifiable.h"

using namespace std;

class Member : public Identifiable {
    public:
        Member();
        ~Member();

        string getfirstName();
        void setfirstName(const string& val);
        string getlastName();
        void setlastName(const string& val);
        bool getgender();
        void setgender(const bool& val);
        int getage();
        void setage(const int& val);
        string getphoneNumber();
        void setphoneNumber(const string& val);
        string getusername();
        void setusername(const string& val);
        string getpassword();
        void setpassword(const string& val);

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
