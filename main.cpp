#include <iostream>
#include <string>
#include <vector>
#include "serviceDone.h"
#include "Database.h"

using namespace std;
const string SERVICE_DONE_FILE = "database/service-done.txt";

int main()
{
    serviceDone a;
    Database<serviceDone> serviceDoneDB(SERVICE_DONE_FILE);
    serviceDoneDB.append(a);
    vector<serviceDone>_list = serviceDoneDB.readAll();
    cout << _list.size();
    for (auto x : _list){
        cout << x << '\n';
    }
    return 0;
}
