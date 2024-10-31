#include "Customer.h"

Customer::Customer()
{
    //ctor
}

Customer::Customer(const string& firstName, const string& lastName, bool gender, int age, const string& phoneNumber, const string& username, const string& password)
    : Member(firstName, lastName, gender, age, phoneNumber, username, password)
{
}
Customer::~Customer()
{
    //dtor
}

void Customer::bookAppointment(Database<Appointment>& db, const vector <service>& seviceList, const string& requirement, const DateTime& appointmentTime){
    string appointmentID = to_string(db.Count() + 1);
    // Add leading 0 to appointmentID if it has less than 6 digits
    appointmentID = string(6 - appointmentID.length(), '0') + appointmentID;
    Appointment newAppointment(appointmentID, this->GetID(), seviceList, requirement, appointmentTime);
    db.Append(newAppointment);
    this->_list.push_back(newAppointment);
}

void Customer::cancelAppointment(Database<Appointment>& db, const string& appointmentID){
    db.Delete(appointmentID);
}

vector<Appointment> Customer::viewAppointment(){
    return this->_list;
}

void Customer::setRequirement(Database<Appointment>& db, const string& appointmentID, const string& requirement){
    
}

void Customer::giveFeedback(Database<Appointment>& db, const string& appointmentID, const string& feedback){
    
}
