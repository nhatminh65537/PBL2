#include<string>
#include<vector>
#include<iostream>
using namespace std;

enum service
{
    CatToc,
    NhuomToc,
    TayToc,
    UocToc,
    PhucHoiToc, 
    TaoKieu,
    GoiDau
};

class Appointment
{
    private:
        string appointmentID;
        string customerID;
        vector <service> seviceList;   
        string requirement;
    public:
        Appointment(const string& appointmentID, const string& customerID, const vector <service>& seviceList, const string& requirement);
};