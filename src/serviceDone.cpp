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

serviceDone::~serviceDone()
{
    //dtor
}

void serviceDone::setID(const string& id){
    this->serviceDoneID = id;
}

string serviceDone::getID() const{
    return this->serviceDoneID;
}

ostream& operator<<(ostream& os, const serviceDone& obj){
    os << obj.serviceDoneID << " " << obj.customerID << " " << obj.workerID
        << " " << obj.serviceID << " " << obj.feedback << " " << obj.isBooked << " " << obj.isPerfect;
    return os;
}
istream& operator>>(istream& is,serviceDone& obj){
    is >> obj.serviceDoneID >> obj.customerID >> obj.workerID
        >> obj.serviceID >> obj.feedback >> obj.isBooked >> obj.isPerfect;
    return is;
}
