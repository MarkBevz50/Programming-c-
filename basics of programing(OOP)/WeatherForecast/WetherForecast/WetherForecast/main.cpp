#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>
#include <memory>
#include <set>
#include "WeatherForecast.h"


int main() {
    std::vector<WeatherForecast> forecasts;

    // Read data from file
    readForecastsFromFile("weather.txt", forecasts);

    // Sort forecasts by date
    std::sort(forecasts.begin(), forecasts.end());

    // Print sorted forecasts
    std::cout << "Sorted Weather Forecasts by Date:\n";
    for (const auto& forecast : forecasts) {
        std::cout << forecast << std::endl;
    }

    // Calculate total precipitation and number of dry days for a given month
    std::string target_month = "May";
    unsigned total_precipitation = 0;
    unsigned dry_days = 0;

    for (const auto& forecast : forecasts) {
        if (forecast.getMonth() == target_month) {
            total_precipitation += forecast.getPrecipitation();
            if (forecast.getPrecipitation() == 0) {
                dry_days++;
            }
        }
    }

    std::cout << "\nTotal precipitation in " << target_month << ": " << total_precipitation << " mm" << std::endl;
    std::cout << "Number of dry days in " << target_month << ": " << dry_days << std::endl;

    // Create a new container for forecasts without precipitation
    std::vector<WeatherForecast> no_precipitation_forecasts;
    std::copy_if(forecasts.begin(), forecasts.end(), std::back_inserter(no_precipitation_forecasts),
        [](const WeatherForecast& wf) { return wf.getPrecipitation() == 0; });

    // Sort by daily temperature
    std::sort(no_precipitation_forecasts.begin(), no_precipitation_forecasts.end(),
        [](const WeatherForecast& a, const WeatherForecast& b) { return a.getTemperature() < b.getTemperature(); });

    // Print the warmest and coldest days without precipitation
    if (!no_precipitation_forecasts.empty()) {
        std::cout << "\nColdest day without precipitation:\n" << no_precipitation_forecasts.front() << std::endl;
        std::cout << "Warmest day without precipitation:\n" << no_precipitation_forecasts.back() << std::endl;
    }

    // Create a container of unique daily temperatures for a given day of the week
    std::string target_day_of_week = "Monday";
    std::set<short> monday_temperatures;

    for (const auto& forecast : forecasts) {
        if (forecast.getDayOfWeek() == target_day_of_week) {
            monday_temperatures.insert(forecast.getTemperature());
        }
    }

    // Print unique temperatures for the target day of the week
    std::cout << "\nUnique temperatures for " << target_day_of_week << ":\n";
    for (short temp : monday_temperatures) {
        std::cout << temp << ' ';
    }
    std::cout << std::endl;

    return 0;
}
