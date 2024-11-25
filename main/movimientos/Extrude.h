#include "MovimientoBase.h"

void extrude(float distance) {
    // Calcular el número de pasos necesarios para la extrusión
    int steps = distance * stepsPerMME; // Convertir distancia en mm a pasos
    int currentStepsE = 0; // Posición actual del motor de extrusión

    // Determinar dirección y mover el motor
    if (steps > 0) {
        // Mover hacia adelante
        moveMotor(stepPinE, dirPinE, currentStepsE, currentStepsE + steps);
    } else {
        // Mover hacia atrás
        moveMotor(stepPinE, dirPinE, currentStepsE, currentStepsE + steps);
    }

    // Actualizar la posición actual
    currentStepsE += steps; // Actualiza la posición actual del motor de extrusión
}