//
//  date.hpp
//  
//
//  Created by Ellie Haber on 6/7/19.
//

#ifndef DATE_H
#define DATE_H

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
