#ifndef MEMBER_H
#define MEMBER_H

#include <string>

using namespace std;

class Member
{
    public:
        Member();
        ~Member();
        static int count;
        Member* setID(string id);
        Member* setFirstName(string firstName);

        string getID();
    protected:

    private:
        string id;
        string firstName;
        string lastName;
        bool gender;
        int age;
        string phoneNumber;
        string username;
        string password;
};

#endif // MEMBER_H
