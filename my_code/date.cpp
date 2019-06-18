//
//  date.cpp
//  
//
//  Created by Ellie Haber on 6/7/19.
//
#include <iostream>
#include "date.h"

using namespace std;

Date::Date(int d, int m, int y) :
day(d), month(m), year(y) {
}

ostream& operator<<(ostream& os, const Date& date){
    os <<"month: " << date.month << ", day: "<< date.day << ", year: " << date.year;
    return os;
}
