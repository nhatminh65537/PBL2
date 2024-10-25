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
    // Đa năng hóa toán tử [] để lấy thông tin kiểu như ri
    // mp["123"].name;
    serviceDone a;
    myList.Show();
    cout << myList["1"].GetFeedBack();
    return 0;
}
