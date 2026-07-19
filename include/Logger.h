#ifndef LOGGER_H
#define LOGGER_H

#include <Arduino.h>

class LoggerSystem {
public:
    void begin(unsigned long baudRate = 115200);
    void info(const char* message);
    void error(const char* message);
};

extern LoggerSystem Logger;

#endif