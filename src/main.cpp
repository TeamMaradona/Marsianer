
#include "calibration.hpp"
#include "moisture.hpp"
#include <Arduino.h>

/**
 * @file main.cpp
 * @brief Hauptprogramm des Projekts.
 */

/**
 * @brief Initialisiert die serielle Kommunikation.
 */
void
setup()
{
  Serial.begin(9600); // open serial port, set the baud rate to 9600 bps
}

/**
 * @brief Hauptprogrammschleife des Projekts.
 */
void
loop()
{
  // Kalibrierung
  calibration::print();

  // Werte der Kalibrierung setzen
  moisture::AirValue = 824;
  moisture::WaterValue = 477;

  // Feuchtigkeitsmessung
  const int moistureInterval = moisture::getInterval(4);
  switch (moistureInterval) {
    case 0:
      Serial.println("Sehr trocken");
      break;
    case 1:
      Serial.println("Trocken");
      break;
    case 2:
      Serial.println("Feucht");
      break;
    case 3:
      Serial.println("Sehr feucht");
      break;
  }
  delay(100);
}