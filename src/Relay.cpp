#include "Relay.h"
#include "Pins.h"

RelayManager Relay;

void RelayManager::begin() {
    pinMode(PIN_RELAY_WASHER, OUTPUT);
    digitalWrite(PIN_RELAY_WASHER, LOW); // Assume lógica ativa em HIGH. Mude para HIGH se for relé invertido.
}

void RelayManager::update() {
    // Lógica contínua de proteção de hardware pode ir aqui (ex: timeout de segurança)
}

void RelayManager::turnOnWasher() {
    digitalWrite(PIN_RELAY_WASHER, HIGH);
    Serial.println("Rele: Lavadora LIGADA");
}

void RelayManager::turnOffWasher() {
    digitalWrite(PIN_RELAY_WASHER, LOW);
    Serial.println("Rele: Lavadora DESLIGADA");
}