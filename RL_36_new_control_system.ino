// Future things
// Electric motor control for fuel lines





// Initialization of variables


  // pins
int oxValve = 9;       // Set pin of oxygen regulation valve                      Valve '1'
int fuelValve1 = 10;   // Set pin of fuel regulation valve 1, the first one       Valve '2'
int fuelValve2 = 11;   // Set pin of fuel regulation valve 2, the second one      Valve '3'
int purgeValve = 12;   // Set pin of purge valve                                  Valve '4'
int igniter = 13;      // Set pin of igniter
int oxPressure = 2;    // Set pin of Oxygen pressure
int fuelPressure = 3;  // Set pin of fuel pressure


  // kill switch pin
int killSwitch = 18;


  // Others
int startdelay = 3000   // Delay of 3 seconds before firing
int burntime = 7000     // Burn for 7 seconds 

String startCommand     // Command that must be sent to start the fire sequence
String inputCommand     // Command input by user


void setup() {
  // assign pins as input or output
pinMode(killSwitch, INPUT);
pinMode(oxPressure, INPUT);
pinMode(fuelPressure, INPUT);

  // Interrupts to declare
attachInterrupt(digitalPinToInterrupt(killSwitch),


  // Initialize closed valves
  

}


void ignition() { 
  // Activate the Sparky boy
  // Send high signal to igniter pins to activate
  Serial.write(ignition, HIGH)
  
}


void valveControl(char valve, char state) {
  //Alter state of valve when called
  //valve- 1-4
  //state- O = open, C = closed
  
  switch(valve)

  
}


void shutDownValves() {
  // Close all valves
valveControl('1','C');
valveControl('2','C');
valveControl('3','C');
valveControl('4','C');
}


void loop() {
  // run everything
  // Wait for user to send start command
  while (inputCommand != startCommand){
    inputCommand = Serial.readString();
  }
  // Begin fire sequence once while statement is broken (start command is input)

  
}
