void m3() {
    digitalWrite(spindlePinB, LOW);
    delay(100);
    digitalWrite(spindlePinA, HIGH); // Encender el husillo/láser
    Serial.println("Husillo/Láser encendido.");
}

void m4() {
    digitalWrite(spindlePinA, LOW); // Encender el husillo/láser (sentido antihorario)
    delay(100);
    digitalWrite(spindlePinB, HIGH);
    Serial.println("Husillo/Láser encendido en sentido antihorario.");
}

void m5() {
    digitalWrite(spindlePinA, LOW); // Apagar el husillo/láser
    digitalWrite(spindlePinB, LOW);
    Serial.println("Husillo/Láser apagado.");
}