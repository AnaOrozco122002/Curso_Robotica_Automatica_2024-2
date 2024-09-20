#include "BluetoothSerial.h"

String Nombre = "Curso";

BluetoothSerial SerialBT;

String Variable = "";

//Motores
const byte MotorA[]={23,22};
const byte MotorB[]={33,32};

//PWM
const uint16_t Frecuencia=5000;
const byte Resolucion = 10;
const byte Canales[] = {0,1,2,3};

void setup() {

  //Bluetooth
  Serial.begin(115200);
  SerialBT.begin(Nombre);

  // Inicializar Pines
  pinMode(MotorA[0],OUTPUT);
  pinMode(MotorA[1],OUTPUT);
  pinMode(MotorB[0],OUTPUT);
  pinMode(MotorB[1],OUTPUT);

  //PWM
  ledcSetup(Canales[0],Frecuencia,Resolucion);
  ledcSetup(Canales[1],Frecuencia,Resolucion);
  ledcSetup(Canales[2],Frecuencia,Resolucion);
  ledcSetup(Canales[3],Frecuencia,Resolucion);
  ledcAttachPin(MotorA[0],Canales[0]);
  ledcAttachPin(MotorA[1],Canales[1]);
  ledcAttachPin(MotorB[0],Canales[2]);
  ledcAttachPin(MotorB[1],Canales[3]);
}

void loop() {

  if (SerialBT.available()) {
    //Obtención de la variable
    char receivedChar = (char)SerialBT.read();
    Variable = "";
    Variable += receivedChar;

    Serial.println(Variable);
  }


}
