
// Initialization of variables

// pins
int igniter = 13;       // Set pin of igniter
int killSwitch = 18;    // Set pin of kill switch
int oxPressure = 2;     // Set pin of Oxygen pressure
int fuelPressure = 3;   // Set pin of fuel pressure

int oxValve = 9;        // Set pin of oxygen regulation valve                      Valve '1'
int fuelValve1 = 10;    // Set pin of fuel regulation valve 1, the first one       Valve '2'
int fuelValve2 = 11;    // Set pin of fuel regulation valve 2, the second one      Valve '3'
int purgeValve = 12;    // Set pin of purge valve                                  Valve '4'
int oxPump = 15;        // Set pin of Ox pump
int fuelPump = 16;      // Set pin of fuel pump

int valveStatOxV1 = 0;  // Set valve and pump states, 0 = closed, 1 = open
int valveStatFV1 = 0;
int valveStatFV2 = 0;
int valveStatPV = 0;
int pumpStateOx = 0;    // 0 = off, 1 = on
int pumpStateFuel = 0;



// Others
int startDelay = 3000;   // Delay of 3 seconds before firing
int burnTime = 7000;     // Burn for 7 seconds

String startCommand;     // Command that must be sent to start the fire sequence
String inputCommand;     // Command input by user for starting, must match startCommand to initiate start sequence


void setup() {
  // assign pins as input or output
  pinMode(killSwitch, INPUT);
  pinMode(oxPressure, INPUT);
  pinMode(fuelPressure, INPUT);

  // Interrupts to declare
  attachInterrupt(digitalPinToInterrupt(killSwitch), shutDownValves, HIGH);
  attachInterrupt(digitalPinToInterrupt(oxPressure), shutDownValves, HIGH);
  attachInterrupt(digitalPinToInterrupt(fuelPressure), shutDownValves, HIGH);
  Serial.begin(9600);

  // Initialize closed valves
  pinMode(oxValve, OUTPUT);
  digitalWrite(oxValve, LOW);
  pinMode(fuelValve1, OUTPUT);
  digitalWrite(fuelValve1, LOW);
  pinMode(fuelValve2, OUTPUT);
  digitalWrite(fuelValve2, LOW);
  pinMode(purgeValve, OUTPUT);
  digitalWrite(purgeValve, LOW);
  pinMode(oxPump, OUTPUT);
  digitalWrite(oxPump, LOW);
  pinMode(fuelPump, OUTPUT);
  digitalWrite(fuelPump, LOW);
}


void ignition() {
  // Activate the Sparky boy
  // Send high signal to igniter pins to activate
  digitalWrite(igniter, HIGH);
  delay(5000);
  digitalWrite(igniter, LOW);
  delay(burnTime);

}


void loop() {
  while(runCondition != 1){
    if(
  }
  logPressures();
  
  shutDownValves();
  // Wait for user to send start command
  while (inputCommand != startCommand) {
    inputCommand = Serial.readString();
  }
  // Begin fire sequence once while statement is broken (start command is input)

  // Open solenoid 1 (Ox valve)
  valveControl('1', 'O');

  // Open solenoid 2 and 3 (fuel valves)
  valveControl('2', 'O');
  valveControl('3', 'O');

  // Turn on pumps
  pumpControl('1', "On");
  pumpControl('2', "On");

  ignition();

  // Close fuel and ox solenoids after 7 sec firing and stop pumps
  valveControl('1', 'C');
  valveControl('2', 'C');
  valveControl('3', 'C');
  pumpControl('1', "Off");
  pumpControl('2', "Off");

  delay(3000); // Arbitrary delay before opening purge, is this necessary?

  // Open purge valve, is it necessary to repeat other valve commands? (like that in old code)
  valveControl('1', 'C');
  valveControl('2', 'C');
  valveControl('3', 'C');
  valveControl('4', 'O');

  delay(3000); // Arbitrary delay before closing purge again

  shutDownValves();
}
