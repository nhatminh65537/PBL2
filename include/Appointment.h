#include <string>
#include <vector>
#include <iostream>
#include <DateTime.h>
using namespace std;

enum service
{
    CatToc    = 1,
    NhuomToc  = 2,
    TayToc    = 4,
    UocToc    = 8,
    PhucHoiToc=16, 
    TaoKieu   =32,
    GoiDau    =64
};

class Appointment
{
    private:
        string appointmentID;
        string customerID;
        vector<service> seviceList;   
        string requirement;
        DateTime appointmentTime;
    public:
        Appointment(const string& customerID, const vector <service>& seviceList, const string& requirement, const DateTime& appointmentTime);

        // setter and getter
        void setAppointmentID(const string& appointmentID) { this->appointmentID = appointmentID; }
        void setCustomerID(const string& customerID) { this->customerID = customerID; }
        void setSeviceList(const vector <service>& seviceList) { this->seviceList = seviceList; }
        void setRequirement(const string& requirement) { this->requirement = requirement; }
        void setAppointmentTime(const DateTime& appointmentTime) { this->appointmentTime = appointmentTime; }

        const string& getAppointmentID() const { return appointmentID; }
        const string& getCustomerID() const { return customerID; }
        const vector <service>& getSeviceList() const { return seviceList; }
        const string& getRequirement() const { return requirement; }
        const DateTime& getAppointmentTime() const { return appointmentTime; }
};