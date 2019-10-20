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
float pote1ValorWP, pote2ValorWP, pote3ValorWP, pote4ValorWP, pote5ValorWP; 
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
  
//  void imprimirValoresSinProcesarPotenciometros(pote1ValorWP, pote2ValorWP, pote3ValorWP, pote4ValorWP, pote5ValorWP);
  
  Joystick.begin();
  
}


void loop(){
    //Leemos valor del Pote 1 (Girar izquierda Derecha); 
   
    pote1ValorWP = analogRead(pote1);
 
    //Variable División, almacena una constante necesaria para convertir a la escala adecuada
    division = 0.248046875; 

 
    pote1Valor = ((pote1ValorWP*division)-127);
      
    Joystick.setXAxis(pote1Valor);

    //Acaban de ser seteados los valores del axis X o eje x 
      
   
    pote2ValorWP = analogRead(pote2);

    pote2Valor = ((pote2ValorWP*division)-127);

    Joystick.setYAxis(pote2Valor);

    //Se setean los valores de axis Y 
    
    pote3ValorWP = analogRead(pote3);

    pote3Valor = ((pote3ValorWP*division));

    Joystick.setThrottle(pote3Valor);
  
    //Se setea el acelerador "Throttle" Con el valor del pote 3 luego de ser convertido a escala 0-254
    

    pote4ValorWP = analogRead(pote4);

    pote4Valor = ((pote4ValorWP*division));

    Joystick.setRudder(pote4Valor);
    
    //Se setea el timon "Rudder" con el valor del pote4 tambin con una escala 0-254
      
    
    pote5ValorWP = analogRead(pote5);
    pote5Valor = ((pote5ValorWP*division)-127);
    Joystick.setZAxis(pote5Valor);

    //Se setea el eje Z con el valor de pote5 que trabajara con una escala -127 a +127 y es el temita de FLAPS 
   
  if(digitalRead(0) != previo ){
    Joystick.setButton(3, 1);
    delay(50);
    Joystick.setButton(3, 0);
    previo = !previo;  
  }

  //Esto setea el boton 3, se utiliza luego en el simulador como 4 y significa NO FUMAR SIGNALLE 
  
  previo = digitalRead(0);
  
  //La variable previo esta guardando el valor anterior de la lectura, para siempre setear "boton apretado" cuando la lectura nueva signifique una variacion con respecto a la anterior. 
  
  if(digitalRead(1) != previo1 ){
    Joystick.setButton(2, 1);
    delay(50);
    Joystick.setButton(2, 0);
    previo1 = !previo1;  
  }

  previo1 = digitalRead(1);
  
//Vamos a tener que hacer lo mismo pero con todos los botones que se utilicen.     



 
//  imprimirValoresSinProcesarPotenciometros(pote1ValorWP,pote2ValorWP,pote3ValorWP,pote4ValorWP,pote5ValorWP);
  
  
  
  
  
  
  
  
}
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
//  void imprimirValoresSinProcesarPotenciometros(pote1ValorWP, pote2ValorWP, pote3ValorWP, pote4ValorWP, pote5ValorWP){
//    
// 
//   Serial.print("Pote1 = ");
//   Serial.print(pote1ValorWP);
//   Serial.print("\t");
//   Serial.print("Pote2 = ");
//   Serial.print(pote2ValorWP);
//   Serial.print("\t");
//   Serial.print("Pote3 = ");
//   Serial.print(pote3ValorWP);
//   Serial.print("\t");
//   Serial.print("Pote4 = ");
//   Serial.print(pote4ValorWP);
//   Serial.print("\t");
//   Serial.print("Pote5 = ");
//   Serial.print(pote5ValorWP);  
//   Serial.print("\n");
//  
//}


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


