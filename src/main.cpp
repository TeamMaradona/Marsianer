
#include "calibration.hpp"
#include "moisture.hpp"
#include <Arduino.h>

// Hier wird die Funktion der Pins festgelegt
void
setup()
{
  Serial.begin(9600); // open serial port, set the baud rate to 9600 bps
}

// Hauptprogramm
void
loop()
{
  // Kalibrierung
  calibration::print();

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