#define azul 44
#define verde 45
#define amarillo 46
#define rojo 47
  
void setup() {
  pinMode(azul, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(rojo, OUTPUT);
    

}

void loop() {
  
  digitalWrite(azul, HIGH);
  delay(50);
  digitalWrite(azul, LOW);
  delay(50);
  digitalWrite(verde, HIGH);
  delay(50);
  digitalWrite(verde,LOW);
  delay(50);
  digitalWrite(amarillo, HIGH);
  delay(50);
  digitalWrite(amarillo,LOW);
  delay(50);
  digitalWrite(rojo, HIGH);
  delay(50);
  digitalWrite(rojo,LOW);
  delay(50);
 
   
}
