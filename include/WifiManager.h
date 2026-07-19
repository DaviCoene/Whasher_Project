#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include <Arduino.h>
#include <WiFi.h>

class WiFiManager {
public:
    void begin(const char* ssid, const char* password);
    void update();
    bool isConnected();

private:
    const char* _ssid;
    const char* _password;
    uint32_t lastReconnectAttempt = 0;
    const uint32_t reconnectInterval = 10000; // Tenta reconectar a cada 10 segundos
};

extern WiFiManager Wifi;

#endif