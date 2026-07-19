// #ifndef CONFIG_H
// #define CONFIG_H

// #define WIFI_TIMEOUT            15000

// #define MQTT_TIMEOUT            5000

// #define START_PULSE_TIME        400

// #define STOP_PULSE_TIME         400

// #define DRYER_PULSE_INTERVAL    500

// #define HEARTBEAT_INTERVAL      30000

// #endif

#ifndef CONFIG_H
#define CONFIG_H

// Tempos de ciclo (em milissegundos) para evitar o delay()
const uint32_t WASHER_CYCLE_TIME = 1800000; // Exemplo: 30 minutos

#endif