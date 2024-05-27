#include "WeatherForecast.h"

WeatherForecast::WeatherForecast()
    : day_of_week(""), day_of_month(0), month(""), daily_temperature(0), amount_of_precipitation(0) {
}

WeatherForecast::WeatherForecast(string week_day, unsigned short month_day, string mon, short temperature, unsigned short precipitation)
    : day_of_week(week_day), day_of_month(month_day), month(mon), daily_temperature(temperature), amount_of_precipitation(precipitation) {
}

WeatherForecast::WeatherForecast(const WeatherForecast& WF)
    : day_of_week(WF.day_of_week), day_of_month(WF.day_of_month), month(WF.month), daily_temperature(WF.daily_temperature), amount_of_precipitation(WF.amount_of_precipitation) {
}

void WeatherForecast::readFrom(istream& in) {
    in >> day_of_week >> day_of_month >> month >> daily_temperature >> amount_of_precipitation;
}

void WeatherForecast::writeTo(ostream& out) const {
    out << "Day of week: " << day_of_week<< ". Day of month: "<< day_of_month << ". Month: " << month << ". Temparature today: " << daily_temperature << ". Precipitation today: " << amount_of_precipitation;
}

string WeatherForecast::getDayOfWeek() const {
    return day_of_week;
}

string WeatherForecast::getMonth() const {
    return month;
}

short WeatherForecast::getTemperature() const {
    return daily_temperature;
}

unsigned short WeatherForecast::getPrecipitation() const {
    return amount_of_precipitation;
}

void WeatherForecast::setTemperature(short temperature) {
    daily_temperature = temperature;
}

void WeatherForecast::setPrecipitation(unsigned short precipitation) {
    amount_of_precipitation = precipitation;
}

bool WeatherForecast::operator<(const WeatherForecast& WF) const {
    if (month == WF.month) {
        return day_of_month < WF.day_of_month;
    }
    // Assuming month is a string representing the month name
    // You can improve this by using a mapping from month name to number
    return month < WF.month;
}

istream& operator>>(istream& in, WeatherForecast& WF) {
    WF.readFrom(in);
    return in;
}

ostream& operator<<(ostream& out, const WeatherForecast& WF) {
    WF.writeTo(out);
    return out;
}
void readForecastsFromFile(const std::string& filename, std::vector<WeatherForecast>& container) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    WeatherForecast wf;
    while (file >> wf) {
        container.push_back(wf);
    }
}