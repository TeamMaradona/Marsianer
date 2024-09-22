#include <Arduino.h>

// Werte aus der Kalibrierung
const int AirValue = 824;
const int WaterValue = 477;

// Intervalle für die Ausgabe
int intervals = (AirValue - WaterValue) / 3;
int soilMoistureValue = 0;

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
  soilMoistureValue = analogRead(A0);
  if (soilMoistureValue > WaterValue &&
      soilMoistureValue < (WaterValue + intervals)) {
    Serial.println("Very Wet");
  } else if (soilMoistureValue > (WaterValue + intervals) &&
             soilMoistureValue < (AirValue - intervals)) {
    Serial.println("Wet");
  } else if (soilMoistureValue < AirValue &&
             soilMoistureValue > (AirValue - intervals)) {
    Serial.println("Dry");
  }
  delay(100);
}
