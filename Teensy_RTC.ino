/*
Electronics Studio
@file Teensy_RTC.ino
@date  09-02-2025
@url https:https: https://github.com/electronicsstudio
@url YouTube: https://www.youtube.com/@ElectronicsStudio-v7o/featured
*/


#include <TimeLib.h>

time_t RTCTime;
void setup() {
  Serial.begin(115200);
  while (!Serial && millis() < 4000 );
  Serial.println("\n" __FILE__ " " __DATE__ " " __TIME__);
  setSyncProvider(getTeensy3Time);
}

void loop() {
  Serial.print("Time ");
  Serial.print(hour());
  Serial.print(":");
  Serial.print(minute());
  Serial.print(":");
  Serial.print(second());
  Serial.print(" ");
  Serial.print(month());
  Serial.print("/");
  Serial.print(day());
  Serial.print("/");
  Serial.print(year());
  Serial.println();
  delay(1000);
}

time_t getTeensy3Time() {
  return Teensy3Clock.get();
}





