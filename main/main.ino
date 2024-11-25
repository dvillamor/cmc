// Configuraciones y parámetros generales
const float h = 42;         // Altura del eje Z
const float L = 90;         // Longitud del brazo (en milímetros)
const float xmax = 40;      // Máximo valor de X (ajusta según tu impresora)
const float d = (sqrt(3) / 2) * xmax; // Anclaje motor C

// Pines de control para los motores paso a paso
const int stepPinA = 2;
const int dirPinA = 3;
const int stepsPerMMA = 10;

const int stepPinB = 4;
const int dirPinB = 5;
const int stepsPerMMB = 10;

const int stepPinC = 6;
const int dirPinC = 7;
const int stepsPerMMC = 10;

const int stepPinE = 8;
const int dirPinE = 9;
const int stepsPerMME = 10; // Pasos por milímetro para extrusión/corte

const int spindlePinA = 10; // Pin para controlar el husillo/láser
const int spindlePinB = 11; // Pin para controlar el husillo/láser

// Posición actual en coordenadas cartesianas
float currentX = 0, currentY = 0, currentZ = 0;
// Variables de los motores (posiciones actuales de A, B, C)
int currentStepsA = 0, currentStepsB = 0, currentStepsC = 0;

// Velocidad deseada en mm/min (ajusta según tu necesidad)
float velocidad = 120; // Velocidad de corte/extrusión en mm/min
// Calcula el tiempo entre pasos en microsegundos
unsigned long stepDelayMicroseconds;
float volumetricDiameter = 1.75; // Valor predeterminado, ajustar según sea necesario
float flowPercentage = 100.0; // Valor predeterminado (100%)

#include "LeerInstrucciones.h" // Contiene la función para leer instrucciones del puerto serie

void setup() {
  // Configurar los pines como salida
  pinMode(stepPinA, OUTPUT);
  pinMode(dirPinA, OUTPUT);
  pinMode(stepPinB, OUTPUT);
  pinMode(dirPinB, OUTPUT);
  pinMode(stepPinC, OUTPUT);
  pinMode(dirPinC, OUTPUT);
  pinMode(stepPinE, OUTPUT);
  pinMode(dirPinE, OUTPUT);
  pinMode(spindlePinA, OUTPUT);
  pinMode(spindlePinB, OUTPUT);
  
  Serial.begin(9600); // Iniciar comunicación serie para depuración

  // Calcular el retraso entre pasos
  stepDelayMicroseconds = (60 * 1000000) / (velocidad * stepsPerMME);
}

void loop() {
  leerInstrucciones(); // Leer e interpretar instrucciones G-code
}