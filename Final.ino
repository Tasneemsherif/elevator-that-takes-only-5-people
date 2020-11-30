#include <Servo.h>
int Buttom ;
int pin= 1;
int state = HIGH;      
int reading;           
int previous = LOW;
long time = 0;         
long debounce = 200;
Servo myservo;
void setup() {
  pinMode(2, INPUT);
  pinMode(A0, INPUT);
  pinMode(12, OUTPUT); 
  pinMode(13,OUTPUT);
  pinMode(6,OUTPUT);
  myservo.attach(9);
  Serial.begin(9600);

}

void loop() {
  pin = digitalRead(Buttom);
  int value = analogRead(A0);
  Serial.println(value);
  if (pin == HIGH && previous == LOW && millis() - time > debounce) {
    if (state == HIGH)
      state = LOW;
    else
      state = HIGH;
 
    if (pin == HIGH)
   {
    
   
        digitalWrite(6,HIGH);
        digitalWrite(12,LOW);
       for (int i = 0; i < 80; i++)
      {
        myservo.write(i);
        delay(25);
        
      }
      for (int i = 79; i >= 0; i--)
      {
        myservo.write(i);
        delay(25); 
      }
     
      if (value < 300)
{
   myservo.write(0);
        digitalWrite(6,LOW);
        digitalWrite(12,HIGH);
        tone (6, 1000);
        delay(500);
        noTone(6);
        delay(500);
}
   
}

if (pin == LOW)
{
   myservo.write(0);
        digitalWrite(6,LOW);
        digitalWrite(12,HIGH);    
        noTone(6);
        
}
  }
}
