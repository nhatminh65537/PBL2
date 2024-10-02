#include <iostream>
#include <string>
#include <vector>
#include "serviceDone.h"
#include "Database.h"
#include "Member.h"

using namespace std;
const string SERVICE_DONE_FILE = "database/service-done.txt";


int main()
{
    serviceDone a;
    a.setID("1232");
    cout << a.getID();
    return 0;
}
