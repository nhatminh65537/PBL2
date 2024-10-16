#include "serviceDone.h"

using namespace std;

serviceDone::serviceDone()
{
    this->serviceDoneID = "null";
    this->customerID = "null";
    this->workerID = "null";
    this->serviceID = "null";
    this->feedback = "null";
    this->isBooked = 0;
    this->isPerfect = 0;
}

serviceDone::serviceDone(const string& serviceDoneID, const string& customerID,const string& workerID,
                         const string& serviceID,const string& feedback,const bool& isBooked,
                         const bool& isPerfect){
    this->serviceDoneID = serviceDoneID;
    this->customerID = customerID;
    this->workerID = workerID;
    this->serviceID = serviceID;
    this->feedback = feedback;
    this->isBooked = isBooked;
    this->isPerfect = isBooked;
}

serviceDone::~serviceDone()
{
    //dtor
}

void serviceDone::SetID(const string& id){
    this->serviceDoneID = id;
}

string serviceDone::GetID() const{
    return this->serviceDoneID;
}

ostream& operator<<(ostream& os, const serviceDone& obj){
    os << obj.serviceDoneID << " " << obj.customerID << " " << obj.workerID
        << " " << obj.serviceID << " " << obj.feedback
        << " " << obj.isBooked << " " << obj.isPerfect;
    return os;
}
istream& operator>>(istream& is,serviceDone& obj){
    is >> obj.serviceDoneID >> obj.customerID >> obj.workerID
        >> obj.serviceID >> obj.feedback >> obj.isBooked >> obj.isPerfect;
    return is;
}

bool operator<(const serviceDone& a,const serviceDone& b){
    return a.serviceDoneID < b.serviceDoneID;
}
