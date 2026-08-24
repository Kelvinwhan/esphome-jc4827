#include "jc4827_display.h"

void JC4827Display::setup() {
  bus = new Arduino_ESP32RGBPanel(
    40, 39, 41, 42,
    45, 48, 47, 21, 14,
    5, 6, 7, 15, 16, 4,
    8, 3, 46, 9, 1
  );
  gfx = new Arduino_RGB_Display(bus, 480, 272);
  gfx->begin();
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
}

void JC4827Display::update() {
  // LVGL will handle drawing
}

void JC4827Display::draw_pixel_at(int x, int y, esphome::Color color) {
  gfx->drawPixel(x, y, color.to_rgb_565());
}
