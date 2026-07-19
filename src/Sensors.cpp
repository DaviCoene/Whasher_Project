#include "Sensors.h"
#include "Pins.h"

SensorManager Sensor;

void SensorManager::begin() {
    pinMode(PIN_SENSOR_WASHER, INPUT_PULLUP);
}

void SensorManager::update() {
    // Leitura não-bloqueante com debounce simples
    bool reading = !digitalRead(PIN_SENSOR_WASHER); // Invertido devido ao INPUT_PULLUP
    
    if (millis() - lastDebounceTime > debounceDelay) {
        if (reading != washerDoorState) {
            washerDoorState = reading;
            lastDebounceTime = millis();
        }
    }
}

bool SensorManager::isWasherDoorClosed() {
    return washerDoorState;
}