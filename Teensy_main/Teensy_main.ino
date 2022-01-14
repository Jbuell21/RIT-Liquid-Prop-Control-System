
#include <NativeEthernet.h>
#include <NativeEthernetUdp.h>


byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
IPAddress ip(10, 10, 10, 75);

unsigned int localPort = 8080;      // local port to listen on

char packetBuffer[8];  // buffer to hold incoming packet,

EthernetUDP Udp; 

typedef struct{
  uint32_t seq_num;
  uint16_t control;
  uint16_t state;
} command_t;

typedef struct{
  uint16_t ox_valve;
  uint16_t fuel_valve;
  uint16_t purge_valve;
} solenoids_t;

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
  


}
