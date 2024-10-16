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
    this->path = path;
    this->_list = ReadAll();
}

template<typename T>
Database<T>::~Database() {
    this->Save();
}

template<typename T>
vector<T> Database<T>::ReadAll() {
    ifstream inputFile(this->path.c_str(), ios::in);
    if (!inputFile.is_open()) {
        cerr << "File " << this->path << " not found!";
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

template<typename T>
void Database<T>::Save() {
    ofstream outputFile(this->path.c_str());
    if (!outputFile.is_open()) {
        cerr << "File " << this->path << " not found!";
        exit(1);
    }
    sort(this->_list.begin(),this->_list.end());
    for (const T& obj : this->_list){
        outputFile << obj << '\n';
    }
    outputFile.close();
}

template<typename T>
void Database<T>::Update(const string& ID,const T& newObj){
    int idx = this->Search(ID);
    if (idx == -1) return;
    this->_list[idx] = newObj;
}

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
