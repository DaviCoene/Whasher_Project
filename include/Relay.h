#ifndef RELAY_H
#define RELAY_H

#include <Arduino.h>

class RelayManager {
public:
    void begin();
    void update();
    void turnOnWasher();
    void turnOffWasher();
    // Métodos para o Dryer podem ser adicionados aqui futuramente
};

extern RelayManager Relay;

#endif