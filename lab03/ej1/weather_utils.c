#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "weather_utils.h"

int min_temp_min(WeatherTable table) {
    int result;
    result = table [0] [0] [0]._min_temp;
    for (unsigned int year = 0; year < YEARS; year++){
        for (unsigned int month = 0; month < MONTHS; month++){
            for (unsigned int days = 0; days < DAYS; days++){
                if (table[year] [month] [days]._min_temp < result){
                    result = table[year] [month] [days]._min_temp;
                }
            }
        }
    }
    return result;
}


void max_temp_max(WeatherTable table, int output[YEARS]) {
    for (unsigned int year = 0; year < YEARS; year++){
        int max_temp_year = table[year] [0] [0]._max_temp;
        for (month_t month = january; month <= december; month++){
            for (unsigned int day = 0; day < DAYS; day++){
                if (table [year] [month] [day]._max_temp > max_temp_year){
                    max_temp_year= table[year] [month] [day]._max_temp;
                }
                
            }
            
        }
        output[year] = max_temp_year;
    }
    
}

void month_max_rainfall(WeatherTable table, month_t output[YEARS]) {
    for (unsigned int year = 0; year < YEARS; year++){
        month_t month_max = january;
        unsigned int max_reinfall = 0;
        for (month_t month = january; month <= december; month++){
            unsigned int month_reinfall = 0;
            for (unsigned int day = 0; day < DAYS; day++){
                month_reinfall += table [year] [month] [day]._rainfall;
            }
            if (month_reinfall > max_reinfall){
                max_reinfall = month_reinfall;
                month_max = month;
            }
            
        }
        output [year] = month_max;
    }
    
}



