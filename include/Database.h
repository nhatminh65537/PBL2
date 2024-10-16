#ifndef DATABASE_H
#define DATABASE_H
#include <string>
#include <vector>

using namespace std;

template<typename T>
class Database
{
    public:
        Database();
        Database(const string& path);
        ~Database();
        void Update(const T& _old,const T& _new);
        void Append(const T& content);
        int Search(const string& searchID);
        void Show();
        int Count();
    private:
        vector<T> ReadAll(const string& path);
        vector<T>_list;
};

#endif // DATABASE_H
