#include "EllaFace.h"

EllaFace::EllaFace(Adafruit_SSD1306& display)
    : display(display),
      ultimaPiscada(millis()),
      inicioPiscada(0),
      piscando(false),
      expressao(0) {
}

void EllaFace::begin() {
    desenharRosto();
}

void EllaFace::update() {
    unsigned long agora = millis();

    // Piscada automática
    if (!piscando && agora - ultimaPiscada >= 4000) {
        piscando = true;
        inicioPiscada = agora;
        desenharRosto();
    }

    if (piscando && agora - inicioPiscada >= 150) {
        piscando = false;
        ultimaPiscada = agora;
        desenharRosto();
    }
}

void EllaFace::proximaExpressao() {
    expressao++;

    if (expressao > 4) {
        expressao = 0;
    }

    piscando = false;
    ultimaPiscada = millis();

    desenharRosto();
}

void EllaFace::desenharRosto() {
    display.clearDisplay();

    if (piscando) {
        display.fillRoundRect(20, 30, 32, 5, 2, SSD1306_WHITE);
        display.fillRoundRect(76, 30, 32, 5, 2, SSD1306_WHITE);
    }
    else {
        switch (expressao) {

            case 0:
                // Normal
                display.fillRoundRect(20, 18, 32, 28, 8, SSD1306_WHITE);
                display.fillRoundRect(76, 18, 32, 28, 8, SSD1306_WHITE);

                display.fillCircle(36, 32, 7, SSD1306_BLACK);
                display.fillCircle(92, 32, 7, SSD1306_BLACK);

                display.drawRoundRect(52, 51, 24, 6, 2, SSD1306_WHITE);
                break;

            case 1:
            // Feliz
                display.fillRoundRect(20, 18, 32, 28, 8, SSD1306_WHITE);
                display.fillRoundRect(76, 18, 32, 28, 8, SSD1306_WHITE);

                display.fillCircle(36, 32, 7, SSD1306_BLACK);
                display.fillCircle(92, 32, 7, SSD1306_BLACK);

                // Boca feliz
                display.drawLine(52, 51, 57, 55, SSD1306_WHITE);
                display.drawLine(57, 55, 64, 57, SSD1306_WHITE);
                display.drawLine(64, 57, 71, 55, SSD1306_WHITE);
                display.drawLine(71, 55, 76, 51, SSD1306_WHITE);
                break;

            case 2:
                // Triste
                display.fillRoundRect(20, 18, 32, 28, 8, SSD1306_WHITE);
                display.fillRoundRect(76, 18, 32, 28, 8, SSD1306_WHITE);

                display.fillCircle(36, 34, 7, SSD1306_BLACK);
                display.fillCircle(92, 34, 7, SSD1306_BLACK);

                display.drawLine(52, 56, 64, 50, SSD1306_WHITE);
                display.drawLine(64, 50, 76, 56, SSD1306_WHITE);
                break;

            case 3:
                // Surpresa
                display.fillRoundRect(20, 16, 32, 32, 8, SSD1306_WHITE);
                display.fillRoundRect(76, 16, 32, 32, 8, SSD1306_WHITE);

                display.fillCircle(36, 32, 8, SSD1306_BLACK);
                display.fillCircle(92, 32, 8, SSD1306_BLACK);

                display.fillCircle(64, 53, 5, SSD1306_WHITE);
                break;

            case 4:
                // Pensando
                display.fillRoundRect(20, 18, 32, 28, 8, SSD1306_WHITE);
                display.fillRoundRect(76, 18, 32, 28, 8, SSD1306_WHITE);

                display.fillCircle(40, 28, 7, SSD1306_BLACK);
                display.fillCircle(88, 36, 7, SSD1306_BLACK);

                display.drawRoundRect(55, 51, 18, 5, 2, SSD1306_WHITE);
                break;
        }
    }

    display.display();
}