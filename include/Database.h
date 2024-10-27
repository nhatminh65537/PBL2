#ifndef DATABASE_H
#define DATABASE_H
#include <string>
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
        void Delete(const string&);
        int Search(const string&);
        void Show() const;
        int Count();
    private:
        // 2 functions ReadAll and Save shouldn't be allowed to call outside of the class.
        // as we are gonna to call them once. When create the list and delete the list.
        void ReadAll(map<string,T>& ); // Return reference to _list, to reduce time complexity
        void Save();
        const string path;
        map<string,T>_list;
        map<string,function<void(T&,const string&)>>attributeMap; // Function map used for update function
        void initAttributeMap();
};

#endif // DATABASE_H
