
#include <NativeEthernet.h>
#include <NativeEthernetUdp.h>

// Pin delcarations to relay
int oxValve = 0
int fuelValve = 1
int purgeValve = 2
int igniter = 3
int redLight = 4 
int yellowLight = 5
int greenLight = 6
int buzzer = 7


byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
IPAddress ip(10, 10, 10, 75);

unsigned int localPort = 8080;      // local port to listen on

char packetBuffer[8];  // buffer to hold incoming packet,

EthernetUDP Udp;

typedef struct{
  uint32_t seqNum;
  uint16_t control;
  uint16_t state;
} command_t;

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

void setup() {
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
    if (content.seq_num) {

    }
  }


}
