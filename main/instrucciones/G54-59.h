#include "../movimientos/MovimientoBase.h"

// Definición de estructuras para almacenar las coordenadas de cada sistema
struct CoordinateSystem {
    float x;
    float y;
    float z;
};

// Variables para almacenar las coordenadas de los sistemas G54 a G59
CoordinateSystem g54 = {0, 0, 0};
CoordinateSystem g55 = {0, 0, 0};
CoordinateSystem g56 = {0, 0, 0};
CoordinateSystem g57 = {0, 0, 0};
CoordinateSystem g58 = {0, 0, 0};
CoordinateSystem g59 = {0, 0, 0};

CoordinateSystem* currentCoordinateSystem = &g54; // Establece G54 como sistema de coordenadas actual

void g54_g59(String command) {
    char gCode = command.charAt(3); // Obtener el código de sistema (4to carácter)

    // Leer coordenadas del comando
    float targetX = currentCoordinateSystem->x;
    float targetY = currentCoordinateSystem->y;
    float targetZ = currentCoordinateSystem->z;

    // Analizar la cadena de comandos
    int index = 4; // Comenzar después de "G54" o "G55"...
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

    // Actualizar el sistema de coordenadas seleccionado
    switch (gCode) {
        case '4': // G54
            g54.x = targetX;
            g54.y = targetY;
            g54.z = targetZ;
            currentCoordinateSystem = &g54;
            break;
        case '5': // G55
            g55.x = targetX;
            g55.y = targetY;
            g55.z = targetZ;
            currentCoordinateSystem = &g55;
            break;
        case '6': // G56
            g56.x = targetX;
            g56.y = targetY;
            g56.z = targetZ;
            currentCoordinateSystem = &g56;
            break;
        case '7': // G57
            g57.x = targetX;
            g57.y = targetY;
            g57.z = targetZ;
            currentCoordinateSystem = &g57;
            break;
        case '8': // G58
            g58.x = targetX;
            g58.y = targetY;
            g58.z = targetZ;
            currentCoordinateSystem = &g58;
            break;
        case '9': // G59
            g59.x = targetX;
            g59.y = targetY;
            g59.z = targetZ;
            currentCoordinateSystem = &g59;
            break;
    }
}