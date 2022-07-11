int valvula=13;
int bomba=12;
void setup() {
  pinMode(valvula,OUTPUT);
  pinMode(bomba,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  digitalWrite(valvula,HIGH);
  digitalWrite(bomba,HIGH);
  delay(2500);
  digitalWrite(valvula,LOW);
  digitalWrite(bomba,LOW);
  Serial.println("Funciona");
  delay(2500);

}
