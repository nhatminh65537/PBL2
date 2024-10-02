#include "Database.h"
#include "serviceDone.h"
#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

template class Database<serviceDone>;


template<typename T>
Database<T>::Database(const string& path) {
    this->path = path;
}

template<typename T>
Database<T>::~Database() {
    cout << "Changes of database completed!\n";
}

template<typename T>
void Database<T>::setPath(const string& path) {
    this->path = path;
}

template<typename T>
string Database<T>::getPath() {
    return this->path;
}

template<typename T>
vector<T> Database<T>::readAll() {
    ifstream inputFile(this->path.c_str(), ios::in);
    if (!inputFile.is_open()) {
        cerr << "File not found!";
        exit(1);
    }
    vector<T>_list;
    T tempObject;
    while (inputFile >> tempObject) {
        _list.push_back(tempObject);
    }
    inputFile.close();
    return _list;
}

template<typename T>
void Database<T>::append(const T& content) {
    ofstream outputFile(this->path.c_str(), ios::app);
    if (!outputFile.is_open()) {
        cerr << "File not found!";
        exit(1);
    }
    outputFile << content << '\n';
    outputFile.close();
}
