
//#define dht_apin A0 // Analog Pin sensor is connected to
#include <FaBoLCD_PCF8574.h>
#include <Wire.h>
#include <DHT.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define DHTPIN 6
#define DHTTYPE DHT21

#define ONE_WIRE_BUS 7

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);


float Celsius = 0;

DHT dht(DHTPIN, DHTTYPE);

FaBoLCD_PCF8574 lcd;






int role = 2;





 
void setup(){

Serial.begin(9600);
Serial.println(F("DHTxx test!"));

  dht.begin();
     

//LCD KISMI
  lcd.begin(16,2);
  lcd.print("Kulucka Makinesi");
  lcd.setCursor(0,1);
  lcd.print("* DOKUZER *");
  delay(3000);
  
 //LCD KISMI 



 pinMode(role, OUTPUT); 
pinMode(3, OUTPUT); 
 pinMode(4, OUTPUT); 
pinMode(5, OUTPUT); 
 pinMode(11, OUTPUT); 
 pinMode(12, OUTPUT); 
 pinMode(13, OUTPUT); 
 


 
 
}//end "setup()"  
 
void loop(){
  
  
  
    
    float temp = dht.readTemperature();
  float hum = dht.readHumidity();


   
  Serial.print("Sıcaklık Değeridht21: ");
  Serial.println(temp);
  Serial.print("Sıcaklık Değeri dallas: ");
  Serial.println(Celsius);
   


 
  

 sensors.requestTemperatures();

 Celsius = sensors.getTempCByIndex(0); 

  
analogWrite(3,180);
analogWrite(11,200);

analogWrite(5,200);//GENEL FAN
digitalWrite(4,LOW);


  
  //Start of Program 
 
analogWrite(11,200);  //SİLKÜLASYON FANI
digitalWrite(12,LOW);
    
    
    
   
    

//LCD KISMI
 //lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Sicaklik:");
  lcd.print(Celsius);
  lcd.print("`C");

  lcd.setCursor(0,1);
  lcd.print("Nem: %");
  lcd.print(hum);
// lcd.clear();
  delay(1000);
//LCD KISMI



if (Celsius<37.1)    //temp yazılı idi
{
digitalWrite(role, LOW);// röle aç
//digitalWrite(5,HIGH); // IŞIK FANI HIZINI MAX YAPTIK.
//digitalWrite(4,LOW);
}

if (Celsius>37.5)    // temp yazılı idi
{
digitalWrite(role, HIGH);//röle kapa
//analogWrite(5,200); // IŞIK FANI HIZINI DÜŞÜRDÜK.
//digitalWrite(4,LOW);
}

if (hum<=55)
{
analogWrite(9,0);




}

if (hum>=57)
{
analogWrite(9,255);
}





 
}// end loop() 
