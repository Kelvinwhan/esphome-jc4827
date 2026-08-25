#pragma once

#include "esphome/core/component.h"
#include "esphome/components/display/display_buffer.h"
#include "TouchLib.h"

namespace esphome {
namespace jc4827 {

class JC4827Touch : public Component {
 public:
  explicit JC4827Touch(DisplayBuffer *disp);

  void setup() override;
  void loop() override;

 private:
  DisplayBuffer *display;
  TouchLib *touch;
};

}  // namespace jc4827
}  // namespace esphome
