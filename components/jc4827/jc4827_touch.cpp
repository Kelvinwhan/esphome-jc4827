#include "jc4827_touch.h"
#include "esphome/core/log.h"

namespace esphome {
namespace jc4827 {

static const char *TAG = "jc4827_touch";

void JC4827Touch::setup() {
  ESP_LOGI(TAG, "Setting up JC4827 touch...");
  if (cs_pin_) cs_pin_->setup();
  if (irq_pin_) irq_pin_->setup();
  if (reset_pin_) reset_pin_->setup();
}

void JC4827Touch::loop() {
  // Poll touch controller here
  // Example: if (irq_pin_ && !irq_pin_->digital_read()) { ... }
}

}  // namespace jc4827
}  // namespace esphome
