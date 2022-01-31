#include <Servo.h>

Servo myservo;

int servoPin = 3;
int derece = 0;

void setup()
{
  pinMode(7,OUTPUT);
  myservo.attach(servoPin);
  
}

void loop()
{
 
  for (derece=0; derece<=150; derece+=1) //0'dan 180'e kadar birer derece artır
  {
    myservo.write(derece);
    delay(100);
  }
 
   myservo.attach(7);
   
 delay(7200000);

myservo.attach(3);
  for(derece=150  ; derece>=0; derece-=1) //180'den 0'a kadar birer derece azalt
  {
    myservo.write(derece);
    delay(100);
  }
    ;
  myservo.attach(7);
 delay(7200000);
  myservo.attach(3);



}
