#pragma once

#include "esphome/core/component.h"
#include "esphome/components/i2c/i2c.h"

namespace esphome {
namespace drv8830 {

class DRV8830 : public Component, public i2c::I2CDevice {
 public:
  void setup() override;
  void dump_config() override;

  enum Direction : uint8_t {
    RELEASE = 0,
    BACKWARD = 1,
    FORWARD  = 2,
    BRAKE    = 3
  };

  bool set_motor(uint8_t speed, Direction dir);
  bool get_fault(uint8_t *fault);

 protected:
  bool write_register_(uint8_t reg, uint8_t value);
  bool read_register_(uint8_t reg, uint8_t *value);
};

}  // namespace drv8830
}  // namespace esphome
