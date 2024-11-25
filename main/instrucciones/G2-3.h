#include "../movimientos/MovimientoCircular.h"

void g2_g3(String command) {
  float targetX = 0, targetY = 0, targetZ = 0;
  float centerX = 0, centerY = 0; // Centro del arco
  float radius = 0; // Radio del arco
  bool isG2 = command.startsWith("G2"); // Determina si es G2 o G3

  // Analizar la cadena de comandos
  int index = 0;
  while (index < command.length()) {
    char c = command.charAt(index);
    if (c == 'X') {
      index++;
      while (index < command.length() && isDigit(command.charAt(index))) {
        targetX = command.substring(index, index + 1).toFloat();
        index++;
      }
    } else if (c == 'Y') {
      index++;
      while (index < command.length() && isDigit(command.charAt(index))) {
        targetY = command.substring(index, index + 1).toFloat();
        index++;
      }
    } else if (c == 'Z') {
      index++;
      while (index < command.length() && isDigit(command.charAt(index))) {
        targetZ = command.substring(index, index + 1).toFloat();
        index++;
      }
    } else if (c == 'I') {
      index++;
      while (index < command.length() && isDigit(command.charAt(index))) {
        centerX = command.substring(index, index + 1).toFloat();
        index++;
      }
    } else if (c == 'J') {
      index++;
      while (index < command.length() && isDigit(command.charAt(index))) {
        centerY = command.substring(index, index + 1).toFloat();
        index++;
      }
    } else {
      index++;
    }
  }

  // Aplicar la lógica de posicionamiento
  float finalX = isAbsolutePositioning ? targetX : currentX + targetX; // Ajustar según el modo
  float finalY = isAbsolutePositioning ? targetY : currentY + targetY; // Ajustar según el modo

  MoveCircular(centerX, centerY, isG2);
  
}