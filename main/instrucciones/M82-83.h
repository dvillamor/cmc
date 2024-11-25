bool isAbsoluteExtrusion = true; // Modo de extrusión inicial en absoluto

void m82() {
    isAbsoluteExtrusion = true; // Cambia a modo de extrusión absoluta
    Serial.println("Modo de extrusión establecido en absoluto (M82)");
}

void m83() {
    isAbsoluteExtrusion = false; // Cambia a modo de extrusión relativa
    Serial.println("Modo de extrusión establecido en relativo (M83)");
}