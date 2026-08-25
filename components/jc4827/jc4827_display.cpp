#include "jc4827_display.h"
#include "esphome/core/log.h"

namespace esphome {
namespace jc4827 {

void JC4827Display::setup() {
  ESP_LOGI("display", "JC4827 display setup");
  // Initialize your panel hardware here
}

void JC4827Display::loop() {
  // Optional: handle refresh logic
}

void JC4827Display::update() {
  // Draw LVGL buffer to hardware here
}

}  // namespace jc4827
}  // namespace esphome
