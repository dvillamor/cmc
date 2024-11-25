#include "MovimientoBase.h"

void MoveCircular(int centerX, int centerY, bool isG2){
        // Calcular el radio
    float radius = sqrt(pow((currentX + centerX), 2) + pow((currentY + centerY), 2));

    // Lógica para movimiento en arco
    int steps = 100; // Número de pasos para la interpolación
    for (int i = 0; i <= steps; i++) {
        float t = (float)i / (float)steps; // Proporción de movimiento
        float angle = t * (isG2 ? 1 : -1) * (M_PI / 2); // Ángulo en radianes (ajustar según el arco)

        float newX = centerX + radius * cos(angle);
        float newY = centerY + radius * sin(angle);
        
        // Actualizar la posición actual
        currentX = newX;
        currentY = newY;

        // Calcular los nuevos pasos para los motores
        int newStepsA = calculateMotorA(currentX, currentY, currentZ);
        int newStepsB = calculateMotorB(currentX, currentY, currentZ);
        int newStepsC = calculateMotorC(currentX, currentY, currentZ);

        // Mover los motores a las nuevas posiciones
        moveMotor(stepPinA, dirPinA, currentStepsA, newStepsA);
        moveMotor(stepPinB, dirPinB, currentStepsB, newStepsB);
        moveMotor(stepPinC, dirPinC, currentStepsC, newStepsC);
    }
}