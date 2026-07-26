#include <Arduino.h>
#include "Relay.h"
#include "Sensors.h"
#include "Washer.h"
#include "Dryer.h"
#include "WifiManager.h"
#include "Config.h" // Assumindo que você tem as credenciais aqui

// Se não tiver o Config.h ainda, substitua por suas credenciais:
const char* WIFI_SSID = "POCO X7 Pro";
const char* WIFI_PASS = "12345678";

void setup() {
    Serial.begin(115200);
    
    Relay.begin();
    Sensor.begin();
    WasherController.begin();
    DryerController.begin();
    
    // Inicia o WiFi
    Wifi.begin(WIFI_SSID, WIFI_PASS);
    
    Serial.println("Sistema Iniciado.");
}

void loop() {
    Relay.update();
    Sensor.update();
    WasherController.update();
    DryerController.update();
    
    // Mantém a conexão viva
    Wifi.update();

    if (Serial.available() > 0) {
        char comando = Serial.read();
        
        // Se você digitar '1' e der Enter no Monitor Serial
        if (comando == '1') {
            Serial.println("Comando recebido: Iniciar Lavadora");
            WasherController.startCycle();
        }
        else if (comando == '2') {
            Serial.println("Comando recebido: Iniciar Secadora");
            DryerController.startCycle();
        }
    }
}