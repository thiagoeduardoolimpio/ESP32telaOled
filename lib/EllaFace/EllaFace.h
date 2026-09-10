#ifndef ELLA_FACE_H
#define ELLA_FACE_H

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class EllaFace {
public:
    EllaFace(Adafruit_SSD1306& display);

    void begin();
    void update();
    void proximaExpressao();

private:
    Adafruit_SSD1306& display;

    unsigned long ultimaPiscada;
    unsigned long inicioPiscada;

    bool piscando;
    int expressao;

    void desenharRosto();
};

#endif