#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <vector>
#include <string>
#include "Appointment.h"
#include "Member.h"
#include "DateTime.h"
#include "Database.h"

class Customer: public Member
{
    public:
        Customer(const string& firstName, const string& lastName, bool gender, int age, const string& phoneNumber, const string& username, const string& password);
        Customer();
        ~Customer();
        void bookAppointment(Database<Appointment>& db, const vector <service>& seviceList, const string& requirement, const DateTime& appointmentTime);
        void cancelAppointment(Database<Appointment>& db, const string& appointmentID);
        vector<Appointment> viewAppointment();
        
        void setRequirement(Database<Appointment>& db, const string& appointmentID, const string& requirement);
        void giveFeedback(Database<Appointment>& db, const string& appointmentID, const string& feedback);
        

    protected:

    private:
        vector<Appointment>_list; // What does this use for?

};

#endif // CUSTOMER_H
