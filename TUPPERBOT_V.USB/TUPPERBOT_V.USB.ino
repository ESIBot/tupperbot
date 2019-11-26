#include <Servo.h>

Servo servoIzq;
Servo servoDer; 

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
  servoDer.write(98);
  servoIzq.write(80);
}

//Creación cadena
String inputString = "";         // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete

void setup() {
  //creacion servos
  servoIzq.attach(9);
  servoDer.attach(10);
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
  para();
}

void loop() {

  // Comprueba que hay cadena nueva
  if (stringComplete) {
    Serial.println(inputString); //Imprime la cadena
    
    if(inputString.charAt(0) == 'a')
      izquierda ();
    else if(inputString.charAt(0) == 'd')
      derecha(); 
    else  if (inputString.charAt(0) == 'w')
        delante();
     else if (inputString.charAt(0) == 's')
        atras();
     else if (inputString.charAt(0) == 'p')
        para ();
    
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
  
}

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
