
#include <NativeEthernet.h>
#include <NativeEthernetUdp.h>

uint16_t currentSeqNum = 0
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
