#include "Appointment.h"

Appointment::Appointment(const string& appointmentID, const string& customerID, const vector <service>& seviceList, const string& requirement)
{
    this->appointmentID = appointmentID;
    this->customerID = customerID;
    this->seviceList = seviceList;
    this->requirement = requirement;
}



