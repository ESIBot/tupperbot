#include <Servo.h>
#include <EEPROM.h>

Servo servoIzq;
Servo servoDer; 

byte paraI;
byte paraD;
bool laser = false;

//Funciones de direccion  
void delante()
{
  servoDer.write(0);
  servoIzq.write(180); 
}
void atras ()
{
  servoDer.write(180);
  servoIzq.write(0);
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
  servoDer.write(paraD);
  servoIzq.write(paraI);
}

void setup() {
  paraI = EEPROM.read(0);
  paraD = EEPROM.read(1);
  //creacion servos
  servoIzq.attach(9);
  servoDer.attach(10);
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  pinMode(8, OUTPUT);
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

      case 'o': //Aumenta
        paraI++;
        EEPROM.update(0, paraI);
        para();
      break;

      case 'i':
        paraI--;
        EEPROM.update(0, paraI);
        para();
      break;

      case 'l': //Aumenta
        paraD++;
        EEPROM.update(1, paraD);
        para();
      break;

      case 'k':
        paraD--;
        EEPROM.update(1, paraD);
        para();
      break;

      case 'm':
        Serial.print("Izq: ");
        Serial.println(paraI);
        Serial.print("Der: ");
        Serial.println(paraD);
        para();
      break;

      case 't':
        if(!laser)
        {
          digitalWrite(8, HIGH);
          laser = true;
        }
        else
        {
          digitalWrite(8, LOW);
          laser = false;
        }
      break;

      default:
        para();
      break;
    }
  } 
}
