
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
  Serial.begin(9600);
  // Initialisiere die digitalen Pins

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

/**
 * @brief Hauptprogrammschleife des Projekts.
 */
void
loop()
{
  // Kalibrierungsdaten ausgeben
  calibration::print(0);
  calibration::print(1);
  calibration::print(2);
  calibration::print(3);

  // Werte der Kalibrierung setzen
  moisture::AirValue = 700;
  moisture::WaterValue = 329;

  // Feuchtigkeitsmessung
  const int numLevels = 5;
  int values[] = { moisture::getValue(numLevels, 2),
                   moisture::getValue(numLevels, 3),
                   moisture::getValue(numLevels, 4),
                   moisture::getValue(numLevels, 5) };

  // Schalte digitale Pins ein oder aus
  // Loop über alle Werte
  Serial.println("Feuchtigkeitswerte:");
  for (int i = 2; i < 6; i++) {
    Serial.print("AnalogPin " + String(i) + ": Stufe " + String(values[i - 2]) +
                 " von " + numLevels + "\n");
    // Feuchtigkeitswert die kleiner 2 sind, schalte den Pin ein
    if (values[i - 2] >= 5) {
      digitalWrite(i, LOW);
      Serial.println(">> Aktiviere DigitalPin " + String(i));
    } else {
      digitalWrite(i, HIGH);
    }
  }
  Serial.println("===============================================");
  // Warte 1000ms

  delay(1000);
}
