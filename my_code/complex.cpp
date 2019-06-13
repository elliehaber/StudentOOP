#include <iostream>
#include <istream>
#include <iomanip>
#include "complex.h"

using namespace std;

bool operator== (const Complex& c1, const Complex& c2) {
    double real1 = c1.get_real();
    double imag1 = c1.get_imag();
    double real2 = c2.get_real();
    double imag2 = c2.get_imag();
    if ((real1 -real2) <= .001 && (imag1 -imag2) <= .001){
        return true;
    }
    else {
        return false;
    }
}

bool operator!= (const Complex& c1, const Complex& c2){
    double real1 = c1.get_real();
    double imag1 = c1.get_imag();
    double real2 = c2.get_real();
    double imag2 = c2.get_imag();
    if (real1 != real2  && imag1 != imag2){
        return true;
    }
    else {
        return false;
    }
}

ostream& operator<< (ostream& os, const Complex& c) {
    os << c.real << " " << c.imag;
    return os;
    /*
     * Outputting a `Complex` instance, while illustrating some of the
     * capabilities of I/O streams: `setprecision` gives us a fixed
     * number of decimal places, while `showpos` turns on the plus
     * sign for positive numbers.
     * */
}
istream& operator>> (istream& is, Complex& c) {
    is >> c.real >> c.imag;
    return is;
    
}
Complex::Complex(double real, double imag) :
real(real), imag(imag) {}

/*
 * Read a `Complex` number from an input stream.
 * */



Complex::operator bool() const {
    if (real != 0 || imag != 0) {
        return true;
    }
    else {
        return false;
    }
    
}

Complex Complex::operator-=(const Complex& c) {
    real -= c.real;
    imag -= c.imag;
    return *this;
    
}

Complex& Complex::operator++() {
    ++real;
    return *this;
}

Complex Complex::operator++(int dummy) {
    Complex temp = *this;
    real++;
    return temp;
}

Complex operator+(const Complex& c1, const Complex& c2) {
    double c1_real = c1.get_real();
    double c2_real = c2.get_real();
    
    double c1_imag = c1.get_imag();
    double c2_imag = c2.get_imag();
    
    c1_real += c2_real;
    c1_imag += c2_imag;
    return Complex(c1_real, c1_imag);
}

Complex operator-(const Complex& c1, const Complex& c2) {
    double c1_real = c1.get_real();
    double c2_real = c2.get_real();
    
    double c1_imag = c1.get_imag();
    double c2_imag = c2.get_imag();
    
    c1_real -= c2_real;
    c1_imag -= c2_imag;
    return Complex(c1_real, c1_imag);
}

Complex Complex::operator*(const int i) {
    real *= i;
    imag *= i;
    return *this;
}

double Complex::get_real() const {
    return real;
}

double Complex::get_imag() const {
    return imag;
}

Complex& Complex::operator--(){
    --real;
    return *this;
}

Complex Complex::operator--(int dummy) {
    Complex temp = *this;
    real--;
    return temp;
}







