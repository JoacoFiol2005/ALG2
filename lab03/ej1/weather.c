/*
  @file weather.c
  @brief Implements weather mesuarement structure and methods
*/
#include <stdlib.h>
#include "weather.h"

Weather weather_from_file(FILE* file){
    Weather weather;
    int scan = fscanf (file, "%d %d %d %u %u %u",
      &weather._average_temp,
      &weather._max_temp,
      &weather._min_temp,
      &weather._pressure,
      &weather._moisture,
      &weather._rainfall);

      if (scan != 6){
      fprintf(stderr, "Error: línea con formato inválido.\n");
      exit(EXIT_FAILURE);  // NOSE QUE ES PERO EL LO USA
      }
  return weather;
}


void weather_to_file(FILE* file, Weather weather){
    fprintf(file, "%d %d %d %u %u %u", weather._average_temp,
            weather._max_temp, weather._min_temp, weather._pressure, weather._moisture, weather._rainfall);
}
