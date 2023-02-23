//Using the ezButton library to help handle button I/O
//Using Simpit to handle interacting with Kerbal Space Program

#include <KerbalSimpit.h>
#include <ezButton.h>

//TOGGLE SWITCH PINS
ezButton MAP_PIN(50);
ezButton GEAR_PIN(42);
ezButton BRAKES_PIN(46);
ezButton LIGHTS_PIN(52);
ezButton ESC_PIN(43);
ezButton ABORTSAFETY_PIN(47);
ezButton ABORT_PIN(49);
ezButton CAG1_PIN(2);
ezButton CAG2_PIN(48);
ezButton RCS_PIN(45);
ezButton SAS_PIN(40);

//PUSHBUTTON SWITCH PINS
ezButton TIMEUP_PIN(53);
ezButton TIMEDOWN_PIN(51);
ezButton CAG3_PIN(5);
ezButton CAG4_PIN(11);
ezButton CAG5_PIN(4);
ezButton CAG6_PIN(12);
ezButton STAGE_PIN(24);
ezButton CAM_VIEW_PIN(27);
ezButton ZOOM_DOWN_PIN(32);
ezButton ZOOM_UP_PIN(38);

//LED PINS
const int MAP_LED = 44;
const int RED_GEAR_LED = 28;
const int GREEN_GEAR_LED = 29;
const int RED_BRAKES_LED = 25;
const int GREEN_BRAKES_LED = 26;
const int RED_LIGHTS_LED = 22;
const int GREEN_LIGHTS_LED = 23;
const int RED_RCS_LED = 36;
const int GREEN_RCS_LED = 35;
const int RED_SAS_LED = 34;
const int GREEN_SAS_LED = 33;
const int CAG1_LED = 39;
const int CAG2_LED = 37;
const int CAG3_LED = 8;
const int CAG4_LED = 7;
const int CAG5_LED = 9;
const int CAG6_LED = 6;
const int CONNECTION_LED = 30;

//THROTTLE POTENTIOMETER PIN
const int THROTTLE_PIN = A14;

//FLIGHT JOYSTICK CONTROL PINS
const int PITCH_PIN = A11;
const int ROLL_PIN = A12;
const int YAW_PIN = A13;

//CAMERA ZOOM POTENTIOMETER PIN
const int CAM_ZOOM_PIN = A6;

//CAMERA JOYSTICK CONTROL PINS
const int CAM_PITCH_PIN = A9;
const int CAM_ROLL_PIN = A8; 
const int CAM_YAW_PIN = A10;

//CAMERA JOYSTICK VARIABLES
int16_t camPitch;
int16_t camRoll;
int16_t camYaw;

const int deadRangeLowPitch = 400;
const int deadRangeHighPitch = 650;
const int deadRangeLowRoll = 425;
const int deadRangeHighRoll = 575;
const int deadRangeLowYaw = 375;
const int deadRangeHighYaw = 625;

//VARIABLES
int abortSafety = LOW;

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
  pinMode(RED_BRAKES_LED, OUTPUT);
  pinMode(GREEN_BRAKES_LED, OUTPUT);
  pinMode(RED_LIGHTS_LED, OUTPUT);
  pinMode(GREEN_LIGHTS_LED, OUTPUT);
  pinMode(RED_SAS_LED, OUTPUT);
  pinMode(GREEN_SAS_LED, OUTPUT);
  pinMode(RED_RCS_LED, OUTPUT);
  pinMode(GREEN_RCS_LED, OUTPUT);
  pinMode(CAG1_LED, OUTPUT);
  pinMode(CAG2_LED, OUTPUT);
  pinMode(CAG3_LED, OUTPUT);
  pinMode(CAG4_LED, OUTPUT);
  pinMode(CAG5_LED, OUTPUT);
  pinMode(CAG6_LED, OUTPUT);
  pinMode(CONNECTION_LED, OUTPUT);
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
  RCS_PIN.setDebounceTime(50);
  SAS_PIN.setDebounceTime(50);
  CAG1_PIN.setDebounceTime(50);
  CAG2_PIN.setDebounceTime(50);
  CAG3_PIN.setDebounceTime(50);
  CAG4_PIN.setDebounceTime(50);
  CAG5_PIN.setDebounceTime(50);
  CAG6_PIN.setDebounceTime(50);
  STAGE_PIN.setDebounceTime(50);
  CAM_VIEW_PIN.setDebounceTime(50);
  ZOOM_UP_PIN.setDebounceTime(50);
  ZOOM_DOWN_PIN.setDebounceTime(50);
  

  while (!mySimpit.init()) {
    delay(100);
  }

  digitalWrite(LED_BUILTIN, LOW);


  mySimpit.printToKSP("Connected", PRINT_TO_SCREEN);
}

