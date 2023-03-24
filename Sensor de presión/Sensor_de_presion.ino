#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

#define densidad 997
#define g 9.80665

Adafruit_BMP280 bmp;
float pressure;
float altura;
float P0;
long last_millis;
long current_millis;

void setup() {
  //Inicia y comprueba que los sensores esten
  Serial.begin(9600);
  Serial.println("Iniciado: ");
  if(!bmp.begin()){
    Serial.println("El sensor BMP280 no encontrado");
  }

  P0=bmp.readPressure();

}

void loop() {

  last_millis=millis();

  //Lee los datos del sensor de temperatura
  pressure = bmp.readPressure();

  //Calcula la altura con la presión dada
  altura = (pressure-P0)/(g*densidad);

  //Escribe la altura y la presión
  Serial.print("Altura: ");
  Serial.print(altura);
  Serial.print(" m");
  Serial.print("  Presion: ");
  Serial.print(pressure);
  Serial.println(" Pa");

  do
  {
    current_millis=millis();
  } while((current_millis-last_millis)<5000);
}
