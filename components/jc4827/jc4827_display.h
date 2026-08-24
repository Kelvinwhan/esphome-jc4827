#pragma once
#include "esphome/core/component.h"

namespace esphome {
namespace jc4827 {

class JC4827 : public Component {
 public:
  void setup() override;
  void loop() override;
};

}  // namespace jc4827
}  // namespace esphome
