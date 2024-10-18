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
    Database<serviceDone> myList(SERVICE_DONE_FILE);
    myList.Show();
    //myList.Update("4","customerID","27");
    //myList.Show();
    return 0;
}
