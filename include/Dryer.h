#ifndef DRYER_H
#define DRYER_H

#include <Arduino.h>

class DryerMachine {
public:
    void begin();
    void update();
    void startCycle();
    
private:
    enum State { IDLE, RUNNING, PAUSED, FINISHED };
    State currentState = IDLE;
    
    uint32_t cycleStartTime = 0;
};

extern DryerMachine DryerController;

#endif