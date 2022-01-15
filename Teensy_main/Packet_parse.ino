void packetRead {                     // Read incoming packet and parse it
  Udp.read(packetBuffer, 8);
  if (packetBuffer.seqNum == currentSeqNum + 1){
    currentSeqNum = packetBuffer.seqNum;
  } else {
    return replyBuffer;
  }

  switch (packetBuffer.control) {

    case oxValve.controlNum:
      if(packetBuffer.state == 0) {
        replyBuffer[0] = 0;
        digitalWrite(oxValve.pin, HIGH);
      } else {
        replyBuffer[0] = 1;
        digitalWrite(oxValve.pin, LOW);
      }
      break;

    case fuelValve.controlNum:
      if(packetBuffer.state == 0){
        replyBuffer[1] = 0;
        digitalWrite(fuelValve.pin, HIGH);
      } else {
        replyBuffer[1] = 1;
        digitalWrite(fuelValve.pin, LOW);
      }
    case purgeValve.controlNum:
      if(packetBuffer.state == 0){
        replyBuffer[2] = 0;
        digitalWrite(purgeValve.pin, HIGH);
      } else {
        replyBuffer[2] = 1;
        digitalWrite(purgeValve.pin, LOW);
      }
    case igniter.controlNum:
      if(packetBuffer.state == 0){
        replyBuffer[3] = 0;
        digitalWrite(igniter.pin, HIGH);
      } else {
        replyBuffer[3] = 1;
        digitalWrite(igniter.pin, LOW);
      }
    case redLight.controlNum:
      if(packetBuffer.state == 0){
        replyBuffer[4] = 0;
        digitalWrite(redLight.pin, HIGH);
      } else {
        replyBuffer[4] = 1;
        digitalWrite(redLight.pin, LOW);
      }
    case yellowLight.controlNum:
      if(packetBuffer.state == 0){
        replyBuffer[5] = 0;
        digitalWrite(yellowLight.pin, HIGH);
      } else {
        replyBuffer[5] = 1;
        digitalWrite(yellowLight.pin, LOW);
      }
    case greenLight.controlNum:
      if(packetBuffer.state == 0){
        replyBuffer[6] = 0;
        digitalWrite(greenLight.pin, HIGH);
      } else {
        replyBuffer[6] = 1;
        digitalWrite(greenLight.pin, LOW);
      }
    case buzzer.controlNum:
      if(packetBuffer.state == 0){
        replyBuffer[7] = 0;
        digitalWrite(buzzer.pin, HIGH);
      } else {
        replyBuffer[7] = 1;
        digitalWrite(buzzer.pin, LOW);
      }
  }

}

void packetSend {                      // Send packet back with response and telemetry



}

void stateUpdate(object, stateNew) {                     // Update states of things

}
