#include "MovimientoBase.h"
// Función para mover paso a paso recalculando la cinemática inversa
void moveToPosition(float targetX, float targetY, float targetZ, int steps) {
  float deltaX = (targetX - currentX) / steps;
  float deltaY = (targetY - currentY) / steps;
  float deltaZ = (targetZ - currentZ) / steps;

  // Para cada paso
  for (int i = 0; i < steps; i++) {
    // Calcular la nueva posición en el espacio cartesiano
    currentX += deltaX;
    currentY += deltaY;
    currentZ += deltaZ;

    // Calcular los nuevos pasos de los motores con las ecuaciones de cinemática inversa
    int newStepsA = calculateMotorA(currentX, currentY, currentZ);
    int newStepsB = calculateMotorB(currentX, currentY, currentZ);
    int newStepsC = calculateMotorC(currentX, currentY, currentZ);

    // Mover los motores a las nuevas posiciones
    moveMotor(stepPinA, dirPinA, currentStepsA, newStepsA);
    moveMotor(stepPinB, dirPinB, currentStepsB, newStepsB);
    moveMotor(stepPinC, dirPinC, currentStepsC, newStepsC);

    // Actualizar las posiciones actuales
    currentStepsA = newStepsA;
    currentStepsB = newStepsB;
    currentStepsC = newStepsC;

    delay(1); // Ajustar el retraso para controlar la velocidad de movimiento
  }
}