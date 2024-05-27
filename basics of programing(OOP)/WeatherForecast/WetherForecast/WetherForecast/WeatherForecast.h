#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class WeatherForecast {
private:
    string day_of_week;
    unsigned short day_of_month;
    string month;
    short daily_temperature;
    unsigned short amount_of_precipitation;

public:
    WeatherForecast();
    WeatherForecast(string week_day, unsigned short month_day, string mon, short temperature, unsigned short precipitation);
    WeatherForecast(const WeatherForecast& WF);

    void readFrom(istream& in);
    void writeTo(ostream& out) const;

    string getDayOfWeek() const;
    string getMonth() const;
    short getTemperature() const;
    unsigned short getPrecipitation() const;

    void setTemperature(short temperature);
    void setPrecipitation(unsigned short precipitation);

    bool operator<(const WeatherForecast& WF) const;
};

istream& operator>>(istream& in, WeatherForecast& WF);
ostream& operator<<(ostream& out, const WeatherForecast& WF);
void readForecastsFromFile(const std::string& filename, std::vector<WeatherForecast>& container);