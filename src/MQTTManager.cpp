#include "MQTTManager.h"
#include "WiFiManager.h" // Precisa saber se o Wi-Fi está ok antes de tentar o MQTT

MQTTManager Mqtt;

void MQTTManager::begin(const char* server, uint16_t port, const char* clientId) {
    _server = server;
    _port = port;
    _clientId = clientId;
    
    client.setClient(espClient);
    client.setServer(_server, _port);
    
    // client.setCallback(suaFuncaoDeCallback); // Adicione depois para receber mensagens
}

void MQTTManager::reconnect() {
    if (client.connect(_clientId)) {
        Serial.println("MQTT: Conectado com sucesso!");
        // client.subscribe("lavanderia/comandos"); // Inscreva-se nos tópicos necessários
    } else {
        Serial.print("MQTT: Falha ao conectar, rc=");
        Serial.print(client.state());
        Serial.println(". Tentando novamente na proxima janela.");
    }
}

void MQTTManager::update() {
    // Só tenta operar o MQTT se o Wi-Fi estiver conectado
    if (!Wifi.isConnected()) return;

    if (!client.connected()) {
        uint32_t currentMillis = millis();
        // Tentativa de reconexão não-bloqueante
        if (currentMillis - lastReconnectAttempt >= reconnectInterval) {
            lastReconnectAttempt = currentMillis;
            reconnect();
        }
    } else {
        client.loop(); // Mantém a comunicação viva e processa mensagens recebidas
    }
}

void MQTTManager::publish(const char* topic, const char* payload) {
    if (client.connected()) {
        client.publish(topic, payload);
    }
}