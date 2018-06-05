#include <Servo.h>  //libreria utilizada para el servo
#include <LiquidCrystal.h> //libreria utilizada para la pantalla LCD

#define IN1  11 //definimos el pin 11 para el motor a pasos
#define IN2  10 //definimos el pin 10 para el motor a pasos
#define IN3  9  //definimos el pin 9 para el motor a pasos
#define IN4  8  //definimos el pin 8 para el motor a pasos

// ------- variables --------
LiquidCrystal lcd(12,7,13,6,14,2); //pines asignados a la LCD

int input;
int Paso [ 8 ][ 4 ] =  //establecemos la secuencia del motor a pasos
{ {1, 0, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 0, 0, 1},
  {1, 0, 0, 1}
};
int pos = 0;    // variable de la posicion del servo
int posicion = 0; // posicion de los servo 1 
int posicion2 = 0; // posicion de los servo 2 
int posicion3 = 0; // posicion de los servo 3 
int steps_left = 4095; 
boolean Direction = true;
int Steps = 0;     // Define el paso actual de la secuencia

Servo myservo;  // crear un objeto servo para controlar el servo 1

Servo myservo2;  // crear un objeto servo para controlar el servo 2

Servo myservo3;  // crear un objeto servo para controlar  servo 3


//--------------- SETUP ---------------
void setup(){
  // ---------- PANTALLA --------
 
  pinMode(12, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(2, OUTPUT);
  
  delay(3000); // wait for console opening
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.clear();
  
  
  // ------- motor a pasos -------
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
//  --------- servomotores ----------
  Serial.begin(9600);
  myservo.attach(3);  // attaches the servo on pin 9 to the servo object
    myservo2.attach(4);  // attaches the servo on pin 9 to the servo object
      myservo3.attach(5);  // attaches the servo on pin 9 to the servo object
}

//-------------------- LOOP --------------------
void loop(){
// ---------- servomotor ---------------
 if (Serial.available() > 0) {
      input = Decimal_to_ASCII(Serial.read());

// -------------- Servomotor 1  --------
if(input == 'a'){
    String grados = "";
     do {
      grados = grados + (char)Serial.read();
      //Serial.println(grados);
      delay(5);
     }
     while (Serial.available() > 0);
      lcd.setCursor(14,0);
      lcd.print(grados);
    posicion = grados.toInt();
    myservo.write(posicion);
}
    
  else if ( input == 'b'){
    String grados2 = "";
 do {
      grados2 = grados2 + (char)Serial.read();
      //Serial.println(grados2);
      delay(5);
 }
  while (Serial.available() > 0);  
      lcd.setCursor(5,0);
      lcd.print(grados2);
   posicion2 = grados2.toInt();
    myservo2.write(posicion2);
    
  
  }
  else {
    String grados3 = "";
   do{
      grados3 = grados3 + (char)Serial.read();
      //Serial.println(grados3);
      delay(5);
   } while (Serial.available() > 0);
    
      lcd.setCursor(5,1);
      lcd.print(grados3);
    posicion3 = grados3.toInt();
    myservo3.write(posicion3);
    
  
  
 }
  
// ----------- motor a pasos ------------
  while (steps_left > 0)
  {
    stepper() ;     // Avanza un paso
    steps_left-- ;  // Un paso menos
    delay (1) ;
  }
  delay(300);
  Direction = ! Direction; // Invertimos la direceccion de giro
  steps_left = 4095;
}
 }


//----------- METODO INDEPENDIENTE ( FUERA DEL LOOP PARA CODIGO DE  MENSAJES---------------
char Decimal_to_ASCII(int entrada) {
  char salida = ' ' ;
  switch (entrada) {
    case 32:
      salida = ' ';
      break;
    case 33:
      salida = '!';
      break;
    case 34:
      salida = '"';
      break;
    case 35:
      salida = '#';
      break;
    case 36:
      salida = '$';
      break;
    case 37:
      salida = '%';
      break;
    case 38:
      salida = '&';
      break;
    case 39:
      salida = ' ';
      break;
    case 40:
      salida = '(';
      break;
    case 41:
      salida = ')';
      break;
    case 42:
      salida = '*';
      break;
    case 43:
      salida = '+';
      break;
    case 44:
      salida = ',';
      break;
    case 45:
      salida = '-';
      break;
    case 46:
      salida = '.';
      break;
    case 47:
      salida = '/';
      break;
    case 48:
      salida = '0';
      break;
    case 49:
      salida = '1';
      break;
    case 50:
      salida = '2';
      break;
    case 51:
      salida = '3';
      break;
    case 52:
      salida = '4';
      break;
    case 53:
      salida = '5';
      break;
    case 54:
      salida = '6';
      break;
    case 55:
      salida = '7';
      break;
    case 56:
      salida = '8';
      break;
    case 57:
      salida = '9';
      break;
    case 58:
      salida = ':';
      break;
    case 59:
      salida = ';';
      break;
    case 60:
      salida = '<';
      break;
    case 61:
      salida = '=';
      break;
    case 62:
      salida = '>';
      break;
    case 63:
      salida = '?';
      break;
    case 64:
      salida = '@';
      break;
    case 65:
      salida = 'A';
      break;
    case 66:
      salida = 'B';
      break;
    case 67:
      salida = 'C';
      break;
    case 68:
      salida = 'D';
      break;
    case 69:
      salida = 'E';
      break;
    case 70:
      salida = 'F';
      break;
    case 71:
      salida = 'G';
      break;
    case 72:
      salida = 'H';
      break;
    case 73:
      salida = 'I';
      break;
    case 74:
      salida = 'J';
      break;
    case 75:
      salida = 'K';
      break;
    case 76:
      salida = 'L';
      break;
    case 77:
      salida = 'M';
      break;
    case 78:
      salida = 'N';
      break;
    case 79:
      salida = 'O';
      break;
    case 80:
      salida = 'P';
      break;
    case 81:
      salida = 'Q';
      break;
    case 82:
      salida = 'R';
      break;
    case 83:
      salida = 'S';
      break;
    case 84:
      salida = 'T';
      break;
    case 85:
      salida = 'U';
      break;
    case 86:
      salida = 'V';
      break;
    case 87:
      salida = 'W';
      break;
    case 88:
      salida = 'X';
      break;
    case 89:
      salida = 'Y';
      break;
    case 90:
      salida = 'Z';
      break;
    case 91:
      salida = '[';
      break;
    case 92:
      salida = ' ';
      break;
    case 93:
      salida = ']';
      break;
    case 94:
      salida = '^';
      break;
    case 95:
      salida = '_';
      break;
    case 96:
      salida = '`';
      break;
    case 97:
      salida = 'a';
      break;
    case 98:
      salida = 'b';
      break;
    case 99:
      salida = 'c';
      break;
    case 100:
      salida = 'd';
      break;
    case 101:
      salida = 'e';
      break;
    case 102:
      salida = 'f';
      break;
    case 103:
      salida = 'g';
      break;
    case 104:
      salida = 'h';
      break;
    case 105:
      salida = 'i';
      break;
    case 106:
      salida = 'j';
      break;
    case 107:
      salida = 'k';
      break;
    case 108:
      salida = 'l';
      break;
    case 109:
      salida = 'm';
      break;
    case 110:
      salida = 'n';
      break;
    case 111:
      salida = 'o';
      break;
    case 112:
      salida = 'p';
      break;
    case 113:
      salida = 'q';
      break;
    case 114:
      salida = 'r';
      break;
    case 115:
      salida = 's';
      break;
    case 116:
      salida = 't';
      break;
    case 117:
      salida = 'u';
      break;
    case 118:
      salida = 'v';
      break;
    case 119:
      salida = 'w';
      break;
    case 120:
      salida = 'x';
      break;
    case 121:
      salida = 'y';
      break;
    case 122:
      salida = 'z';
      break;
    case 123:
      salida = '{';
      break;
    case 124:
      salida = '|';
      break;
    case 125:
      salida = '}';
      break;
    case 126:
      salida = '~';
      break;
  }
  return salida;
}


// ------------------ METODOS -------------------

void stepper()            //Avanza un paso
{
  digitalWrite( IN1, Paso[Steps][ 0] );
  digitalWrite( IN2, Paso[Steps][ 1] );
  digitalWrite( IN3, Paso[Steps][ 2] );
  digitalWrite( IN4, Paso[Steps][ 3] );

  SetDirection();
}

void SetDirection()
{
  if (Direction)
    Steps++;
  else
    Steps--;

  Steps = ( Steps + 8 ) % 8 ;
}

