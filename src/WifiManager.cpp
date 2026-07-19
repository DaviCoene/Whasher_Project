#include "WiFiManager.h"

WiFiManager Wifi;

void WiFiManager::begin(const char* ssid, const char* password) {
    _ssid = ssid;
    _password = password;
    
    WiFi.mode(WIFI_STA);
    WiFi.begin(_ssid, _password);
    
    Serial.print("Conectando ao WiFi: ");
    Serial.println(_ssid);
}

void WiFiManager::update() {
    // Se estiver conectado, não faz nada
    if (WiFi.status() == WL_CONNECTED) {
        return;
    }

    // Se estiver desconectado, tenta reconectar a cada 10 segundos (não-bloqueante)
    uint32_t currentMillis = millis();
    if (currentMillis - lastReconnectAttempt >= reconnectInterval) {
        lastReconnectAttempt = currentMillis;
        Serial.println("Tentando reconectar ao WiFi...");
        WiFi.disconnect();
        WiFi.begin(_ssid, _password);
    }
}

bool WiFiManager::isConnected() {
    return WiFi.status() == WL_CONNECTED;
}