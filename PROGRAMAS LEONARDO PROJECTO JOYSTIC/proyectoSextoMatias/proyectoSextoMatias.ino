#define potenciometro1 A1
#define potenciometro2 A2
#define potenciometro3 A3
#define potenciometro4 A4
#define potenciometro5 A5


void setup() {
  Serial.begin(9600);
  pinMode(potenciometro1, INPUT);
  pinMode(potenciometro2, INPUT);
  //pinMode(potenciometro3, INPUT);
  //pinMode(potenciometro4, INPUT);
  //pinMode(potenciometro5, INPUT);
}

void loop() {

  double varPote1 = analogRead(potenciometro1);
  delay(100);
  double varPote2 = analogRead(potenciometro2);
  delay(100);
 // double varPote3 = analogRead(potenciometro3);
 // double varPote4 = analogRead(potenciometro4);
 // double varPote5 = analogRead(potenciometro5);
  Serial.print("Pote1: ");
  Serial.print(varPote1);
  Serial.print("\t  Pote2: ");
  Serial.println(varPote2);
  //Serial.print("Pote3: ");
  //Serial.println(varPote3);
  //Serial.print("Pote4: ");
  //Serial.println(varPote4);
  //Serial.print("Pote5: ");
  //Serial.println(varPote5);



  

}
