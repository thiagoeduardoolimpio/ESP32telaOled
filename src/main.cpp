#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// NÃO ALTERAR: CONFIGURAÇÃO DO HARDWARE
// Estes valores correspondem à ligação física do OLED.
// SDA = GPIO 16
// SCL = GPIO 17
// Endereço I2C do OLED = 0x3C

#define SDA_PIN 16
#define SCL_PIN 17

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);
// NÃO ALTERAR: inicialização do barramento I2C
  Wire.begin(SDA_PIN, SCL_PIN);

// NÃO ALTERAR: endereço do OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("Falha ao iniciar o OLED.");
    while (true);
  }

  display.clearDisplay();

  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 20);
  display.println("Ola Mundo!");

  display.display();

  Serial.println("OLED funcionando!");
}

void loop() {
}