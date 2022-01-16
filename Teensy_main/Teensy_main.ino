
#include <NativeEthernet.h>
#include <NativeEthernetUdp.h>

uint16_t currentSeqNum = 0;
char packetBuffer[8];  // buffer to hold incoming packet,

byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
IPAddress ip(10, 10, 10, 75);

unsigned int localPort = 8080;      // local port to listen on

EthernetUDP Udp;

typedef struct{
  uint16_t pinNum;
  uint16_t currentState;
  uint16_t controlNum;
} relay_t;

typedef struct{
  uint16_t oxValve;
  uint16_t fuelValve;
  uint16_t purgeValve;
} solenoids_t;

typedef struct{
  uint16_t red;
  uint16_t yellow;
  uint16_t green;
  uint16_t buzz;
} tower_t;

relay_t oxValve;
oxValve.pinNum = 0;
oxValve.currentState = 0;
oxValve.controlNum = 100;

relay_t fuelValve;
fuelValve.pinNum = 1;
fuelValve.currentState = 0;
fuelValve.controlNum = 101;

relay_t purgeValve;
purgeValve.pinNum = 2;
purgeValve.currentState = 0;
purgeValve.controlNum = 102;

relay_t igniter;
igniter.pinNum = 3;
igniter.currentState = 0;
igniter.controlNum = 200;

relay_t redLight;
redLight.pinNum = 4;
redLight.currentState = 0;
redLight.controlNum = 300;

relay_t yellowLight;
yellowLight.pinNum = 5;
yellowLight.currentState = 0;
yellowLight.controlNum = 301;

relay_t greenLight;
greenLight.pinNum = 6;
greenLight.currentState = 0;
greenLight.controlNum = 302;

relay_t buzzer;
buzzer.pinNum = 7;
buzzer.currentState = 0;
buzzer.controlNum = 303;

uint16_t replyBuffer[8] = [0, 0, 0, 0, 0, 0, 0, 0]

void setup() {
  pinMode(oxValve, OUTPUT);
  digitalWrite(oxValve, HIGH);
  pinMode(fuelValve, OUTPUT);
  digitalWrite(fuelValve, HIGH);
  pinMode(purgeValve, OUTPUT);
  digitalWrite(purgeValve, HIGH);
  pinMode(igniter, OUTPUT);
  digitalWrite(igniter, HIGH);

  pinMode(redLight, OUTPUT);
  digitalWrite(redLight, HIGH);
  pinMode(yellowLight, OUTPUT);
  digitalWrite(yellowLight, HIGH);
  pinMode(greenLight, OUTPUT);
  digitalWrite(greenLight, HIGH);
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, HIGH);

  Ethernet.begin(mac, ip);

  if(Ethernet.hardwareStatus() == EthernetNoHardware){
    while(true){
      delay(1);
    }
  }

  Udp.begin(localPort);

}



void loop() {
  int packetSize = Udp.parsePacket();
  if (packetSize) {
    
  }


}
