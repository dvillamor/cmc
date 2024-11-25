#include "../movimientos/MovimientoBase.h" // Asegúrate de incluir los encabezados necesarios

void g6(String command) {
    int targetSteps = 0; // Pasos a mover
    char axis = ' '; // Eje a mover (X, Y, Z)

    // Analizar la cadena de comandos
    int index = 0;
    while (index < command.length()) {
        char c = command.charAt(index);
        if (c == 'X' || c == 'Y' || c == 'Z') {
            axis = c;
            index++;
            String stepsStr = "";
            while (index < command.length() && isDigit(command.charAt(index))) {
                stepsStr += command.charAt(index);
                index++;
            }
            targetSteps = stepsStr.toInt(); // Convertir la cadena a un número
        } else {
            index++;
        }
    }

    // Mover el motor según el eje
    switch (axis) {
        case 'X':
            moveMotor(stepPinA, dirPinA, currentStepsA, currentStepsA + targetSteps);
            currentStepsA += targetSteps; // Actualizar posición actual
            break;
        case 'Y':
            moveMotor(stepPinB, dirPinB, currentStepsB, currentStepsB + targetSteps);
            currentStepsB += targetSteps; // Actualizar posición actual
            break;
        case 'Z':
            moveMotor(stepPinC, dirPinC, currentStepsC, currentStepsC + targetSteps);
            currentStepsC += targetSteps; // Actualizar posición actual
            break;
        default:
            // Manejar el caso de un eje no válido
            Serial.println("Eje no válido para G6");
            break;
    }
}
