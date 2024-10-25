#include "Database.h"
#include "serviceDone.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

template class Database<serviceDone>;

template<typename T>
Database<T>::Database(const string& path) : path(path) {
    ReadAll(this->_list);
    initAttributeMap();
}

template<typename T>
Database<T>::~Database() {
    this->Save();
}


template<typename T>
void Database<T>::ReadAll(map<string,T>& _list){
    ifstream inputFile(this->path.c_str(), ios::in);
    if (!inputFile.is_open()) {
        cerr << "File " << this->path << " not found!";
        exit(1);
    }
    T tempObject;
    while (inputFile >> tempObject) {
        _list[tempObject.GetID()] = tempObject;
    }
    inputFile.close();
}

template<typename T>
void Database<T>::Save() {
    ofstream outputFile(this->path.c_str());
    if (!outputFile.is_open()) {
        cerr << "File " << this->path << " not found!";
        exit(1);
    }
    for (const auto& it : this->_list){
        outputFile << it.second << '\n';
    }
    outputFile.close();
}

template<typename T>
void Database<T>::Update(const string& ID,const T& newObj){
    if (newObj.GetID() != ID){
        cerr << ID << " does not exists in database\n";
        exit(1);
    }
    this->_list[ID] = newObj;
}

template<typename T>
void Database<T>::Update(const string& ID,const string& attributeName, const string& newVal){
    if (this->_list.find(ID) == this->_list.end()){
        cerr << ID << " does not exists in database\n";
        exit(1);
    }
    this->attributeMap[attributeName](this->_list[ID],newVal);
}

template<typename T>
void Database<T>::Append(const T& obj) {
    // If object is already in map
    if (this->_list.find(obj.GetID()) != this->_list.end()){
        cerr << obj.GetID() << " already exists\n";
        exit(1);
    }
    this->_list[obj.GetID()] = obj;
}

template<typename T>
void Database<T>::Delete(const string& id){
    // If object does not exist in map
    if (this->_list.find(id) == this->_list.end()){
        cerr << id << " does not exist\n";
        exit(1);
    }
    this->_list.erase(id);
}

template<typename T>
void Database<T>::Show() const {
    for (const auto& it : this->_list){
        cout << it.second << '\n';
    }
}

template<typename T>
int Database<T>::Count(){
    return this->_list.size();
}

template<>
void Database<serviceDone>::initAttributeMap(){
    // lambda function
    attributeMap["serviceDoneID"] = [](serviceDone& obj,const string& newVal){
        obj.SetID(newVal);
    };
    attributeMap["customerID"] = [](serviceDone& obj,const string& newVal){
        obj.SetCustomerID(newVal);
    };
    attributeMap["workerID"] = [](serviceDone& obj,const string& newVal){
        obj.SetWorkerID(newVal);
    };
    attributeMap["serviceID"] = [](serviceDone& obj,const string& newVal){
        obj.SetServiceID(newVal);
    };
    attributeMap["feedback"] = [](serviceDone& obj,const string& newVal){
        obj.SetFeedBack('"' + newVal + '"'); // Thêm 2 dấu " ở đầu và cuối để phân biệt feedback với các phần khác
    };
}

