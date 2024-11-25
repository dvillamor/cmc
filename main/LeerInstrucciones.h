#include "instrucciones/G90-91.h"
#include "instrucciones/M82-83.h"

#include "instrucciones/G0-1.h"
#include "instrucciones/G2-3.h"
#include "instrucciones/G6.h"
#include "instrucciones/G53.h"
#include "instrucciones/G54-59.h"

#include "instrucciones/M200.h"
#include "instrucciones/M221.h"
#include "instrucciones/M3-5.h"

void leerInstrucciones() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n'); // Leer hasta nueva línea
    command.trim(); // Eliminar espacios en blanco

    if (command.startsWith("G0") || command.startsWith("G1")) {
      g0_1(command);
    } else if (command.startsWith("G2") || command.startsWith("G3")) {
      g2_g3(command);
    } else if (command.startsWith("G6")) {
      g6(command);
    } else if (command.startsWith("G53")) {
      g53(command);
    } else if (command.startsWith("G54") || command.startsWith("G55") ||
               command.startsWith("G56") || command.startsWith("G57") ||
               command.startsWith("G58") || command.startsWith("G59") ||
               command.startsWith("G59.1") || command.startsWith("G59.2") ||
               command.startsWith("G59.3")) {
      g54_g59(command);
    } else if (command.startsWith("G90")) {
      g90();
    } else if (command.startsWith("G91")) {
      g91();
    } else if (command.startsWith("M82")) {
      m82();
    } else if (command.startsWith("M83")) {
      m83();
    } else if (command.startsWith("M200")) {
      m200(command);
    } else if (command.startsWith("M221")) {
      m221(command);
    } else if (command.startsWith("M3")) {
      m3();
    } else if (command.startsWith("M4")) {
      m4();
    } else if (command.startsWith("M5")) {
      m5();
    } else {
      Serial.println("Comando no reconocido: "+command);
    }
  }
}
