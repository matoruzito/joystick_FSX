#include<Joystick.h>
//Programa para lectura de potencometros leonardo con leds.
#define azul 4 
#define verde 5 
#define amarillo 6
#define rojo 7 

#define pote1 A1 
#define pote2 A2 
#define pote3 A3 
#define pote4 A4
#define pote5 A5


float pote1Valor, pote2Valor, pote3Valor, pote4Valor, pote5Valor; 
float factor; 
float division;
int previo, previo1;  

void setup(){
  pinMode(azul, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(rojo, OUTPUT);
  
  pinMode(pote1, INPUT);
  pinMode(pote2, INPUT);
  pinMode(pote3, INPUT);
  pinMode(pote4, INPUT);
  pinMode(pote5, INPUT);
       
  Serial.begin(9600);

  Joystick.begin();
  
}


void loop(){
    //Leemos valor del Pote 1 (Girar izquierda Derecha); 
   
    pote1Valor = analogRead(pote1);
 
    //Variable División, almacena una constante necesaria para convertir a la escala adecuada
    division = 0.248046875; 

 
    pote1Valor = ((pote1Valor*division)-127);
      
    Joystick.setXAxis(pote1Valor);
    Serial.println(pote1Valor);
    //Acaban de ser seteados los valores del axis X o eje x 
      
   
    pote2Valor = analogRead(pote2);

    pote2Valor = ((pote2Valor*division)-127);

    Joystick.setYAxis(pote2Valor);
    Serial.println(pote1Valor);

    //Se setean los valores de axis Y 
    
    pote3Valor = analogRead(pote3);



    pote3Valor = ((pote3Valor*division));

     Joystick.setThrottle(pote3Valor);
               

    pote4Valor = analogRead(pote4);

    pote4Valor = ((pote4Valor*division));

    Joystick.setRudder(pote4Valor);
    

      
    
    pote5Valor = analogRead(pote5);
    pote5Valor = ((pote5Valor*division)-127);
    Joystick.setZAxis(pote5Valor);

     
   
  if(digitalRead(0) != previo ){
    Joystick.setButton(3, 1);
    delay(50);
    Joystick.setButton(3, 0);
    previo = !previo;  
  }

  previo = digitalRead(0);
  
  if(digitalRead(1) != previo1 ){
    Joystick.setButton(2, 1);
    delay(50);
    Joystick.setButton(2, 0);
    previo1 = !previo1;  
  }

  previo1 = digitalRead(1);
  
    

 
  
    
 
   Serial.print("Pote1 = ");
   Serial.print(pote1Valor);
   Serial.print("\t");
   Serial.print("Pote2 = ");
   Serial.print(pote2Valor);
  Serial.print("\t");
   Serial.print("Pote3 = ");
 
   Serial.print(pote3Valor);
 Serial.print("\t");
   Serial.print("Pote4 = ");
    Serial.print(pote4Valor);
 Serial.print("\t");
   Serial.print("Pote5 = ");
   Serial.print(pote5Valor);  
  
  Serial.print("\n");
  
}


void leds(){
   digitalWrite(azul, HIGH);
   digitalWrite(verde, HIGH);
   digitalWrite(amarillo, HIGH);
   digitalWrite(rojo, HIGH);
   
   delay(100);
   
   digitalWrite(azul, HIGH);
   digitalWrite(verde, LOW);
   digitalWrite(amarillo, LOW);
   digitalWrite(rojo, LOW);
   
   
   delay(100);
   
   
    digitalWrite(azul, LOW);
   digitalWrite(verde, HIGH);
   digitalWrite(amarillo, LOW);
   digitalWrite(rojo, LOW);
  
    delay(100);
  
   digitalWrite(azul, LOW);
   digitalWrite(verde, LOW);
   digitalWrite(amarillo, HIGH);
   digitalWrite(rojo, LOW);  

  delay(100);

  digitalWrite(azul, LOW);
   digitalWrite(verde, LOW);
   digitalWrite(amarillo, LOW);
   digitalWrite(rojo, HIGH);

  delay(100);

}


