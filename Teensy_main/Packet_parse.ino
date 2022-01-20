extern relay_t oxValve;
extern relay_t fuelValve;
extern relay_t purgeValve;
extern relay_t igniter;
extern relay_t redLight;
extern relay_t yellowLight;
extern relay_t greenLight;
extern relay_t buzzer;
extern uint16_t replyBuffer[10];


void packetRead() {                     // Read incoming packet and parse it
 
  
  while (!Udp.parsePacket()){
   yield(); 
  }
  Serial.print("packet available");
  
  Udp.read((char*)&packetBuffer, 8);
  
  Serial.print("packet received");

  replyBuffer[8] = packetBuffer.seqNum;
 
  
  
    if (oxValve.controlNum == packetBuffer.controlNum) {
      if(packetBuffer.state == 0) {
        replyBuffer[0] = 0;
        digitalWrite(oxValve.pin, HIGH);
      } else {
        replyBuffer[0] = 1;
        digitalWrite(oxValve.pin, LOW);
      }
    } else if (fuelValve.controlNum == packetBuffer.controlNum) {
      if(packetBuffer.state == 0){
        replyBuffer[1] = 0;
        digitalWrite(fuelValve.pin, HIGH);
      } else {
        replyBuffer[1] = 1;
        digitalWrite(fuelValve.pin, LOW);
      }
    } else if (purgeValve.controlNum == packetBuffer.controlNum) {
      if(packetBuffer.state == 0){
        replyBuffer[2] = 0;
        digitalWrite(purgeValve.pin, HIGH);
      } else {
        replyBuffer[2] = 1;
        digitalWrite(purgeValve.pin, LOW);
      }
    } else if (igniter.controlNum == packetBuffer.controlNum) {
      if(packetBuffer.state == 0){
        replyBuffer[3] = 0;
        digitalWrite(igniter.pin, HIGH);
      } else {
        replyBuffer[3] = 1;
        digitalWrite(igniter.pin, LOW);
      }
    } else if (redLight.controlNum == packetBuffer.controlNum) {
      if(packetBuffer.state == 0){
        replyBuffer[4] = 0;
        digitalWrite(redLight.pin, HIGH);
      } else {
        replyBuffer[4] = 1;
        digitalWrite(redLight.pin, LOW);
      }
    } else if (yellowLight.controlNum == packetBuffer.controlNum) {
      if(packetBuffer.state == 0){
        replyBuffer[5] = 0;
        digitalWrite(yellowLight.pin, HIGH);
      } else {
        replyBuffer[5] = 1;
        digitalWrite(yellowLight.pin, LOW);
      }
    } else if (greenLight.controlNum == packetBuffer.controlNum) {
      if(packetBuffer.state == 0){
        replyBuffer[6] = 0;
        digitalWrite(greenLight.pin, HIGH);
      } else {
        replyBuffer[6] = 1;
        digitalWrite(greenLight.pin, LOW);
      }
    } else if (buzzer.controlNum == packetBuffer.controlNum) {
      if(packetBuffer.state == 0){
        replyBuffer[7] = 0;
        digitalWrite(buzzer.pin, HIGH);
      } else {
        replyBuffer[7] = 1;
        digitalWrite(buzzer.pin, LOW);
      }
  }
}


void packetSend() {                      // Send packet back with response and telemetry
  Udp.beginPacket("10.10.10.25", 8080);
  Udp.write((char*)replyBuffer, 20);
  Udp.endPacket();
  Serial.print("packet sent");

}

//void stateUpdate(object, stateNew) {                     // Update states of things

//}
