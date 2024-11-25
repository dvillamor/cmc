bool isAbsolutePositioning = true; // Modo de posicionamiento por defecto

void g90() {
    isAbsolutePositioning = true; // Establecer a modo absoluto
}

void g91() {
    isAbsolutePositioning = false; // Establecer a modo relativo
}