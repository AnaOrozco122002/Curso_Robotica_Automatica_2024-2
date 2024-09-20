//Motores
const byte MotorA[]={23,22};
const byte MotorB[]={33,32};

//PWM
const uint16_t Frecuencia=5000;
const byte Resolucion = 10;
const byte Canales[] = {0,1,2,3};

void setup() {
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
  //Motor A
  ledcWrite(Canales[0],1000);
  ledcWrite(Canales[1],0);
  //Motor B
  ledcWrite(Canales[2],1000);
  ledcWrite(Canales[3],0);

  delay(5000);

  //Motor A
  ledcWrite(Canales[0],0);
  ledcWrite(Canales[1],1000);
  //Motor B
  ledcWrite(Canales[2],0);
  ledcWrite(Canales[3],1000);

  delay(5000);

  //Motor A
  ledcWrite(Canales[0],0);
  ledcWrite(Canales[1],0);
  //Motor B
  ledcWrite(Canales[2],0);
  ledcWrite(Canales[3],0);

  delay(5000);

}
