#include<Servo.h>

int servopos1 = 90, servopos2 = 90;  //To know the servo's positions
const int ser1 = 7, ser2 = 8; //The digital pin where the servos are going to connect
  
//Servos that will act as hatches
Servo servo1; 
Servo servo2;

const int ir_send1 = 2,ir_send2 = 3;  //The position of the IR LED on the Digital pin
const int ir_rec1 = A0, ir_rec2 = A1; //The position of the IR Receiver on the Analog Pin
int irSensorValue1 = 0, irSensorValue2 = 0; //The values received from the IR Receiver

void setup() {
  
  Serial.begin(9600); //For debug messages
  
  pinMode(ir_send1 , OUTPUT);
  pinMode(ir_send2 , OUTPUT);
  //Enables the usage of the IR LEDs
}

void loop() {
  
  irSensorValue1 = analogRead(ir_rec1);
  irSensorValue2 = analogRead(ir_rec2);
  //Reads the value from the receiver and stores it in the respective variable
  
  if((irSensorValue1==LOW)&&(irSensorValue2==LOW)){ 
   //Checks if the values are low/non-existant

   Serial.println("Sensor receiver obstructed, meaning the item isn't a plastic.");
   //Prints a debug message on the Serial
   
   servo1.attach(ser1); //Connects the servo
   for(int i=0;i<=servopos1;i++){
    servo1.write(i);  //Writes the servo position 1 by 1, until it gets to 90 degrees
    delay(25);  //Waits 25 milliseconds before changing the position again
   }
   
   delay(1000);
   servo1.write(0);
   servo1.detach();
   //Waits a second before going back to the position 0 and disconnecting the servo
  }
  
  else if (((irSensorValue1==HIGH)&&(irSensorValue2==HIGH))||((irSensorValue1==HIGH)||(irSensorValue2==HIGH))){
    //Checks if the values are high/existing

    Serial.println("Item isn't a plastic (or at least, it isn't one that allows the passing of IR light).");
    //Prints a debug message on the Serial
  }
   
  
}
