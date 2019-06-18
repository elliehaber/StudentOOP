#include <iostream>
#include "vector.h"

using namespace std;

void print_vector(const MyVec& v) {
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
}


MyVec::MyVec() {
    sz = 0;
    capacity = 0;
    data = new int[sz];
}

MyVec::MyVec(const MyVec& v2) {
    sz = v2.size();
    capacity = sz;
    
    data = new int[sz];
    
    for(int i = 0; i < sz; i++){
        data[i] = v2[i];
    }
}

MyVec::~MyVec() {
    delete [] data;
}

MyVec& MyVec::operator=(const MyVec& v2) {
    if(this != &v2) {
        delete [] data;
        sz = v2.sz;
        capacity = v2.capacity;
        
        data = new int[sz];
        for(int i= 0; i < v2.size(); i++) {
            data[i] = v2.data[i];
        }
    }
    return *this;

}


/*
 * == is true when every element of the vectors are the same in
 * the same order. (Thus they must be the same size.)
 * */
bool operator==(MyVec& v1, MyVec& v2) {
    if (v1.size() != v2.size()){
        return false;
    }
    for(int i = 0; i < v1.size(); i++){
        if(v1[i] != v2[i]){
            return false;
        }
    }
    return true;
}

/*
 * Puts an element at the back of a vector.n
 * */
void MyVec::push_back(int val) {
    if (capacity == 0) {
        ++capacity;
        data = new int[capacity];
    }
    if(sz == capacity){
        int* old_data = data;
        data = new int[2*capacity];
        capacity *= 2;
        
        for(int i = 0; i < capacity; i++){
            data[i] = old_data[i];
        }
        delete [] old_data;
    }
    data[sz] = val;
    ++sz;
}

/*
 * this [] is for reading items from the MyVec:
 * It returns the i-th element.
 * */
int MyVec::operator[](int i) const {
    return data[i];
}

/*
 * this [] allows write access to items in the MyVec:
 * It returns a reference to the i-th element.
 * */
int& MyVec::operator[](int i) {
    return data[i];
}
