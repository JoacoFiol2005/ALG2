#include "weather.h"

int year_reinfall (WeatherTable table , unsigned int year){
    int res = 0;
    if (year < YEARS){
        int y = year;  
        for (int month = 0; month < MONTHS; month++) {
            for (int day = 0; day < DAYS; day++) {
                res += table [y] [month] [day]._rainfall;
            }
        } 
    } else {
        printf ( "Error en la eleccion del año");
    }
        return res; 
    }

