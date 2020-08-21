
#include <Servo.h>

Servo myservo;
int pos = 0;// create servo object to control a servo
void setup() {
  // put your setup code here, to run once:
pinMode(13,OUTPUT);//trig
pinMode(12,INPUT);//echo

    
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(13,LOW);//trig
delay(2);
digitalWrite(13,HIGH);
delay(10);
digitalWrite(13,LOW);
float dur=pulseIn(12,HIGH);
float dis=(0.067*dur);
Serial.println(dis);
if(dis<=50)
{
  
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
 
  delay(1000);
   
}
}
