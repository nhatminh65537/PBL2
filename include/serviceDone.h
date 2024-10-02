#ifndef SERVICEDONE_H
#define SERVICEDONE_H
#include <string>
#include <iostream>
#include "Identifiable.h"

using namespace std;

class serviceDone : public Identifiable
{
    public:
        serviceDone();
        ~serviceDone();
        friend ostream& operator<<(ostream& os,const serviceDone& obj);
        friend istream& operator>>(istream& is,serviceDone& obj);
        string getID() const override;
        void setID(const string&) override;
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
