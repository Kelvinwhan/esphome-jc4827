#include "esphome.h"
#include <Arduino_GFX_Library.h>

class JC4827Display : public esphome::Component, public esphome::DisplayBuffer {
 public:
  Arduino_DataBus *bus;
  Arduino_GFX *gfx;

  void setup() override {
    // Configure RGB parallel bus
    bus = new Arduino_ESP32RGBPanel(
      40 /* DE */, 39 /* HSYNC */, 41 /* VSYNC */, 42 /* PCLK */,
      45, 48, 47, 21, 14,   // R0-R4
      5, 6, 7, 15, 16, 4,   // G0-G5
      8, 3, 46, 9, 1        // B0-B4
    );

    gfx = new Arduino_RGB_Display(bus, 480, 272);

    gfx->begin();
    pinMode(2, OUTPUT);      // Backlight pin
    digitalWrite(2, HIGH);   // Turn backlight on
  }

  void loop() override {
    // Nothing here yet
  }

  void update() override {
    // Draw test text
    gfx->fillScreen(BLACK);
    gfx->setCursor(50, 100);
    gfx->setTextColor(WHITE);
    gfx->setTextSize(2);
    gfx->println("Hello JC4827W543C!");
  }
};
