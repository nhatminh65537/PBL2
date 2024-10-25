#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <vector>
#include <string>
#include "Appointment.h"
#include "Member.h"

using namespace std;

class Customer : public Member {
    public:
        Customer();
        ~Customer();

    protected:

    private:
        vector<Appointment>_list;

};

#endif // CUSTOMER_H
