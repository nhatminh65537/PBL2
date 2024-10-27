#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <vector>
#include <string>
#include "Appointment.h"
#include "Member.h"

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
        vector<Appointment>_list;

};

#endif // CUSTOMER_H
