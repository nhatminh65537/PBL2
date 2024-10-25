#include<string>
#include "DateTime.h"   
using namespace std;
class ServiceDone
{
    private:
        string customerID;
        string workerID;
        enum ServiceType
        {
            CatToc,
            NhuomToc,
            TayToc,
            UocToc,
            PhucHoiToc, 
            TaoKieu,
            GoiDau
        };
        string feedback;
        bool isBooked;
        bool isPerfect;
        DateTime time;
};