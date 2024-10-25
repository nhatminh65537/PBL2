#include <string>
using namespace std;
class Member
{
    private:
        string ID;
        string firstName;
        string lastName;
        string phoneNumber;
        string userName;
    public:
        Member();
        ~Member();
        Member& setID(string ID);
        string getID();
        Member& setFirstName(string firstName);
        string getFirstName();
        Member& setLastName(string lastName);
        string getLastName();
        Member& setPhoneNumber(string phoneNumber);
        string getPhoneNumber();
        Member& setUserName(string userName);
        string getUserName();
        int getAge();
        int getGender();
        friend int checkName(string name);
        friend int checkAge(string ID);
};