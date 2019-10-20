/* Programa desarrollado para obtener lecturas de potenciómetros y botones y convertirlos en datos para un joystick
 *  Se utiliza la librería Joystick.h 
 */
#include<Joystick.h>

//Potenciómetros 1 al 5 
#define pote0 A0
#define pote1 A1 
#define pote2 A2 
#define pote3 A3 
#define pote4 A4


//Botones 0 al 6 
#define boton0 0
#define boton1 1 
#define boton2 2
#define boton3 3
#define boton4 4 
#define boton5 5 
#define boton6 6 

//Pulsadores 1 y 2 
#define pulsa1 7
#define pulsa2 8

//Donde guardaremos los valores de los potenciómetros (En el array)
float poteValor[4];

const byte  potes[5] = {A0, A1, A2, A3, A4};

//Constantes importantes-  
const float division = 0.248046875; 

//Array que guardará los valores previos de lecturas de botones y también las lecturas postas de botones.
int previo[15]; 
int botonesValores[15]; 
int a = 1;

void setup(){
  pinMode(pote0, INPUT);
  pinMode(pote1, INPUT);
  pinMode(pote2, INPUT);
  pinMode(pote3, INPUT);
  pinMode(pote4, INPUT);

  pinMode(boton0, INPUT);
  pinMode(boton1, INPUT);
  pinMode(boton2, INPUT);
  pinMode(boton3, INPUT);
  pinMode(boton4, INPUT);
  pinMode(boton5, INPUT);
  pinMode(boton6, INPUT);
    
  Serial.begin(9600);
  Joystick.begin();  
}
void loop(){
    while(a<7){
      previo[a] = digitalRead(a);
      a++;
    }
    a = 0;
    
    
   while(a<5){
       poteValor[a] = analogRead(potes[a]);
              
      if((a == 0) || (a == 1) || (a == 4)){
        poteValor[a] = ((poteValor[a] * division)-127);
        
        }//EndIf
      else if((a == 3) || (a == 2)){
        poteValor[a] = (poteValor[a] * division);
      }//EndElseIf
      a++;
    }//EndWhile
    a = 0;
      Joystick.setXAxis(poteValor[1]);
      Joystick.setYAxis(poteValor[2]);
      Joystick.setZAxis(poteValor[5]);
      Joystick.setThrottle(poteValor[3]);
      Joystick.setRudder(poteValor[4]);
      
          
    while(a<7){
      botonesValores[a] = digitalRead(a);
      if (botonesValores[a] != previo[a]){
        Joystick.setButton(a, 1);
        delay(30);
        Joystick.setButton(a, 0);
        previo[a] = !previo[a];
      } //EndIf
      a++;
     }//EndFor
     a=0;
    }//End Loop


