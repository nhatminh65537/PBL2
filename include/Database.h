#ifndef DATABASE_H
#define DATABASE_H
#include <string>
#include <vector>
#include <map>
#include <functional>
using namespace std;

template<typename T>
class Database
{
    public:
        Database();
        Database(const string& path);
        ~Database();
        const T& operator[](const string&);
        void Update(const string&,const T&);
        void Update(const string&,const string&,const string&);
        void Append(const T&);
        int Search(const string&);
        void Show();
        int Count();
    private:
        // 2 functions ReadAll and Save shouldn't be allowed to call outside of the class.
        // as we are gonna to call them once. When create the list and delete the list.
        vector<T> ReadAll();
        void Save();
        const string path;
        vector<T>_list;
        map<string,function<void(T&,const string&)>>attributeMap;
        void initAttributeMap();
};

#endif // DATABASE_H
