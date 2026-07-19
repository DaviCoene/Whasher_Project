#ifndef MQTT_MANAGER_H
#define MQTT_MANAGER_H

#include <Arduino.h>
#include <PubSubClient.h>
#include <WiFi.h>

class MQTTManager {
public:
    void begin(const char* server, uint16_t port, const char* clientId);
    void update();
    void publish(const char* topic, const char* payload);
    
private:
    const char* _server;
    uint16_t _port;
    const char* _clientId;
    
    WiFiClient espClient;
    PubSubClient client;

    uint32_t lastReconnectAttempt = 0;
    const uint32_t reconnectInterval = 5000; // Tenta reconectar a cada 5 segundos
    
    void reconnect();
};

extern MQTTManager Mqtt;

#endif