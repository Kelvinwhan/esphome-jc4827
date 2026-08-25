#pragma once

#include "esphome/core/component.h"
#include "esphome/core/gpio.h"

namespace esphome {
namespace jc4827 {

class JC4827Display;  // forward declaration

class JC4827Touch : public Component {
 public:
  void setup() override;
  void loop() override;

  void set_display(JC4827Display *disp) { display_ = disp; }
  void set_cs_pin(GPIOPin *pin) { cs_pin_ = pin; }
  void set_irq_pin(GPIOPin *pin) { irq_pin_ = pin; }
  void set_reset_pin(GPIOPin *pin) { reset_pin_ = pin; }

 protected:
  JC4827Display *display_{nullptr};
  GPIOPin *cs_pin_{nullptr};
  GPIOPin *irq_pin_{nullptr};
  GPIOPin *reset_pin_{nullptr};
};

}  // namespace jc4827
}  // namespace esphome
