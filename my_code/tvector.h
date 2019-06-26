//
//  tvector.h
//  
//
//  Created by Ellie Haber on 6/26/19.
//

#ifndef tvector_h
#define tvector_h

using namespace std;

const int DEF_CAPACITY = 10;
const int CAPACITY_MULT = 2;


template <typename T>
class MyVec {
public:
    
    MyVec() : sz(0) {
        capacity = DEF_CAPACITY;
        data = new T[DEF_CAPACITY];
    }
    
    MyVec(int sz, int val) : sz(sz) {
        capacity = sz;
        data = new T[sz];
        for(int i = 0; i < sz; i++){
            data[i] = val;
        }
    }
    
    // copy control:
    MyVec(const MyVec<T>& v2) {
        copy(v2);
    }
    ~MyVec(){
        delete [] data;
    }
    MyVec& operator=(const MyVec<T>& v2){
        if (this != &v2) {
            delete [] data;
            copy(v2);
        }
        return *this;
    }
    
    void push_back(int val) {
        sz++;
        if (sz > capacity) {
            cout << "Increasing capacity\n";
            int* old_data = data;
            data = new T[capacity * CAPACITY_MULT];
            for (int i = 0; i < sz; i++) {
                data[i] = old_data[i];
            }
            capacity *= CAPACITY_MULT;
            delete [] old_data;
        }
        data[sz - 1] = val;
    }
    int size() const { return sz; }
    
    T& operator[](int i) const {
        return data[i];
    }
    T& operator[](int i)  {
        return data[i];
    }
    //Iterator begin() const;
    //Iterator end() const;
    
private:
    void copy(const MyVec<T>& v2);
    T* data;
    int sz;
    int capacity;
};

template <typename T>
void print_vector(const MyVec<T>& v){
    for (int i = 0; i < v.sz; i++){
        cout << v[i] << " ";
        cout << endl;
    }
};

template <typename T>
bool operator==(MyVec<T>& v1, MyVec<T>& v2) {
    if (v1.size() != v2.size()){
        return false;
    }
    for(int i = 0; i < v1.size(); i++){
        if(v1[i] != v2[i]){
            return false;
        }
    }
    return true;
    
};


#endif /* tvector_h */
