/*
 PROJECT NAME : Portable Ultrasonic Distance Meter
 AUTHOR       : Zülfikar AĞIRKAYA
 DATE         : 25.12.2021
//-----------------------------------------------------------------------------------------------------------------------------------------------
 PURPOSE      : Measuring and displaying distances more easily with an ultrasonic sensor instead of conventional meters
 
//-----------------------------------------------------------------------------------------------------------------------------------------------
 System Input :
                1) HC SR-04: To measure the distance
 System Output:
                1)LED      : To show the measured distance         
//-----------------------------------------------------------------------------------------------------------------------------------------------
 System Work  : Distance sensing process is carried out with HC SR-04 ulrasonic distance sensor,and the measured distance is displayed on the LCD
  
//-----------------------------------------------------------------------------------------------------------------------------------------------
 */
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

//DEFINITIONS
LiquidCrystal_I2C lcd(0x27,16,2);  // To set the LCD address to 0x27 for a 16 chars and 2 line display
#define echoPin 7                  // Echo pin of the HC SR-04 is connected to Digital 7 pin
#define trigPin 6                  // Trigger pin of the HC SR-04 is connected to Digital 6 pin
long duration, distance;           // To store the total time (in microseconds) of the sound wave propagation and return
//-----------------------------------------------------------------------------------------------------------------------------------------------

//SETUP CODE AREA
void setup() {
   
  Serial.begin (9600);             // Sets the baut rate for serial data transmission
  pinMode(trigPin, OUTPUT);        // Trigger pin defined as OUTPUT
  pinMode(echoPin, INPUT);         // Echo pin defined as INPUT
  
 
  lcd.init();                      // Initialize the lcd 
  lcd.backlight();                 // Turning on thr backlight to print a message on the LCD.
  lcd.noBlink();                   // Turns off the blinking block cursor
}
//-----------------------------------------------------------------------------------------------------------------------------------------------

//MAIN CODE AREA
void loop() {
  
                                          /* The following trigPin/echoPin codes are used to determine the distance of the nearest object by 
 bouncing soundwaves off of it. */
   delay(150);                            // Delay 150ms before next reading. 
   digitalWrite(trigPin, LOW);            // LOW pulse to ensure a clean HIGH pulse
   delayMicroseconds(2);                  // Wait for a short time
   digitalWrite(trigPin, HIGH);           // The sensor is triggered by a HIGH pulse
   delayMicroseconds(10);                 // Wait for a short time 
   digitalWrite(trigPin, LOW);            // LOW pulse again
   duration = pulseIn(echoPin, HIGH);     // It measures the time taken for the US wave to return back to the sensor
   distance = duration/58.2;              // Distance(in cm)=(time_travel/2)*sound velocity 
   
   String disp = String(distance);        // Display on LCD (creating a textual data)
   
   lcd.clear();                           // To clear text on screen
   lcd.print("distance :");               // Print text on screen
   lcd.setCursor(0, 1);                   // To start typing from the 1st line of the 0th column of the LCD screen
   lcd.print(disp);                       // Display on LCD
   lcd.print(" cm");                      // Second line

//---------------------------------------------------------------------------------------------------------------------------------------------- 

}
