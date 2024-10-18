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
        serviceDone(const string& serviceDoneID, const string& customerID,const string& workerID,
                    const string& serviceID,const string& feedback,const bool& isBooked,
                    const bool& isPerfect);
        ~serviceDone();
        friend ostream& operator<<(ostream& os,const serviceDone& obj);
        friend istream& operator>>(istream& is,serviceDone& obj);
        friend bool operator<(const serviceDone& a,const serviceDone& b);
        string GetID() const override;
        void SetID(const string&) override;
        string GetCustomerID() const;
        void SetCustomerID(const string&);
        string GetWorkerID() const;
        void SetWorkerID(const string&);
        string GetServiceID() const;
        void SetServiceID(const string&);
        string GetFeedBack() const;
        void SetFeedBack(const string&);
        void Show();
    protected:

    private:
        string serviceDoneID;
        string customerID;
        string workerID;
        string serviceID;
        string feedback;
        // Try using alternative for these.
        bool isBooked;
        bool isPerfect;
        //Datetime time;
};

#endif // SERVICEDONE_H
