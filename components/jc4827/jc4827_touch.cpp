#include "jc4827_touch.h"
#include "esphome/core/log.h"
#include "esphome/components/lvgl/lvgl.h"
#include <Wire.h>

namespace esphome {
namespace jc4827 {

JC4827Touch::JC4827Touch(DisplayBuffer *disp) {
  display = disp;
  touch = nullptr;
}

void JC4827Touch::setup() {
  // Initialize I2C bus on GPIO8 (SDA) and GPIO4 (SCL)
  Wire.begin(8, 4);

  // addr=0x5D, INT=GPIO3, RST=GPIO38
  touch = new TouchLib(Wire, 0x5D, 3, 38);
  touch->begin();
}

void JC4827Touch::loop() {
  if (touch != nullptr && touch->available()) {
    TP_Point p = touch->read();
    ESP_LOGI("touch", "Touch at x=%d y=%d", p.x, p.y);
    lvgl::touch_update(p.x, p.y, true);
  } else {
    lvgl::touch_update(0, 0, false);
  }
}

}  // namespace jc4827
}  // namespace esphome
