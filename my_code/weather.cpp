#include <iostream>
#include <string>
#include <vector>
#include "date.h"
#include "weather.h"

using namespace std;

const double C_TO_F = 9/5;


Image::Image(int w, int h, std::string flnm)
: width(w), height(h)
{
    filename = flnm;
    image_buf = new char[image_sz()];
    
}

// copy constructor:
Image::Image(const Image& img2) {
    copy_fields(img2);

    for (int i = 0; i < img2.image_sz(); i++) {
        image_buf[i] = img2.image_buf[i];
    }
    
}

Image::~Image() {
    if (image_buf != nullptr) {
      delete image_buf;
    }
}

Image& Image::operator=(const Image& img2) {
    if (&img2 != this) {
        delete image_buf;
        
        copy_fields(img2);
        for (int i = 0; i < img2.image_sz(); i++) {
            image_buf[i] = img2.image_buf[i];
        }
    }
    return *this;
}

int Image::image_sz() const{
    return width * height;
}


void Image::copy_fields(const Image& img2) {
    width = img2.width;
    height = img2.height;
    filename = img2.filename;
    image_buf = new char[image_sz()];
}


/*
 * Setting `display() = 0` here makes this an abstract
 * class that can't be implemented.
 * */
void Image::display() {
    cout << "Displaying image " << endl;
}

void Png::display() {
    cout << "Displaying png " << endl;
}

void Jpeg::display(){
    cout << "Displaying jpeg "  << endl;
}

void Gif::display(){
    cout << "Displaying gif " << endl;
}

double WReading::get_tempF() {
    return (temperature * C_TO_F) + 32;
    
}

void WReading::display_image(){
    if(!image){
        cout << "null" << endl;
    }
    else{
        image->display();

    }
}
/*
 * output for GPS coordinates
 * */
ostream& operator<<(ostream& os, const GPS& gps){
    os << "latitude: " << gps.latitude << "; longitude: " << gps.longitude;
    return os;
}


WReading::WReading(Date dt, double temp, double hum, double ws, Image* img = nullptr) :
date(dt), temperature(temp), humidity(hum), windspeed(ws), image(img)
{
}
ostream& operator<<(ostream& os, const WReading& wreading){
    os <<"Date: " << wreading.date << ", temperature: "<< wreading.temperature << ", humidity: "
    << wreading.humidity << ", windspeed: " << wreading.windspeed << " image: " << wreading.image;
    return os;
}
/*
 * A constructor for weather class.
 * */
Weather::Weather(string nm, GPS loc) :
    station_nm(nm), my_loc(loc) {
    }
string Weather::get_name() const {
    return station_nm;
}

void Weather::display_images() {
    for(WReading wr: wreadings){
        wr.display_image();
    }
}

int Weather::get_rating() const{
    return rating;
    
}



double WReading::get_heat_index(){
    return -42.379 + 2.04901523*temperature + 10.14333127*humidity -
    .22475541*temperature*humidity - .00683783*temperature*temperature - .05481717*humidity*humidity + .00122874*temperature*temperature*humidity + .00085282*temperature*humidity*humidity - .00000199*temperature*temperature*humidity*humidity;
    
}

double WReading::get_wind_chill(){
    double temp = get_tempF();
    return 35.74 + (.6215 * temp) - (35.75 * windspeed) + (.4275 * temp * windspeed);
    
}

        
void Weather::set_rating(int new_rating){
    int rating = new_rating;
}

void Weather::add_reading(WReading wr) {
    wreadings.push_back(wr);
}


ostream& operator<<(ostream& os, const Weather& w){
    os << w.get_name() <<  ": rating " << w.get_rating() << " " << w.my_loc << endl;

    for (WReading reading: w.wreadings) {
        os << reading << endl;
    }
    return os;
}




