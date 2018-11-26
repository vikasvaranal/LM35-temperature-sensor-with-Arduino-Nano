#include <Arduino.h>
//initialise the LED pins
#define LEDPIN1 4
#define LEDPIN2 3
//initialise delay times
const int time1 = 1000;
const int time2 = 2000;

//deine the sensor pin --Analog connection
#define pinTemp A0
float tempC;
float tempF;
float Vout;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LEDPIN1,OUTPUT);
  pinMode(LEDPIN2, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  Vout = analogRead(pinTemp);
  Vout = ((Vout/1024.0)*5000)/10;
  tempC = Vout;
  tempF = (Vout*1.8)+32;
  Serial.print("Temperature in Celsius=");
  Serial.print("\t");
  Serial.print(tempC);
  Serial.print("°C");
  Serial.print("\n");
  Serial.print("Temperature in Fahrenheit=");
  Serial.print("\t");
  Serial.print(tempF);
  Serial.println("°F");
  delay(time1);

  if(tempC < 27.00) {
    digitalWrite(LEDPIN1, HIGH);
    }else{
      digitalWrite(LEDPIN2, HIGH);
    }

/*  digitalWrite(LEDPIN1, HIGH);
  delay(time1);
  digitalWrite(LEDPIN2,HIGH);
  delay(time2);
  digitalWrite(LEDPIN1, LOW);
  delay(time1);
  digitalWrite(LEDPIN2,LOW);
  delay(time2);
  */
}