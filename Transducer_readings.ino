
// For readings of pressures and logging them

void logPressures() {
  // Write pressures to serial monitor
  Serial.begin(9600);
  Serial.write(oxPressure);
  Serial.write(fuelPressure);
 
}
