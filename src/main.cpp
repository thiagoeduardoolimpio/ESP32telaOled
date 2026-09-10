#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <EllaFace.h>

// ============================================================
// NÃO ALTERAR: CONFIGURAÇÃO DO HARDWARE
// SDA = GPIO 16
// SCL = GPIO 17
// OLED = 128x64
// Endereço I2C = 0x3C
// BOOT = GPIO 0
// ============================================================

#define SDA_PIN 16
#define SCL_PIN 17
#define BOOT_BUTTON 0

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

EllaFace rosto(display);

bool ultimoEstadoBotao = HIGH;

void setup() {
    Serial.begin(115200);

    // NÃO ALTERAR
    Wire.begin(SDA_PIN, SCL_PIN);

    // NÃO ALTERAR
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println("Falha ao iniciar o OLED.");
        while (true);
    }

    pinMode(BOOT_BUTTON, INPUT_PULLUP);

    rosto.begin();

    Serial.println("ELLA iniciada!");
}

void loop() {
    rosto.update();

    bool estadoBotao = digitalRead(BOOT_BUTTON);

    // Detecta o momento em que o BOOT é pressionado
    if (ultimoEstadoBotao == HIGH && estadoBotao == LOW) {
        rosto.proximaExpressao();
    }

    ultimoEstadoBotao = estadoBotao;

    delay(10);
}