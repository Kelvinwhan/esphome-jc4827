#include "esphome.h"
#include "esphome/components/i2c/i2c.h"
#include <TouchLib.h>

class JC4827Touch : public esphome::Component {
 public:
  JC4827Touch(esphome::DisplayBuffer *disp);
  void setup() override;
  void loop() override;

 private:
  TouchLib *touch;
  esphome::DisplayBuffer *display;
};
