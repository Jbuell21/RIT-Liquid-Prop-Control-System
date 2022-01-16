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
        stateUpdate(oxValve, 0);
      } else {
        replyBuffer[0] = 1;
        digitalWrite(oxValve.pin, LOW);
        stateUpdate(oxValve, 1);
      }
      break;

    case fuelValve.controlNum:
      if(packetBuffer.state == 0){
        replyBuffer[1] = 0;
        digitalWrite(fuelValve.pin, HIGH);
        stateUpdate(fuelValve, 0);
      } else {
        replyBuffer[1] = 1;
        digitalWrite(fuelValve.pin, LOW);
        stateUpdate(fuelValve, 1);
      }
      break;

    case purgeValve.controlNum:
      if(packetBuffer.state == 0){
        replyBuffer[2] = 0;
        digitalWrite(purgeValve.pin, HIGH);
        stateUpdate(purgeValve, 0);
      } else {
        replyBuffer[2] = 1;
        digitalWrite(purgeValve.pin, LOW);
        stateUpdate(purgeValve, 1);
      }
      break;

    case igniter.controlNum:
      if(packetBuffer.state == 0){
        replyBuffer[3] = 0;
        digitalWrite(igniter.pin, HIGH);
        stateUpdate(igniter, 0);
      } else {
        replyBuffer[3] = 1;
        digitalWrite(igniter.pin, LOW);
        stateUpdate(igniter, 1);
      }
      break;

    case redLight.controlNum:
      if(packetBuffer.state == 0){
        replyBuffer[4] = 0;
        digitalWrite(redLight.pin, HIGH);
        stateUpdate(redLight, 0);
      } else {
        replyBuffer[4] = 1;
        digitalWrite(redLight.pin, LOW);
        stateUpdate(redLight, 1);
      }
      break;

    case yellowLight.controlNum:
      if(packetBuffer.state == 0){
        replyBuffer[5] = 0;
        digitalWrite(yellowLight.pin, HIGH);
        stateUpdate(yellowLight, 0);
      } else {
        replyBuffer[5] = 1;
        digitalWrite(yellowLight.pin, LOW);
        stateUpdate(yellowLight, 1);
      }
      break;

    case greenLight.controlNum:
      if(packetBuffer.state == 0){
        replyBuffer[6] = 0;
        digitalWrite(greenLight.pin, HIGH);
        stateUpdate(greenLight, 0);
      } else {
        replyBuffer[6] = 1;
        digitalWrite(greenLight.pin, LOW);
        stateUpdate(greenLight, 1);
      }
      break;

    case buzzer.controlNum:
      if(packetBuffer.state == 0){
        replyBuffer[7] = 0;
        digitalWrite(buzzer.pin, HIGH);
        stateUpdate(buzzer, 0);
      } else {
        replyBuffer[7] = 1;
        digitalWrite(buzzer.pin, LOW);
        stateUpdate(buzzer, 1);
      }
      break;

  }
    default;
}

void packetSend(packetBuffer) {                      // Send packet back with response and telemetry
  packetRead();
  if(packetBuffer.controlNum >= 100 && packetBuffer.controlNum < 200){
    Udp.begin(Udp.remoteIP(), 8080);
    Udp.write(replyBuffer);
    Udp.endPacket();
  } else if(packetBuffer.controlNum >= 200 && packetBuffer.controlNum < 300) {
    Udp.begin(Udp.remoteIP(), 8081);
    Udp.write(replyBuffer);
    Udp.endPacket();
  } else {
    Udp.begin(Udp.remoteIP(), 8082);
    Udp.write(replyBuffer);
    Udp.endPacket();
  }
}

void stateUpdate(object, stateNew) {                     // Update states of things
  object.currentState == stateNew;
}
