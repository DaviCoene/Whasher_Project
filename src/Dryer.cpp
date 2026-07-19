#include "Dryer.h"
#include "Relay.h"
#include "Sensors.h"
#include "Config.h"

DryerMachine DryerController;

void DryerMachine::begin() {
    currentState = IDLE;
}

void DryerMachine::startCycle() {
    // Assumindo que a secadora também tenha um sensor de porta no futuro
    if (currentState == IDLE /* && Sensor.isDryerDoorClosed() */) {
        currentState = RUNNING;
        cycleStartTime = millis();
        // Relay.turnOnDryer(); // Descomente quando implementar no Relay.cpp
        Serial.println("Dryer: Ciclo Iniciado.");
    }
}

void DryerMachine::update() {
    switch (currentState) {
        case IDLE:
            break;

        case RUNNING:
            // Simulação de término de ciclo usando a mesma constante da lavadora (ou crie uma DRYER_CYCLE_TIME no Config.h)
            if (millis() - cycleStartTime >= WASHER_CYCLE_TIME) {
                // Relay.turnOffDryer();
                currentState = FINISHED;
                Serial.println("Dryer: Ciclo Finalizado.");
            }
            break;

        case PAUSED:
            // Lógica de pausa
            break;

        case FINISHED:
            currentState = IDLE;
            break;
    }
}