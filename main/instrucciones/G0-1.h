#include "../movimientos/MovimientoLineal.h"
// Verificar si es un comando G0 o G1
void g0_1(String command) {
    float targetX = currentX; // Valor por defecto en modo absoluto
    float targetY = currentY; // Valor por defecto en modo absoluto
    float targetZ = currentZ; // Valor por defecto en modo absoluto
    bool hasX = false, hasY = false, hasZ = false;

    // Analizar la cadena de comandos
    int index = 0;
    while (index < command.length()) {
        char c = command.charAt(index);
        if (c == 'X') {
            index++;
            String value = "";
            while (index < command.length() && isDigit(command.charAt(index))) {
                value += command.charAt(index);
                index++;
            }
            targetX = isAbsolutePositioning ? value.toFloat() : currentX + value.toFloat(); // Ajuste para modo relativo
            hasX = true;
        } else if (c == 'Y') {
            index++;
            String value = "";
            while (index < command.length() && isDigit(command.charAt(index))) {
                value += command.charAt(index);
                index++;
            }
            targetY = isAbsolutePositioning ? value.toFloat() : currentY + value.toFloat(); // Ajuste para modo relativo
            hasY = true;
        } else if (c == 'Z') {
            index++;
            String value = "";
            while (index < command.length() && isDigit(command.charAt(index))) {
                value += command.charAt(index);
                index++;
            }
            targetZ = isAbsolutePositioning ? value.toFloat() : currentZ + value.toFloat(); // Ajuste para modo relativo
            hasZ = true;
        } else {
            index++;
        }
    }

    // Validar las posiciones antes de mover
    if (isnan(targetX) || isnan(targetY) || isnan(targetZ)) {
        Serial.println("Error: coordenadas no válidas.");
        return;
    }

    // Si al menos una coordenada está definida, mover
    if (hasX || hasY || hasZ) {
        moveToPosition(targetX, targetY, targetZ, 100); // Ajusta el número de pasos
    }
}