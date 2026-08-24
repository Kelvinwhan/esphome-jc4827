#include "jc4827_touch.h"

JC4827Touch::JC4827Touch(esphome::DisplayBuffer *disp) {
  display = disp;
}

void JC4827Touch::setup() {
  Wire.begin(8, 4); // SDA=GPIO8, SCL=GPIO4
  touch = new TouchLib(Wire, 0x5D, 3, 38); // addr=0x5D, INT=GPIO3, RST=GPIO38
  touch->begin();
}

void JC4827Touch::loop() {
  if (touch->available()) {
    TP_Point p = touch->read();
    ESP_LOGI("touch", "Touch at x=%d y=%d", p.x, p.y);
    lvgl::touch_update(p.x, p.y, true);
  } else {
    lvgl::touch_update(0, 0, false);
  }
}
