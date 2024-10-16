#include "Database.h"
#include "serviceDone.h"
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <algorithm>

using namespace std;

template class Database<serviceDone>;

template<typename T>
Database<T>::Database(const string& path) {
    this->_list = ReadAll(path);
}

template<typename T>
Database<T>::~Database() {

}

template<typename T>
vector<T> Database<T>::ReadAll(const string& path) {
    ifstream inputFile(path.c_str(), ios::in);
    if (!inputFile.is_open()) {
        cerr << "File " << path << " not found!";
        exit(1);
    }
    vector<T>_list;
    T tempObject;
    while (inputFile >> tempObject) {
        _list.push_back(tempObject);
    }
    inputFile.close();
    sort(_list.begin(),_list.end());
    return _list;
}

// append new data to the end of list.
template<typename T>
void Database<T>::Append(const T& content) {
    this->_list.push_back(content);
}

template<typename T>
int Database<T>::Search(const string& searchID){
    int lo = 0,hi = this->Count();
    while (lo <= hi){
        int mid = (lo+hi)/2;
        if (this->_list[mid].GetID() == searchID) return mid;
        else if (this->_list[mid].GetID() < searchID) lo = mid+1;
        else hi = mid-1;
    }
    return -1;
}
template<typename T>
void Database<T>::Show(){
    for (int i = 0;i < this->_list.size();++i){
        cout << this->_list[i] << '\n';
    }
}

template<typename T>
int Database<T>::Count(){
    return this->_list.size();
}
