
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
  // Kalibrierungsdaten ausgeben
  calibration::print();

  // Werte der Kalibrierung setzen
  moisture::AirValue = 824;
  moisture::WaterValue = 477;

  // Feuchtigkeitsmessung
  int values[] = { moisture::getValue(5, 0),
                   moisture::getValue(5, 1),
                   moisture::getValue(5, 2),
                   moisture::getValue(5, 3) };

  // Schalte digitale Pins ein oder aus
  for (int i = 0; i < 4; i++) {
    if (values[i] < 2) {
      digitalWrite(i, HIGH);
    } else {
      digitalWrite(i, LOW);
    }
  }

  // Warte 1000ms
  delay(1000);
}