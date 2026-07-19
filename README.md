# Washer & Dryer Controller 🚀

Um sistema robusto, modular e totalmente **não-bloqueante (zero `delay()`)** desenvolvido em C++ com PlatformIO para o ecossistema ESP32. Projetado especificamente para automação e monitoramento de equipamentos industriais ou comerciais de lavanderia self-service através do protocolo MQTT.

---

## 📌 Visão Geral do Projeto

O firmware foi estruturado utilizando conceitos avançados de **Máquinas de Estado Finitas (FSM)** e programação orientada a eventos. Toda a lógica de temporização, debounce de sensores e reconexão de rede baseia-se em checagens de tempo assíncronas (`millis()`), garantindo que o processador nunca fique travado e consiga responder instantaneamente a estímulos externos e de rede.

### ✨ Principais Características
* **Arquitetura Assíncrona:** Sem uso de funções bloqueantes, garantindo fluidez no processamento global.
* **Máquinas de Estado Isoladas:** Ciclos independentes de Lavadora (`Washer`) e Secadora (`Dryer`).
* **Debounce de Hardware nativo:** Proteção contra ruídos elétricos nas leituras dos sensores em nível de firmware.
* **Resiliência de Rede:** Gerenciadores dedicados para auto-reconexão inteligente de Wi-Fi e MQTT.
* **Abordagem Singleton:** Instâncias globais bem gerenciadas (`Relay`, `Sensor`, `Logger`) facilitando a comunicação entre módulos sem poluir o escopo global.

---

## 📂 Estrutura do Projeto

O projeto segue estritamente a árvore padrão do ecossistema PlatformIO, mantendo a separação rígida entre cabeçalhos e implementações:

```text
Whasher_Project/
├── .pio/               # Arquivos de compilação do PlatformIO
├── include/            # Arquivos de Cabeçalho (.h)
│   ├── Config.h        # Constantes, tempos e configurações gerais
│   ├── Dryer.h         # FSM da Secadora
│   ├── Logger.h        # Abstração de logs do sistema
│   ├── MQTTManager.h   # Cliente de comunicação assíncrona MQTT
│   ├── Pins.h          # Mapeamento estrito do Hardware (GPIOs)
│   ├── Relay.h         # Controle lógico de atuadores
│   ├── Sensors.h       # Leitura e debounce de inputs
│   ├── Washer.h        # FSM da Lavadora
│   └── WiFiManager.h   # Gerenciador inteligente da interface Wi-Fi
├── src/                # Implementações (.cpp) e Orquestrador
│   ├── main.cpp        # Loop principal e inicialização do sistema
│   └── [Módulos].cpp   # Implementação respectiva de cada cabeçalho
└── platformio.ini      # Configurações de build e dependências
