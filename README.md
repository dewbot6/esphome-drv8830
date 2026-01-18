# ESPHome DRV8830 Motor Driver Component

ESPHome custom component for controlling the DRV8830 I2C dual H-bridge motor driver.

## Overview

The DRV8830 is a low-voltage motor driver that can control two DC motors or one stepper motor via I2C interface. This component provides an easy-to-use interface for integrating the DRV8830 into your ESPHome projects.

## Features

- I2C-based motor control
- Speed control (0-63)
- Direction control (Forward, Backward, Brake, Release)
- Fault detection and reporting
- Easy integration with ESPHome

## Installation

Add this component to your ESPHome configuration:

```yaml
external_components:
  - source: github://andrewsnodgrass/esphome-drv8830/components/drv8830
    version: main  # or a specific tag/commit
```

## Quick Start

```yaml
esphome:
  name: my_motor_controller

i2c:
  sda: GPIO2
  scl: GPIO1
  scan: true

drv8830:
  id: motor_driver
  address: 0x60  # Optional, defaults to 0x60

switch:
  - platform: template
    name: "Motor Forward"
    turn_on_action:
      - lambda: |-
          id(motor_driver)->set_motor(32, id(motor_driver)->FORWARD);
      - delay: 1s
      - lambda: |-
          id(motor_driver)->set_motor(0, id(motor_driver)->RELEASE);
```

## Documentation

For detailed documentation, API reference, and usage examples, see the [component README](components/drv8830/README.md).

## Requirements

- ESPHome 2023.1.0 or later
- I2C bus configured in your ESPHome configuration
- DRV8830 motor driver connected via I2C

## License

BSD License - see [LICENSE](LICENSE) file for details.

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## Author

[@andrewsnodgrass](https://github.com/andrewsnodgrass)
