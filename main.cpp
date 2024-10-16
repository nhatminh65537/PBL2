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
    Database<serviceDone> myList(SERVICE_DONE_FILE);
    myList.Show();
    cout << myList.Count() << '\n';
    cout << myList.Search("1") << '\n';
    return 0;
}
