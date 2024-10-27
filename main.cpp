#include <iostream>
#include <string>
#include <vector>
#include "serviceDone.h"
#include "Database.h"
#include "Member.h"

using namespace std;
const string SERVICE_DONE_FILE = "database/service-done.txt";
// Các hàm thống kê sẽ được nhét vào class Database. Để tiện lấy thông tin
// Không dùng vector để lưu trữ cho database nữa. Dùng map, vì map tiện hơn và chạy nhanh hơn
int main()
{
    Database<serviceDone> myList(SERVICE_DONE_FILE);
    myList.Show();
    return 0;
}
