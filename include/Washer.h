#ifndef WASHER_H
#define WASHER_H

#include <Arduino.h>

class WasherMachine {
public:
    void begin();
    void update();
    void startCycle();
    
private:
    enum State { IDLE, RUNNING, PAUSED, FINISHED };
    State currentState = IDLE;
    
    uint32_t cycleStartTime = 0;
};

extern WasherMachine WasherController;

#endif