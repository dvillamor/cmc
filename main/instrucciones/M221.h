void m221(String command) {
    // Analizar el comando para obtener el nuevo porcentaje de flujo
    float newFlowPercentage = 0.0;
    bool hasFlowPercentage = false;

    int index = 0;
    while (index < command.length()) {
        char c = command.charAt(index);
        if (c == 'S') { // Se espera que el porcentaje venga después de 'S'
            index++;
            String value = "";
            while (index < command.length() && isDigit(command.charAt(index))) {
                value += command.charAt(index);
                index++;
            }
            newFlowPercentage = value.toFloat();
            hasFlowPercentage = true;
        } else {
            index++;
        }
    }

    // Si se proporciona un nuevo porcentaje, actualízalo
    if (hasFlowPercentage) {
        flowPercentage = newFlowPercentage;
        Serial.print("Nuevo porcentaje de flujo: ");
        Serial.println(flowPercentage);
    } else {
        Serial.println("No se proporcionó un nuevo porcentaje de flujo.");
    }
}