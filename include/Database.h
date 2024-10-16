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
        void Update(const string& ID,const T& newObj);
        void Append(const T& content);
        int Search(const string& searchID);
        void Show();
        int Count();
    private:
        // 2 functions ReadAll and Save shouldn't be allowed to call outside of the class.
        // as we are gonna to call them once. When create the list and delete the list.
        vector<T> ReadAll();
        void Save();
        string path;
        vector<T>_list;
};

#endif // DATABASE_H
