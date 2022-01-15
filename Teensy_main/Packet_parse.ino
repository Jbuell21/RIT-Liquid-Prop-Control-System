void packetRead {                     // Read incoming packet and parse it
  Udp.read(packetBuffer, 8);

  switch (packetBuffer.control) {
    case '100':
      if()
  }

}

void packetSend {                      // Send packet back with response and telemetry

}

void stateUpdate {                     // Update states of things

}
