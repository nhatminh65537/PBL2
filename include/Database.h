#ifndef DATABASE_H
#define DATABASE_H
#include <string>
#include <vector>

using namespace std;

template<typename T>
class Database
{
    public:
        Database(const string& path);
        ~Database();
        void setPath(const string& path);
        string getPath();
        vector<T> readAll();
        void update(const T& _old,
                    const T& _new);
        void append(const T& content);
    private:
        string path;
};

#endif // DATABASE_H
