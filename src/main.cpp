
#include "calibration.hpp"
#include "moisture.hpp"
#include "watering.hpp"
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
  watering::wateringDuration = 1000;
  watering::wateringWaitDuration = 5000;
  watering::wateringInterval = 10000;
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

  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
}

/**
 * @brief Hauptprogrammschleife des Projekts.
 */
void
loop()
{
  // Konfiguration
  configure();

  // Nutzerausgabe
  Serial.println("\n==============================================");
  Serial.println("Starte Bewässerungssystem");

  // Kalibrierungsdaten ausgeben
  calibration::printAll();

  // Feuchtigkeitsmessung
  const int numLevels = 5;
  const int values[] = { moisture::getValue(numLevels, 0),
                         moisture::getValue(numLevels, 1),
                         moisture::getValue(numLevels, 2),
                         moisture::getValue(numLevels, 3) };

  // Bewässerung starten
  watering::run(values, numLevels);

  // Warten bevor der nächste Durchlauf startet
  delay(10000);
}
