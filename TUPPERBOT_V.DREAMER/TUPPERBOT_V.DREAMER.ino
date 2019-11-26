#include <Servo.h>
Servo servoIzq;
Servo servoDer; 
int equilibrioIzq=86; 
int equilibrioDer=84;
//Funciones de direccion  
void delante()
{
  servoDer.write(10);
  servoIzq.write(170); 
}
void atras ()
{
  servoDer.write(170);
  servoIzq.write(10);
}
void derecha ()
{
  servoDer.write(180);
  servoIzq.write(180);
}
void izquierda ()
{
  servoDer.write(0);
  servoIzq.write(0);
}
void para ()
{
  servoDer.write(equilibrioDer);
  servoIzq.write(equilibrioIzq);
}


void setup() {
  //creacion servos
  servoIzq.attach(9);
  servoDer.attach(10);
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  para();
}

void loop() {

  // Comprueba que hay cadena nueva
  if (Serial.available() > 0) {

    char c = Serial.read();
    delay(2);
    
    switch(c)
    {
      case 'a':
        izquierda();
      break;

      case 'w':
        delante();
      break;
        
      case 'd':
        derecha();
      break;

      case 's':
        atras();
      break;

      case 'm':               
        equilibrioDer++; 
        break; 

      case 'n':
        equilibrioDer--; 
        break;

      case 'b':
        equilibrioIzq++; 
        break; 

      case 'v':
        equilibrioIzq--; 
        break;

        
      default:
        para();
      break;
    }
  } 
}
