#ifndef MOVIMIENTOBAS_H
#define MOVIMIENTOBAS_H

// Función para mover un motor paso a paso desde la posición actual a la nueva

void moveMotor(int stepPin, int dirPin, int currentSteps, int newSteps) {
  int steps = newSteps - currentSteps;

  if (steps > 0) {
    digitalWrite(dirPin, HIGH); // Mover hacia adelante
  } else {
    digitalWrite(dirPin, LOW); // Mover hacia atrás
    steps = -steps; // Convertir a positivo
  }

  for (int i = 0; i < steps; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(stepDelayMicroseconds / 2); // Controlar la velocidad
    digitalWrite(stepPin, LOW);
    delayMicroseconds(stepDelayMicroseconds / 2);
  }
}

// Implementación de la cinemática inversa para el motor A
int calculateMotorA(float x, float y, float z) {
  // Calcular la distancia de la base del motor A a la posición (x, y, z)
  float distanceA = sqrt(x * x + y * y + (h - z) * (h - z)) - L;

  // Convertir la distancia a pasos de motor
  int stepsA = (int)(distanceA * stepsPerMMA);

  return stepsA;
}

// Implementación de la cinemática inversa para el motor B
int calculateMotorB(float x, float y, float z) {
  // Calcular la distancia de la base del motor B a la posición (x, y, z)
  float distanceB = sqrt((xmax - x) * (xmax - x) + y * y + (h - z) * (h - z)) - L;

  // Convertir la distancia a pasos de motor
  int stepsB = (int)(distanceB * stepsPerMMB);

  return stepsB;
}

// Implementación de la cinemática inversa para el motor C
int calculateMotorC(float x, float y, float z) {
  // Calcular la distancia de la base del motor C a la posición (x, y, z)
  float distanceC = sqrt(((xmax / 2) - x) * ((xmax / 2) - x) + (d - y) * (d - y) + (h - z) * (h - z)) - L;

  // Convertir la distancia a pasos de motor
  int stepsC = (int)(distanceC * stepsPerMMC);

  return stepsC;
}

#endif // MOVIMIENTOBAS_H