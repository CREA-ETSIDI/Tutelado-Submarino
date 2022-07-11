#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

#define densidad 997
#define g 9.80665

int valvula=13;
int bomba=12;
int fowardM1=10;
int reverseM1=9;
int fowardM2=8;
int reverseM2=7;
int i,prueba;
Adafruit_BMP280 bmp;
float pressure;
float altura;
float P0;

void setup() {
  //Set pins
  pinMode(valvula,OUTPUT);
  pinMode(bomba,OUTPUT);
  pinMode(fowardM1,OUTPUT);
  pinMode(fowardM2,OUTPUT);
  pinMode(reverseM1,OUTPUT);
  pinMode(reverseM2,OUTPUT);
  //Inicia y comprueba que los sensores esten
  Serial.begin(9600);
  if(!bmp.begin()){
    Serial.println("El sensor BMP280 no encontrado");
  }

  P0=bmp.readPressure();

}

void loop() {

  if(Serial.available()>0)
  {
    prueba=Serial.read();
  }

  Serial.println(prueba);

  //Lee los datos del sensor de temperatura
  pressure = bmp.readPressure();

  //Calcula la altura con la presión dada
  altura = (pressure-P0)/(g*densidad);

  switch(prueba)
  {
    case 'U':
    digitalWrite(valvula,HIGH);
    digitalWrite(bomba,HIGH);
    break;

    case 'D':
    digitalWrite(valvula,LOW);
    digitalWrite(bomba,LOW);
    break;

    case 'F':
    digitalWrite(fowardM1,HIGH);
    digitalWrite(fowardM2,HIGH);
    digitalWrite(reverseM1,LOW);
    digitalWrite(reverseM2,LOW);
    break;

    case 'B':
    digitalWrite(fowardM1,LOW);
    digitalWrite(fowardM2,LOW);
    digitalWrite(reverseM1,HIGH);
    digitalWrite(reverseM2,HIGH);
    break;

    case 'L':
    digitalWrite(fowardM1,LOW);
    digitalWrite(fowardM2,HIGH);
    digitalWrite(reverseM1,HIGH);
    digitalWrite(reverseM2,LOW);
    break;

    case 'R':
    digitalWrite(fowardM1,HIGH);
    digitalWrite(fowardM2,LOW);
    digitalWrite(reverseM1,LOW);
    digitalWrite(reverseM2,HIGH);
    break;

    default:
    digitalWrite(valvula,HIGH);
    digitalWrite(bomba,LOW);
    digitalWrite(fowardM1,LOW);
    digitalWrite(fowardM2,LOW);
    digitalWrite(reverseM1,LOW);
    digitalWrite(reverseM2,LOW);
    break;

    
  }

}