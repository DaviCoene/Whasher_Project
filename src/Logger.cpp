#include "Logger.h"

LoggerSystem Logger;

void LoggerSystem::begin(unsigned long baudRate) {
    Serial.begin(baudRate);
    while (!Serial) {
        ; // Aguarda a porta serial conectar
    }
    info("Sistema de Log Iniciado.");
}

void LoggerSystem::info(const char* message) {
    Serial.print("[INFO] ");
    Serial.println(message);
}

void LoggerSystem::error(const char* message) {
    Serial.print("[ERRO] ");
    Serial.println(message);
}