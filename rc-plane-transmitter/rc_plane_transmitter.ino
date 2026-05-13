/*EC23B1038 Caitlin Leonard
TAD Assignment 
RC Plane Controls and Transmitter */

#include <Servo.h>
#include <Wire.h> // for communication over the i2c bus
#include <LiquidCrystal_I2C.h>
#include <AccelStepper.h>  // for controlling stepper motors with acceleration and deceleration

// Pin definitions
#define steppin 10  // for stepper motor
#define dirpin 11
#define enablepin 13
#define sleeppin 5  // 5V
#define resetpin 5
#define alpin 2 // for servo - left aileron
#define arpin 3 // right aileron
#define rudpin 4 // rudder
#define xpin A2 // joystick - horizontal
#define ypin A3
#define tpin 5 // toggle button
#define epin 6 // emergency stop button

// GLOBAL variables
Servo al; // servo objects
Servo ar;
Servo rud;
LiquidCrystal_I2C lcd(0x27, 16, 2); // object for LCD - address
AccelStepper stepper(AccelStepper::DRIVER, steppin, dirpin); // controlling the stepper motor using the driver
bool showal=true;  // to toggle between al and ar
bool sysenabled=true;
int stepperspd = 0; // in RPM
long targetpos=200; // (initial target pos) the number of steps could exceed the range of a 16-bit int... long (32-bit)
int prevalangle=-1; // angles (to store previous value for display updates in LCD)
int prevarangle=-1;
int prevrudangle=-1;
int prevstepperspd=-1;

// setup function
void setup(){
  Serial.begin(9600); // 9600 baud rate for serial communication
  pinMode(enablepin,OUTPUT); // initializing
  pinMode(sleeppin,OUTPUT);
  pinMode(resetpin,OUTPUT);
  digitalWrite(enablepin,LOW); // enables
  digitalWrite(sleeppin,HIGH); // driver awake
  digitalWrite(resetpin,HIGH); // driver reset
  al.attach(alpin); // attaching the objects to their pins
  ar.attach(arpin);
  rud.attach(rudpin);
  lcd.init();
  lcd.backlight(); // backlight turned on
  pinMode(tpin,INPUT_PULLUP); // button pins are configured with internal pullup resistors
  pinMode(epin,INPUT_PULLUP);
  stepper.moveTo(targetpos); // setting the initial target position
}

// MAIN
void loop() {
  if(digitalRead(tpin)==LOW){
    delay(50);
    if(digitalRead(tpin)==LOW){ // second check to ensure that button was really pressed (DEBOUNCING MECHANISM)
      showal= !showal;
      delay(200); // debounce delay to prevent multiple toggles
    }
  }
  if(!sysenabled){
    lcd.clear(); // clear previous message
    lcd.setCursor(0,0); // first col, first row
    lcd.print("EMERGENCY STOP");
    lcd.setCursor(0,1); // moves the cursor to beginning of second line
    lcd.print("              "); // ensures no old msg is displayed
    return;
  }
  int alangle=constrain(analogRead(A0)/4, 0,180); //  range(0-180) conversion 
  int arangle=constrain(analogRead(A1)/4, 0,180); 
  int rudangle=constrain(analogRead(A2)/4, 0,180);
  al.write(alangle); // setting the servo to this angle
  ar.write(arangle);
  rud.write(rudangle);
  if(digitalRead(epin)==LOW) { // emergency stop
    stepper.stop();
    digitalWrite(epin,HIGH); // disabling 
    sysenabled=false;
  }
  int yval=analogRead(ypin); // joystick
  int jst=100; // joystick threshold
  if (yval>(512+jst)){
    stepperspd+=1; // 512 (midpoint of analog reading (0-1023) neutral reference point)
    if (stepperspd>1000) {
      stepperspd=1000; // max limit
    }
  } else if(yval<(512-jst)){
    stepperspd-=1;
    if(stepperspd<0){
      stepperspd=0; // min lim
    }
  }
  int stepperrev=200;
  int sps=stepperspd*stepperrev/60; // rpm to steps per second
  stepper.setMaxSpeed(sps);
  stepper.setAcceleration(100);
  if(stepper.distanceToGo()==0){
    targetpos+=200;
    stepper.moveTo(targetpos);
  }
  stepper.run();
  if(showal){ // toggle
    if (alangle!=prevalangle){
      lcd.clear(); // Clear previous display
      lcd.setCursor(0,0);
      lcd.print("AL:");
      lcd.print(alangle);
      prevalangle=alangle;
    }
  } 
  else{
    if(arangle!=prevarangle){
      lcd.clear(); // Clear previous display
      lcd.setCursor(0,0);
      lcd.print("AR:");
      lcd.print(arangle);
      prevarangle=arangle;
    }
  }
  if (rudangle!=prevrudangle || stepperspd!=prevstepperspd){
    lcd.setCursor(0,1);
    lcd.print("Rud:");
    lcd.print(rudangle);
    lcd.print(" Spd:");
    lcd.print(stepperspd);
    prevrudangle=rudangle;
    prevstepperspd=stepperspd;
  }
  Serial.print("Stepper Pos: ");
  Serial.println(stepper.currentPosition());
  delay(100);
}
