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
                    const string& serviceID,const string& feedback,const bool& isBooked);
        ~serviceDone();
        const string& GetID() const override;
        void SetID(const string&) override;
        const string& GetCustomerID() const;
        void SetCustomerID(const string&);
        const string& GetWorkerID() const;
        void SetWorkerID(const string&);
        const string& GetServiceID() const;
        void SetServiceID(const string&);
        const string& GetFeedBack() const;
        void SetFeedBack(const string&);

        friend ostream& operator<<(ostream& os,const serviceDone& obj);
        friend istream& operator>>(istream& is,serviceDone& obj);
        friend bool operator<(const serviceDone& a,const serviceDone& b);
    protected:

    private:
        string serviceDoneID;
        string customerID;
        string workerID;
        string serviceID;
        string feedback;
        bool isBooked;
        //Datetime time;
};

#endif // SERVICEDONE_H
