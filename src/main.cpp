
#include "calibration.hpp"
#include "moisture.hpp"
#include <Arduino.h>

/**
 * @file main.cpp
 * @brief Hauptprogramm des Projekts.
 */
// Werte der Kalibrierung setzen
void
configure()
{
  moisture::airValue = 700;
  moisture::waterValue = 329;
  moisture::waterThreshold = 4;
}

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
  calibration::printAll();

  // Feuchtigkeitsmessung
  const int numLevels = 5;
  const int* values = moisture::getValues(numLevels);

  // Schalte digitale Pins ein oder aus
  // Loop über alle Werte
  Serial.println("Feuchtigkeitswerte:");
  for (int i = 2; i < 6; i++) {
    Serial.print("AnalogPin " + String(i) + ": Stufe " + String(values[i - 2]) +
                 " von " + numLevels + "\n");
    // Feuchtigkeitswert die kleiner 2 sind, schalte den Pin ein
    if (values[i - 2] >= 4) {
      /* Serial.println("----------------------------------------------");
       Serial.println(">> Aktiviere DigitalPin " + String(i));
       Serial.println(">> Wasser aktiviert...");
       digitalWrite(i, HIGH);
       delay(5000);
       digitalWrite(i, LOW);
       Serial.println(">> Wasser deaktiviert");
       delay(300000);
       Serial.println(">> Warte 3 Minuten...");*/
    } else {
      digitalWrite(i, LOW);
    }
  }
  Serial.println("===============================================");
  // Warte 1000ms

  delay(1000);
}
