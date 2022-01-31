#include "dht.h"
//#define dht_apin A0 // Analog Pin sensor is connected to
#include <FaBoLCD_PCF8574.h>
#include <Wire.h>
#include <DHT.h>

#define DHTPIN A0
#define DHTTYPE DHT11


FaBoLCD_PCF8574 lcd;


dht DHT;

const int motorPin1 = 6;
const int motorPin2 = 7;
const int motorPin3 = 8;
const int motorPin4 = 9;

int bekleme = 5;

int role = 2;

 void adim1() {
digitalWrite(motorPin1, HIGH);
digitalWrite(motorPin2, LOW);
digitalWrite(motorPin3, LOW);
digitalWrite(motorPin4, LOW);
delay(bekleme);
}

void adim2() {
digitalWrite(motorPin1, LOW);
digitalWrite(motorPin2, HIGH);
digitalWrite(motorPin3, LOW);
digitalWrite(motorPin4, LOW);
delay(bekleme);
}

void adim3() {
digitalWrite(motorPin1, LOW);
digitalWrite(motorPin2, LOW);
digitalWrite(motorPin3, HIGH);
digitalWrite(motorPin4, LOW);
delay(bekleme);
}

void adim4() {
digitalWrite(motorPin1, LOW);
digitalWrite(motorPin2, LOW);
digitalWrite(motorPin3, LOW);
digitalWrite(motorPin4, HIGH);
delay(bekleme);
}




 
void setup(){

//LCD KISMI
  lcd.begin(16,2);
  lcd.print("Robotisan.com");
  delay(1000);
  
 //LCD KISMI 

 //STEP MOTOR KISMI
pinMode(motorPin1, OUTPUT);
pinMode(motorPin2, OUTPUT);
pinMode(motorPin3, OUTPUT);
pinMode(motorPin4, OUTPUT);

 pinMode(role, OUTPUT); 
pinMode(3, OUTPUT); 
 pinMode(4, OUTPUT); 
pinMode(5, OUTPUT); 
 pinMode(11, OUTPUT); 
 pinMode(12, OUTPUT); 
 pinMode(13, OUTPUT); 
 //STEP MOTOR KISMI


 
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
 
}//end "setup()"  
 
void loop(){


  
analogWrite(3,200);
analogWrite(11,200);

digitalWrite(5,HIGH);//GENEL FAN
digitalWrite(4,LOW);


  
  //Start of Program 
 
    DHT.read11(dht_apin);
    
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("'C  ");
    
    delay(1000);//Wait 5 seconds before accessing sensor again.
    


  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Sicaklik: ");
  lcd.print(DHT.temperature);
  lcd.print(" C");

  lcd.setCursor(0,1);
  lcd.print("Nem: %");
  lcd.print(DHT.humidity);

  delay(2000);


if (DHT.temperature<38)
{
digitalWrite(role, HIGH);// röle aç
}

if (DHT.temperature>38)
{
digitalWrite(role, LOW);//röle kapa
}

if (DHT.humidity<55)
{
digitalWrite(12,HIGH);//NEM FAN aç
digitalWrite(13,LOW);

}

if (DHT.humidity>60)
{
digitalWrite(12,LOW);//NEM FAN kapa
digitalWrite(13,LOW);
}


//STEP MOTOR KISMI
for (int i = 0; i < 232; i++)
{
adim1();
adim2();
adim3();
adim4();

}
delay(7200000);

for (int i = 0; i < 232; i++)
{
adim4();
adim3();
adim2();
adim1();

}
delay(7200000);

//STEP MOTOR KISMI

 
}// end loop() 
