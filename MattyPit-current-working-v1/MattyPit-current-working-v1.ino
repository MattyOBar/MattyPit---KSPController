//TODO: FINISH THE PROJECT
//TODO: make code readable

//Using the ezButton library to help handle button I/O
//Using Simpit to handle interacting with Kerbal Space Program

#include <KerbalSimpit.h>
#include <ezButton.h>

int abortSafety = LOW;
int stageSafety = LOW;

// // //TOGGLE SWITCH PINS
ezButton MAP_PIN(50);
ezButton GEAR_PIN(42);
ezButton BRAKES_PIN(46);
ezButton LIGHTS_PIN(52);
ezButton ESC_PIN(43);
ezButton ABORTSAFETY_PIN(47);
ezButton ABORT_PIN(49);
ezButton STAGESAFETY_PIN(38);
ezButton STAGE_PIN(3);
ezButton CAG3_PIN(5);
ezButton CAG4_PIN(11);
ezButton CAG5_PIN(4);
ezButton CAG6_PIN(12);

// //PUSHBUTTON SWITCH PINS
ezButton TIMEUP_PIN = 53;
ezButton TIMEDOWN_PIN = 51;

// // //LED PINS
const int MAP_LED = 44;
const int RED_GEAR_LED = 28;
const int GREEN_GEAR_LED = 29;
const int BLUE_GEAR_LED = 30;
const int RED_BRAKES_LED = 25;
const int GREEN_BRAKES_LED = 26;
const int BLUE_BRAKES_LED = 27;
const int RED_LIGHTS_LED = 22;
const int GREEN_LIGHTS_LED = 23;
const int BLUE_LIGHTS_LED = 24;
const int CAG3_LED = 8;
const int CAG4_LED = 7;
const int CAG5_LED = 9;
const int CAG6_LED = 6;

// //THROTTLE POTENTIOMETER PIN
const int THROTTLE_PIN = A14;

//FLIGHT JOYSTICK CONTROL PINS
const int PITCH_PIN = A11;
const int ROLL_PIN = A12;
const int YAW_PIN = A13;

//THIS BLOCK IS FOR DEBUGGING ONLY
// USE THESE TO SEE CAMERA AXIS READOUTS ON THE INGAME PITCH, ROLL, YAW
// const int PITCH_PIN = A9;
// const int ROLL_PIN = A10;
// const int YAW_PIN = A8;


// //CAMERA JOYSTICK CONTROL PINS
const int CAM_PITCH_PIN = A9;
const int CAM_ROLL_PIN = A10;
const int CAM_YAW_PIN = A8;
int16_t camPitch;
int16_t camRoll;
int16_t camYaw;

const int deadRangeLowPitch = 505;
const int deadRangeHighPitch = 525;
const int deadRangeLowRoll = 505;
const int deadRangeHighRoll = 525;
const int deadRangeLowYaw = 505;
const int deadRangeHighYaw = 525;

//DEBOUNCE TIMES
unsigned long lastDebounceTime = 0;

//DEBOUNCE DELAY
unsigned long debounceDelay = 50;


KerbalSimpit mySimpit(Serial);

