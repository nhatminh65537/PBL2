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
    serviceDone b("14","12","12","14","good",1,0);
    cout << myList.Count() << '\n';
    cout << myList.Search("1") << '\n';
    myList.Update("5",b);
    myList.Show();
    return 0;
}