void loop() {

  mySimpit.update();

  //Initialize buttons
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
  SAS_PIN.loop();
  RCS_PIN.loop();
  CAG1_PIN.loop();
  CAG2_PIN.loop();
  CAG3_PIN.loop();
  CAG4_PIN.loop();
  CAG5_PIN.loop();
  CAG6_PIN.loop();
  CAM_VIEW_PIN.loop();
  ZOOM_UP_PIN.loop();
  ZOOM_DOWN_PIN.loop();

  digitalWrite(CONNECTION_LED, HIGH);

  if(CAG1_PIN.isPressed()) {
    digitalWrite(CAG1_LED, HIGH);
    mySimpit.printToKSP("CAG1 PRESSED");
    mySimpit.activateCAG(1);
  }
  
  if(CAG1_PIN.isReleased()) {
    digitalWrite(CAG1_LED, LOW);
    mySimpit.printToKSP("CAG1 RELEASED");
    mySimpit.deactivateCAG(1);
  }

  if(CAG2_PIN.isPressed()) {
    digitalWrite(CAG2_LED, HIGH);
    mySimpit.printToKSP("CAG2 PRESSED");
    mySimpit.activateCAG(2);
  }
  
  if(CAG2_PIN.isReleased()) {
    digitalWrite(CAG2_LED, LOW);
    mySimpit.printToKSP("CAG2 RELEASED");
    mySimpit.deactivateCAG(2);
  }

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

  if (STAGE_PIN.isPressed()) {
    mySimpit.activateAction(STAGE_ACTION);
    mySimpit.printToKSP("STAGE ACTIVATE");
  }

  if(GEAR_PIN.isPressed()) {
    mySimpit.printToKSP("Deactivate GEAR!");
    mySimpit.deactivateAction(GEAR_ACTION);
    digitalWrite(RED_GEAR_LED, HIGH);
    digitalWrite(GREEN_GEAR_LED, LOW);
  }

  if(GEAR_PIN.isReleased()) {
    mySimpit.printToKSP("Activate Gear!");
    mySimpit.activateAction(GEAR_ACTION);
    digitalWrite(RED_GEAR_LED, LOW);
    digitalWrite(GREEN_GEAR_LED, HIGH);
  }

  if(BRAKES_PIN.isReleased()) {
    mySimpit.printToKSP("Deactivate Brakes!");
    mySimpit.deactivateAction(BRAKES_ACTION);
    digitalWrite(RED_BRAKES_LED, HIGH);
    digitalWrite(GREEN_BRAKES_LED, LOW);
  }

  if(BRAKES_PIN.isPressed()) {
    mySimpit.printToKSP("Activate Brakes!");
    mySimpit.activateAction(BRAKES_ACTION);
    digitalWrite(RED_BRAKES_LED, LOW);
    digitalWrite(GREEN_BRAKES_LED, HIGH);
  }

  if(LIGHTS_PIN.isPressed()) {
    mySimpit.printToKSP("Activate Lights!");
    mySimpit.activateAction(LIGHT_ACTION);
    digitalWrite(RED_LIGHTS_LED, LOW);
    digitalWrite(GREEN_LIGHTS_LED, HIGH);
  }
  if(LIGHTS_PIN.isReleased()) {
    mySimpit.printToKSP("Deactivate Lights!");
    mySimpit.deactivateAction(LIGHT_ACTION);
    digitalWrite(RED_LIGHTS_LED, HIGH);
    digitalWrite(GREEN_LIGHTS_LED,LOW);
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

  if(RCS_PIN.isPressed()) {
    mySimpit.printToKSP("Deactivate RCS!");
    mySimpit.deactivateAction(RCS_ACTION);
    digitalWrite(RED_RCS_LED, HIGH);
    digitalWrite(GREEN_RCS_LED, LOW);
  }

  if(RCS_PIN.isReleased()) {
    mySimpit.printToKSP("Activate RCS!");
    mySimpit.activateAction(RCS_ACTION);
    digitalWrite(RED_RCS_LED, LOW);
    digitalWrite(GREEN_RCS_LED, HIGH);
  }

  if(SAS_PIN.isPressed()) {
    mySimpit.printToKSP("Deactivate SAS!");
    mySimpit.deactivateAction(SAS_ACTION);
    digitalWrite(RED_SAS_LED, HIGH);
    digitalWrite(GREEN_SAS_LED, LOW);
  }

  if(SAS_PIN.isReleased()) {
    mySimpit.printToKSP("Activate SAS!");
    mySimpit.activateAction(SAS_ACTION);
    digitalWrite(RED_SAS_LED, LOW);
    digitalWrite(GREEN_SAS_LED, HIGH);
  }

  if(CAM_VIEW_PIN.isPressed()) {
    mySimpit.printToKSP("Switching camera views");
    keyboardEmulatorMessage keyMsg(0x43);
    mySimpit.send(KEYBOARD_EMULATOR,keyMsg);  
  }

  // ------------------------------------------------------------------------------

  //THROTTLE CONTROL
  throttleMessage throttle_msg;
  int throttleReading = analogRead(THROTTLE_PIN);
  throttle_msg.throttle = map(throttleReading, 0, 1023, 0, INT16_MAX);
  mySimpit.send(THROTTLE_MESSAGE, throttle_msg);

  // ------------------------------------------------------------------------------

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

  // ------------------------------------------------------------------------------

  //CAMERA CONTROLS
  cameraRotationMessage camRot_msg;

  //ZOOM CONTROLS
  if(ZOOM_UP_PIN.isPressed()){
    mySimpit.printToKSP("ZOOM UP!");
    keyboardEmulatorMessage keyMsg(0x6B);
    mySimpit.send(KEYBOARD_EMULATOR,keyMsg);    
  }
  
  if(ZOOM_DOWN_PIN.isPressed()){
    mySimpit.printToKSP("ZOOM DOWN!");
    keyboardEmulatorMessage keyMsg(0x6D);
    mySimpit.send(KEYBOARD_EMULATOR,keyMsg);    
  }

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

  //Adjust the sensitivity of the joystick here
  camPitch = camPitch * 0.067;
  camRoll = camRoll * 1.0;
  camYaw = camYaw * 0.067;

  //Inverts axis
  camYaw = camYaw * -1.0;

  // Put those values in the message
  camRot_msg.setPitch(camPitch);
  camRot_msg.setRoll(camRoll);
  camRot_msg.setYaw(camYaw);

  // Send the message
  mySimpit.send(CAMERA_ROTATION_MESSAGE, camRot_msg);
}
