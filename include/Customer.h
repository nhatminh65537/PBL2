#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Member.h"
#include "Appointment.h"
#include <vector>

class Customer: public Member
{
    public:
        Customer();
        ~Customer();


    protected:

    private:
        vector<Appointment> appointmentList;
};

#endif // CUSTOMER_H
