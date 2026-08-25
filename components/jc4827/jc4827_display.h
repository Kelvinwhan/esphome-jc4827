#pragma once

#include "esphome/components/display/display_buffer.h"

namespace esphome {
namespace jc4827 {

class JC4827Display : public display::DisplayBuffer {
 public:
  void setup() override;
  void loop() override;
  void update() override;
  int get_width() override { return 800; }   // adjust to your panel resolution
  int get_height() override { return 480; }  // adjust to your panel resolution
};

}  // namespace jc4827
}  // namespace esphome
