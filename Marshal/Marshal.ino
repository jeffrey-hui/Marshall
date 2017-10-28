#include <Servo.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);
Servo myservo1; // Servo 1
Servo myservo2; // Servo 2

float distanceValue; // Analog Buttons
int pos = 0;    // variable to store the servo position
int SensorPin = 0; // Analog Distance Sensor
float valToCm; // Conversion placeholder from Arduino reading to Centimeters

void setup() {
  myservo1.attach(9);  //
  myservo2.attach(10); // 
  lcd.begin(16,2);     //
  lcd.print("Marshal Bot"); 
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  lcd.setCursor(0,1);
  distanceValue = analogRead(A0);
  valToCm = 12343.85*pow(distanceValue,-1.15) ; 
  delay(100);
  lcd.print(valToCm);
  Serial.println(valToCm);
    if (valToCm >= 10 && valToCm <= 12){
     lcd.print("Proceed Forward                   "); 
     for (pos = 0; pos <= 180; pos += 10) { // goes from 0 degrees to 180 degrees @ 1degree           
      myservo1.write(pos); // tell servo to go to position in variable 'pos'          // Wait 5ms
      myservo2.write(pos);    
      delay(2);
     }
  }
    if (distanceValue>=925 && distanceValue<=935){
     for (pos = 180; pos >= 0; pos -= 1) { 
      myservo1.write(pos);              
      delay(5);
      myservo2.write(pos);
      delay(5);                          
    }
  }
}
