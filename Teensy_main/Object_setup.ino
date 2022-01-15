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
