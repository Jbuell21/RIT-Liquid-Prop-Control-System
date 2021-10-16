
void pumpControl(char pump, String state) {
  //Either run or stop pump depending on what is called
  //pump 1 = Ox pump, pump 2 = fuel pump
  //state - On = turn on, off = turn off

  if (pump == '1'){
    if (state == "On") {
        digitalWrite(oxPump, HIGH);
        pumpStateOx = 1;
      }
      else {
        digitalWrite(oxPump, LOW);
        pumpStateOx = 0;
      }
  } else if (pump == '2'){
    if (state == "On") {
        digitalWrite(fuelPump, HIGH);
        pumpStateFuel = 1;
      }
      else {
        digitalWrite(fuelPump, LOW);
        pumpStateFuel = 0;
      }
  }
}


void valveControl(char valve, char state) {
  //Alter state of valve when called
  //valve- 1-4
  //state- O = open, C = closed

  switch (valve) {
    case '1':
      if (state == 'O') {
        digitalWrite(oxValve, HIGH);
        valveStatOxV1 = 1;
      }
      else {
        digitalWrite(oxValve, LOW);
        valveStatOxV1  = 0;
      }
      break;
    case '2':
      if (state == 'O') {
        digitalWrite(fuelValve1, HIGH);
        valveStatFV1 = 1;
      }
      else {
        digitalWrite(fuelValve1, LOW);
        valveStatFV1 = 0;
      }
      break;
    case '3':
      if (state == 'O') {
        digitalWrite(fuelValve2, HIGH);
        valveStatFV2 = 1;
      }
      else {
        digitalWrite(fuelValve2, LOW);
        valveStatFV2 = 0;
      }
      break;
    case '4':
      if (state == 'O') {
        digitalWrite(purgeValve, HIGH);
        valveStatPV = 1;
      }
      else {
        digitalWrite(purgeValve, LOW);
        valveStatPV = 0;
      }
      break;
    default:
      break;
  }

  return;
}

void shutDownValves() {
  // Close all valves
  valveControl('1', 'C');
  valveControl('2', 'C');
  valveControl('3', 'C');
  valveControl('4', 'C');
}