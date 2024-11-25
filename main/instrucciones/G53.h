#include "../movimientos/MovimientoBase.h" // Asegúrate de incluir los encabezados necesarios

void g53(String command) {
    float targetX = 0, targetY = 0, targetZ = 0;

    // Analizar la cadena de comandos
    int index = 0;
    while (index < command.length()) {
        char c = command.charAt(index);
        if (c == 'X') {
            index++;
            String xStr = "";
            while (index < command.length() && (isDigit(command.charAt(index)) || command.charAt(index) == '-')) {
                xStr += command.charAt(index);
                index++;
            }
            targetX = xStr.toFloat(); // Convertir a float
        } else if (c == 'Y') {
            index++;
            String yStr = "";
            while (index < command.length() && (isDigit(command.charAt(index)) || command.charAt(index) == '-')) {
                yStr += command.charAt(index);
                index++;
            }
            targetY = yStr.toFloat(); // Convertir a float
        } else if (c == 'Z') {
            index++;
            String zStr = "";
            while (index < command.length() && (isDigit(command.charAt(index)) || command.charAt(index) == '-')) {
                zStr += command.charAt(index);
                index++;
            }
            targetZ = zStr.toFloat(); // Convertir a float
        } else {
            index++;
        }
    }

    // Mover a las coordenadas de la máquina
    moveMotor(stepPinA, dirPinA, currentStepsA, targetX); // Asumiendo que `targetX` es el número de pasos
    moveMotor(stepPinB, dirPinB, currentStepsB, targetY); // Asumiendo que `targetY` es el número de pasos
    moveMotor(stepPinC, dirPinC, currentStepsC, targetZ); // Asumiendo que `targetZ` es el número de pasos

    // Actualizar las posiciones actuales
    currentStepsA = targetX;
    currentStepsB = targetY;
    currentStepsC = targetZ;
}
