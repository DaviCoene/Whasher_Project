#include "Washer.h"
#include "Relay.h"
#include "Sensors.h"
#include "Config.h"

WasherMachine WasherController;

void WasherMachine::begin() {
    currentState = IDLE;
}

void WasherMachine::startCycle() {
    if (currentState == IDLE && Sensor.isWasherDoorClosed()) {
        currentState = RUNNING;
        cycleStartTime = millis();
        Relay.turnOnWasher();
        Serial.println("Washer: Ciclo Iniciado.");
    } else {
        Serial.println("Washer: Feche a porta para iniciar.");
    }
}

void WasherMachine::update() {
    switch (currentState) {
        case IDLE:
            // Aguardando comando para iniciar
            break;

        case RUNNING:
            // Se a porta abrir no meio do processo, pausa por segurança
            if (!Sensor.isWasherDoorClosed()) {
                Relay.turnOffWasher();
                currentState = PAUSED;
                Serial.println("Washer: PAUSADO (Porta Aberta)");
            }
            
            // Verifica se o tempo do ciclo acabou
            if (millis() - cycleStartTime >= WASHER_CYCLE_TIME) {
                Relay.turnOffWasher();
                currentState = FINISHED;
                Serial.println("Washer: Ciclo Finalizado.");
            }
            break;

        case PAUSED:
            // Retoma se a porta for fechada
            if (Sensor.isWasherDoorClosed()) {
                Relay.turnOnWasher();
                currentState = RUNNING;
                // Nota: Uma lógica mais avançada ajustaria o cycleStartTime aqui para compensar o tempo pausado
                Serial.println("Washer: RETOMADO");
            }
            break;

        case FINISHED:
            // Retorna ao estado inicial
            currentState = IDLE;
            break;
    }
}