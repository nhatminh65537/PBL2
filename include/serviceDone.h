#ifndef SERVICEDONE_H
#define SERVICEDONE_H
#include <string>
#include <iostream>

using namespace std;

class serviceDone
{
    public:
        serviceDone();
        ~serviceDone();
        friend ostream& operator<<(ostream& os,const serviceDone& obj);
        friend istream& operator>>(istream& is,serviceDone& obj);
    protected:

    private:
        string serviceDoneID;
        string customerID;
        string workerID;
        string serviceID;
        string feedback;
        bool isBooked;
        bool isPerfect;
        //Datetime time;
};

#endif // SERVICEDONE_H
