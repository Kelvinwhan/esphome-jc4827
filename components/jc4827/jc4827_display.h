#pragma once

#include "esphome/components/display/display_buffer.h"
#include "esphome/core/gpio.h"

namespace esphome {
namespace jc4827 {

class JC4827Display : public display::DisplayBuffer {
 public:
  void setup() override;
  void loop() override;
  void update() override;
  int get_width() override { return 800; }
  int get_height() override { return 480; }

  void set_cs_pin(GPIOPin *pin) { cs_pin_ = pin; }
  void set_dc_pin(GPIOPin *pin) { dc_pin_ = pin; }
  void set_reset_pin(GPIOPin *pin) { reset_pin_ = pin; }
  void set_backlight_pin(GPIOPin *pin) { backlight_pin_ = pin; }

 protected:
  GPIOPin *cs_pin_{nullptr};
  GPIOPin *dc_pin_{nullptr};
  GPIOPin *reset_pin_{nullptr};
  GPIOPin *backlight_pin_{nullptr};
};

}  // namespace jc4827
}  // namespace esphome
