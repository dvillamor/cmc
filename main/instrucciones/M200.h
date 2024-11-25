void m200(String command) {
    // Analizar el comando para obtener el nuevo diámetro
    float newDiameter = 0.0;
    bool hasDiameter = false;

    int index = 0;
    while (index < command.length()) {
        char c = command.charAt(index);
        if (c == 'D') {
            index++;
            String value = "";
            while (index < command.length() && isDigit(command.charAt(index))) {
                value += command.charAt(index);
                index++;
            }
            newDiameter = value.toFloat();
            hasDiameter = true;
        } else {
            index++;
        }
    }

    // Si se proporciona un nuevo diámetro, actualízalo
    if (hasDiameter) {
        volumetricDiameter = newDiameter;
        Serial.print("Nuevo diámetro de extrusión: ");
        Serial.println(volumetricDiameter);
    } else {
        Serial.println("No se proporcionó un nuevo diámetro.");
    }
}