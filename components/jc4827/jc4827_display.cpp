#include "jc4827_display.h"
#include "esphome/core/log.h"

namespace esphome {
namespace jc4827 {

static const char *TAG = "jc4827_display";

void JC4827Display::setup() {
  ESP_LOGI(TAG, "Setting up JC4827 display...");
  if (reset_pin_) reset_pin_->setup();
  if (backlight_pin_) backlight_pin_->setup();
  if (cs_pin_) cs_pin_->setup();
  if (dc_pin_) dc_pin_->setup();

  if (backlight_pin_) backlight_pin_->digital_write(true);
}

void JC4827Display::loop() {
  // Add refresh or driver-specific logic here
}

void JC4827Display::update() {
  // Called when ESPHome wants to redraw
  this->do_draw_();
}

}  // namespace jc4827
}  // namespace esphome
