# MPU6050 - Accelerometer example

## Overview

MPU6050: Combines a 3-axis gyroscope and 3-axis accelerometer.

## Explain

### i2c_read_nack()

it's the last byte we want to read from the I2C device during that transaction.

🧠 ACK vs NACK in I2C Reads
ACK (Acknowledge): Sent by the master to tell the slave “I want to keep reading more bytes.”

NACK (Not Acknowledge): Sent by the master to say “I’m done reading, stop transmitting.”

### i2c_write(0x6B)

Power management register

0x6B is the address of the Power Management 1 register in the MPU6050.

By default, when the MPU6050 powers up, it is in sleep mode to conserve energy.

Writing 0 to this register clears the sleep bit (bit 6), effectively waking up the sensor.

### Convert raw data to g value

To convert it into g (gravitational acceleration units), you need to apply the sensor’s sensitivity scale.

