
#include <NativeEthernet.h>
#include <NativeEthernetUdp.h>

uint16_t replyBuffer[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
IPAddress ip(10, 10, 10, 75);

unsigned int localPort = 8080;      // local port to listen on

EthernetUDP Udp;

typedef struct {
  uint16_t pin;
  uint16_t currentState;
  uint16_t controlNum;
} relay_t;

typedef struct {
  uint32_t seqNum;
  uint16_t controlNum;
  uint16_t state;
} ec_command_t;

ec_command_t packetBuffer;

relay_t oxValve = {0, 0, 100};
relay_t fuelValve = {1, 0, 101};
relay_t purgeValve = {2, 0, 102};
relay_t igniter = {3, 0, 200};
relay_t redLight = {4, 0, 300};
relay_t yellowLight = {5, 0, 301};
relay_t greenLight = {6, 0, 302};
relay_t buzzer = {7, 0, 303};

void setup() {
  Ethernet.begin(mac, ip);
  Serial.begin(9600);


  if (Ethernet.hardwareStatus() == EthernetNoHardware) {
    while (true) {
      delay(1);
    }
  }

  Udp.begin(localPort);
  packetSend();
}



void loop() {

  packetRead();
  packetSend();

}
