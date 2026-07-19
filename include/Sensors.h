#ifndef SENSORS_H
#define SENSORS_H

#include <Arduino.h>

class SensorManager {
public:
    void begin();
    void update();
    bool isWasherDoorClosed();
    
private:
    bool washerDoorState = false;
    uint32_t lastDebounceTime = 0;
    const uint32_t debounceDelay = 50; // 50ms para estabilizar a leitura
};

extern SensorManager Sensor;

#endif