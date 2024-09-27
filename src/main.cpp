
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
  // Kalibrierungswerte setzen
  moisture::airValue = 700;
  moisture::waterValue = 329;

  // So kann man die default Konfiguration überspielen
  moisture::waterThreshold = 3;
  watering::wateringDuration = 2000;
  watering::wateringWaitDuration = 30000;
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
  for (int i = 0; i < 86; i++) {
    delay(1000000);
  }
}
