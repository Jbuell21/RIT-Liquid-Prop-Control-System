
// For readings of pressures and logging them
int index = 0;
int OxVoltageIn = 1;
int FuelVoltageIn = 1;
Serial.begin(9600)

void logPressures(int index, float OxVoltage, float FuelVoltage) {
  float OxPressure[index] = {OxVoltage};
  float FuelPressure[index] = {FuelVoltage};

  return OxPressure,FuelPressure;

}

Serial.print(logPressures(index, OxVoltageIn, FuelVoltageIn));
