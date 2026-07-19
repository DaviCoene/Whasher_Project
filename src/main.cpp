#include <Arduino.h>
#include "Relay.h"
#include "Sensors.h"
#include "Washer.h"
#include "WifiManager.h"
#include "Config.h" // Assumindo que você tem as credenciais aqui

// Se não tiver o Config.h ainda, substitua por suas credenciais:
const char* WIFI_SSID = "Sua_Rede_WiFi";
const char* WIFI_PASS = "Sua_Senha";

void setup() {
    Serial.begin(115200);
    
    Relay.begin();
    Sensor.begin();
    WasherController.begin();
    
    // Inicia o WiFi
    Wifi.begin(WIFI_SSID, WIFI_PASS);
    
    Serial.println("Sistema Iniciado.");
}

void loop() {
    Relay.update();
    Sensor.update();
    WasherController.update();
    
    // Mantém a conexão viva
    Wifi.update();
}