//
//  date.hpp
//  
//
//  Created by Ellie Haber on 6/7/19.
//

#ifndef date_h
#define date_h

#include <iostream>


class Date {
    friend std::ostream& operator<<(std::ostream& os, const Date& date);
public:
    Date(int d, int m, int y);
private:
    int day;
    int month;
    int year;
};

#endif /* date_hpp */