void setup() {
  Serial.begin(115200);

  pinMode(MAP_LED, OUTPUT);
  pinMode(RED_GEAR_LED, OUTPUT);
  pinMode(GREEN_GEAR_LED, OUTPUT);
  pinMode(BLUE_GEAR_LED, OUTPUT);
  pinMode(RED_BRAKES_LED, OUTPUT);
  pinMode(GREEN_BRAKES_LED, OUTPUT);
  pinMode(BLUE_BRAKES_LED, OUTPUT);
  pinMode(RED_LIGHTS_LED, OUTPUT);
  pinMode(GREEN_LIGHTS_LED, OUTPUT);
  pinMode(BLUE_LIGHTS_LED, OUTPUT);
  pinMode(CAG3_LED, OUTPUT);
  pinMode(CAG4_LED, OUTPUT);
  pinMode(CAG5_LED, OUTPUT);
  pinMode(CAG6_LED, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

  MAP_PIN.setDebounceTime(50);
  GEAR_PIN.setDebounceTime(50);
  BRAKES_PIN.setDebounceTime(50);
  LIGHTS_PIN.setDebounceTime(50);
  ESC_PIN.setDebounceTime(50);
  ABORT_PIN.setDebounceTime(50);
  ABORTSAFETY_PIN.setDebounceTime(50);
  TIMEUP_PIN.setDebounceTime(50);
  TIMEDOWN_PIN.setDebounceTime(50);
  CAG3_PIN.setDebounceTime(50);
  CAG4_PIN.setDebounceTime(50);
  CAG5_PIN.setDebounceTime(50);
  CAG6_PIN.setDebounceTime(50);
  STAGE_PIN.setDebounceTime(50);
  STAGESAFETY_PIN.setDebounceTime(50);

  while (!mySimpit.init()) {
    delay(100);
  }

  digitalWrite(LED_BUILTIN, LOW);

  mySimpit.printToKSP("Connected", PRINT_TO_SCREEN);
}

void loop() {

  mySimpit.update();

  MAP_PIN.loop();
  GEAR_PIN.loop();
  BRAKES_PIN.loop();
  LIGHTS_PIN.loop();
  ESC_PIN.loop();
  ABORT_PIN.loop();
  ABORTSAFETY_PIN.loop();
  TIMEUP_PIN.loop();
  TIMEDOWN_PIN.loop();
  STAGE_PIN.loop();
  STAGESAFETY_PIN.loop();
  CAG3_PIN.loop();
  CAG4_PIN.loop();
  CAG5_PIN.loop();
  CAG6_PIN.loop();





  //   if(RCS_PIN.isPressed()){
  //     mySimpit.printToKSP("Activate RCS!");
  //     mySimpit.activateAction(RCS_ACTION);
  //     digitalWrite(RCS_LED, HIGH);
  //   }
  //   if(RCS_PIN.isReleased()){
  //     mySimpit.printToKSP("Deactivate RCS!");
  //     mySimpit.deactivateAction(RCS_ACTION);
  //     digitalWrite(RCS_LED, LOW);
  //   }
  if(CAG3_PIN.isPressed()) {
    mySimpit.printToKSP("CAG3 PRESSED");
    mySimpit.activateCAG(3);
    digitalWrite(CAG3_LED, HIGH);
  }
  
  if(CAG3_PIN.isReleased()) {
    mySimpit.printToKSP("CAG3 RELEASED");
    mySimpit.deactivateCAG(3);
    digitalWrite(CAG3_LED, LOW);
  }

  if(CAG4_PIN.isPressed()) {
    mySimpit.printToKSP("CAG4 PRESSED");
    mySimpit.activateCAG(4);
    digitalWrite(CAG4_LED, HIGH);
  }
  
  if(CAG4_PIN.isReleased()) {
    mySimpit.printToKSP("CAG4 RELEASED");
    mySimpit.deactivateCAG(4);
    digitalWrite(CAG4_LED, LOW);
  }

  if(CAG5_PIN.isPressed()) {
    mySimpit.printToKSP("CAG5 PRESSED");
    mySimpit.activateCAG(5);
    digitalWrite(CAG5_LED, HIGH);
  }
  
  if(CAG5_PIN.isReleased()) {
    mySimpit.printToKSP("CAG5 RELEASED");
    mySimpit.deactivateCAG(5);
    digitalWrite(CAG5_LED, LOW);
  } 
  
  if(CAG6_PIN.isPressed()) {
    mySimpit.printToKSP("CAG6 PRESSED");
    mySimpit.activateCAG(6);
    digitalWrite(CAG6_LED, HIGH);
  }
  
  if(CAG6_PIN.isReleased()) {
    mySimpit.printToKSP("CAG6 RELEASED");
    mySimpit.deactivateCAG(6);
    digitalWrite(CAG6_LED, LOW);
  }

  if(TIMEUP_PIN.isPressed()) {
    mySimpit.printToKSP("TIME WARP UP");
    keyboardEmulatorMessage keyMsg(0xBE);
    mySimpit.send(KEYBOARD_EMULATOR,keyMsg);
  }

  if(TIMEDOWN_PIN.isPressed()) {
    mySimpit.printToKSP("TIME WARP DOWN");
    keyboardEmulatorMessage keyMsg(0xBC);
    mySimpit.send(KEYBOARD_EMULATOR,keyMsg);
  }

  if(ESC_PIN.isPressed()) {
    mySimpit.printToKSP("ESC MENU OPEN");
    keyboardEmulatorMessage keyMsg(0x1B);
    mySimpit.send(KEYBOARD_EMULATOR, keyMsg);
  }

  if(ESC_PIN.isReleased()) {
    mySimpit.printToKSP("ESC MENU CLOSE");
    keyboardEmulatorMessage keyMsg(0x1B);
    mySimpit.send(KEYBOARD_EMULATOR, keyMsg);
  }

  if (ABORTSAFETY_PIN.isPressed()) {
    abortSafety = HIGH;
    mySimpit.printToKSP("ABORT SWITCH IS HOT");
  }

  if (ABORTSAFETY_PIN.isReleased()) {
    abortSafety = LOW;
    mySimpit.printToKSP("ABORT SWITCH IS COLD");
  }

  if (ABORT_PIN.isPressed() && abortSafety == HIGH) {
    mySimpit.activateAction(ABORT_ACTION);
    mySimpit.printToKSP("ABORT ACTIVATE");
  }

  if (STAGESAFETY_PIN.isPressed()) {
    stageSafety = HIGH;
    mySimpit.printToKSP("STAGE SWITCH IS HOT");
  }
  
  if (STAGESAFETY_PIN.isReleased()) {
    stageSafety = LOW;
    mySimpit.printToKSP("STAGE SWITCH IS COLD");
  }
  
  if (STAGE_PIN.isPressed()) {
    mySimpit.activateAction(STAGE_ACTION);
    mySimpit.printToKSP("STAGE ACTIVATE");
  }


  if(GEAR_PIN.isPressed()){
    mySimpit.printToKSP("Deactivate GEAR!");
    mySimpit.deactivateAction(GEAR_ACTION);
    digitalWrite(RED_GEAR_LED, HIGH);
    digitalWrite(GREEN_GEAR_LED, LOW);
    digitalWrite(BLUE_GEAR_LED, LOW);
  }

  if(GEAR_PIN.isReleased()){
    mySimpit.printToKSP("Activate Gear!");
    mySimpit.activateAction(GEAR_ACTION);
    digitalWrite(RED_GEAR_LED, LOW);
    digitalWrite(GREEN_GEAR_LED, HIGH);
    digitalWrite(BLUE_GEAR_LED, LOW);
  }

  if(BRAKES_PIN.isPressed()){
    mySimpit.printToKSP("Deactivate Brakes!");
    mySimpit.deactivateAction(BRAKES_ACTION);
    digitalWrite(RED_BRAKES_LED, HIGH);
    digitalWrite(GREEN_BRAKES_LED, LOW);
    digitalWrite(BLUE_BRAKES_LED, LOW);
  }
  if(BRAKES_PIN.isReleased()){
    mySimpit.printToKSP("Activate Brakes!");
    mySimpit.activateAction(BRAKES_ACTION);
    digitalWrite(RED_BRAKES_LED, LOW);
    digitalWrite(GREEN_BRAKES_LED, HIGH);
    digitalWrite(BLUE_BRAKES_LED, LOW);

  }

  if(LIGHTS_PIN.isPressed()){
    mySimpit.printToKSP("Activate Lights!");
    mySimpit.activateAction(LIGHT_ACTION);
    digitalWrite(RED_LIGHTS_LED, LOW);
    digitalWrite(GREEN_LIGHTS_LED, HIGH);
    digitalWrite(BLUE_LIGHTS_LED, LOW);
  }
  if(LIGHTS_PIN.isReleased()){
    mySimpit.printToKSP("Deactivate Lights!");
    mySimpit.deactivateAction(LIGHT_ACTION);
    digitalWrite(RED_LIGHTS_LED, HIGH);
    digitalWrite(GREEN_LIGHTS_LED,LOW);
    digitalWrite(BLUE_LIGHTS_LED, LOW);
  }

  if(MAP_PIN.isPressed()) {
    keyboardEmulatorMessage keyMsg(0x4D);
    mySimpit.send(KEYBOARD_EMULATOR,keyMsg);
    digitalWrite(MAP_LED, HIGH);
    mySimpit.printToKSP("Display Map!");
  }
  
  if(MAP_PIN.isReleased()) {
    keyboardEmulatorMessage keyMsg(0x4D);
    mySimpit.send(KEYBOARD_EMULATOR,keyMsg);  
    digitalWrite(MAP_LED, LOW);
  }

  //THROTTLE CONTROL
  throttleMessage throttle_msg;
  int throttleReading = analogRead(THROTTLE_PIN);
  throttle_msg.throttle = map(throttleReading, 0, 1023, 0, INT16_MAX);
  mySimpit.send(THROTTLE_MESSAGE, throttle_msg);



  //FLIGHT JOYSTICK CONTROL
  rotationMessage rot_msg;
  // Read the values of the potentiometers
  int reading_pitch = analogRead(PITCH_PIN);
  int reading_roll = analogRead(ROLL_PIN);
  int reading_yaw = analogRead(YAW_PIN);
  // Convert them in KerbalSimpit range
  int16_t pitch = map(reading_pitch, 0, 1023, INT16_MIN, INT16_MAX);
  int16_t roll = map(reading_roll, 1023, 0, INT16_MIN, INT16_MAX);
  int16_t yaw = map(reading_yaw, 0, 1023, INT16_MIN, INT16_MAX);
  // Put those values in the message
  rot_msg.setPitch(pitch);
  rot_msg.setRoll(roll);
  rot_msg.setYaw(yaw);
  // Send the message
  mySimpit.send(ROTATION_MESSAGE, rot_msg);



  // //CAMERA JOYSTICK CONTROL
  cameraRotationMessage camRot_msg;
  // Read the values of the potentiometers
  int cam_reading_pitch = analogRead(CAM_PITCH_PIN);
  int cam_reading_roll = analogRead(CAM_ROLL_PIN);
  int cam_reading_yaw = analogRead(CAM_YAW_PIN);
  // Check if they are in the deadzone, if not, set the values to a KSP Figure
    // Pitch
  if (cam_reading_pitch < deadRangeLowPitch) {
   camPitch = map(cam_reading_pitch, 0, deadRangeLowPitch, INT16_MIN, 0);
  } else if (cam_reading_pitch > deadRangeHighPitch) {
    camPitch = map(cam_reading_pitch, deadRangeHighPitch , 1023, 0, INT16_MAX);
  } else {
    camPitch = 0;
  }
    // Roll
  if (cam_reading_roll < deadRangeLowRoll) {
    camRoll = map(cam_reading_roll, 0, deadRangeLowRoll, INT16_MIN, 0);
  } else if (cam_reading_roll > deadRangeHighRoll) {
    camRoll = map(cam_reading_roll, deadRangeHighRoll , 1023, 0, INT16_MAX);
  } else {
    camRoll = 0;
  }
    // Yaw
  if (cam_reading_yaw < deadRangeLowYaw) {
    camYaw = map(cam_reading_yaw, 0, deadRangeLowYaw, INT16_MIN, 0);
  } else if (cam_reading_yaw > deadRangeHighYaw) {
    camYaw = map(cam_reading_yaw, deadRangeHighYaw , 1023, 0, INT16_MAX);
  } else {
    camYaw = 0;
  }
// Put those values in the message
 camRot_msg.setPitch(camPitch);
 camRot_msg.setRoll(camRoll);
 camRot_msg.setYaw(camYaw);
  // Send the message
  mySimpit.send(CAMERA_ROTATION_MESSAGE, camRot_msg);
}
//     cameraRotationMessage camRot_msg;

//     int camReading_pitch = analogRead(CAM_PITCH_PIN);
//     int camReading_roll = analogRead(CAM_ROLL_PIN);
//     int camReading_yaw = analogRead(CAM_YAW_PIN);

//     int16_t camPitch = map(camReading_pitch, 0, 1023, INT16_MIN, INT16_MAX);
//     int16_t camRoll = map(camReading_roll, 1023, 0, INT16_MIN, INT16_MAX);
//     int16_t camYaw = map(camReading_yaw, 0, 1023, INT16_MIN, INT16_MAX);
//     // Put those values in the message
//     camRot_msg.setPitch(camPitch);
//     camRot_msg.setRoll(camRoll);
//     camRot_msg.setYaw(camYaw);
//     // Send the message
//     mySimpit.send(CAMERA_ROTATION_MESSAGE, camRot_msg);

// }

// void messageHandler(byte messageType, byte msg[], byte msgSize) {
//   switch(messageType) {
    
//   case ALTITUDE_MESSAGE:
//     if (msgSize == sizeof(altitudeMessage)) {
//       altitudeMessage myAltitude;
//       myAltitude = parseMessage<altitudeMessage>(msg);
//       // further processing of altitude data in myAltitude here

//       lcd.setCursor(0,0);
//       lcd.print(myAltitude.surface);
//     };

//    case AIRSPEED_MESSAGE:
//     if (msgSize == sizeof(airspeedMessage)) {
//       airspeedMessage myAirspeed;
//       myAirspeed = parseMessage<airspeedMessage>(msg);
//       // further processing of altitude data in myAltitude here

//       lcd.setCursor(0,1);
//       lcd.print(myAirspeed.IAS);
//     };
    
//     break;
//   }
// }