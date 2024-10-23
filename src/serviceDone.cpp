#include "serviceDone.h"

using namespace std;

serviceDone::serviceDone()
{
    this->serviceDoneID = "null";
    this->customerID = "null";
    this->workerID = "null";
    this->serviceID = "null";
    this->feedback = "\"null\"";
    this->isBooked = 0;
}

serviceDone::serviceDone(const string& serviceDoneID, const string& customerID,const string& workerID,
                         const string& serviceID,const string& feedback,const bool& isBooked){
    this->serviceDoneID = serviceDoneID;
    this->customerID = customerID;
    this->workerID = workerID;
    this->serviceID = serviceID;
    this->feedback = feedback;
    this->isBooked = isBooked;
}

serviceDone::~serviceDone()
{
    //dtor
}

void serviceDone::SetID(const string& id){
    this->serviceDoneID = id;
}

const string& serviceDone::GetID() const{
    return this->serviceDoneID;
}

const string& serviceDone::GetCustomerID() const{
    return this->customerID;
}
void serviceDone::SetCustomerID(const string& customerID){
    this->customerID = customerID;
}

const string& serviceDone::GetWorkerID() const{
    return this->workerID;
}
void serviceDone::SetWorkerID(const string& workerID){
    this->workerID = workerID;
}
const string& serviceDone::GetServiceID() const{
    return this->serviceID;
}
void serviceDone::SetServiceID(const string& serviceID){
    this->serviceID = serviceID;
}

void serviceDone::SetFeedBack(const string& feedback){
    this->feedback = feedback;
}

const string& serviceDone::GetFeedBack() const{
    return this->feedback;
}


ostream& operator<<(ostream& os, const serviceDone& obj){
    os << obj.serviceDoneID << " " << obj.customerID << " " << obj.workerID
        << " " << obj.serviceID << " "<< obj.feedback
        << " " << obj.isBooked;
    return os;
}
istream& operator>>(istream& is,serviceDone& obj){
    is >> obj.serviceDoneID >> obj.customerID >> obj.workerID
        >> obj.serviceID;
    char quote;
    is>>quote;
    getline(is,obj.feedback,'"');
    obj.feedback = "\"" + obj.feedback + "\"";
    is >> obj.isBooked;
    return is;
}

bool operator<(const serviceDone& a,const serviceDone& b){
    string s = a.serviceDoneID;
    string r = b.serviceDoneID;
    if (s.size() == r.size())   return s<r;
    return s.size()<r.size();
}
