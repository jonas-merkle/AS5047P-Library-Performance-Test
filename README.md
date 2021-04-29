# AS5047P Library Performance Test

This software is for testing the performance of the [AS5047P library](https://github.com/jonas-merkle/AS5047P).

## Contents

- [AS5047P Library Performance Test](#as5047p-library-performance-test)
  - [Contents](#contents)
  - [Results](#results)
    - [Teensy 4.1](#teensy-41)
    - [Arduino Micro](#arduino-micro)
    - [Arduino Mega 2560](#arduino-mega-2560)
    - [Arduino Uno / Nano](#arduino-uno--nano)

## Results

### Teensy 4.1

| SPI Frequency [in Hz] | Average Delay for 'readAngleRaw()' [in µSec] |
|----------------------:|---------------------------------------------:|
| 100000                | 37                                           |
| 8000000               | 7                                            |
| 20000000              | 4                                            |
| 28000000              | 4                                            |

### Arduino Micro

| SPI Frequency [in Hz] | Average Delay for 'readAngleDegree()' [in µSec] |
|----------------------:|------------------------------------------------:|
| 100000                | 37                                              |
| 8000000               | 35                                              |

### Arduino Mega 2560

| SPI Frequency [in Hz] | Average Delay for 'readAngleDegree()' [in µSec] |
|----------------------:|------------------------------------------------:|
| 100000                | 288                                             |
| 8000000               | 36                                              |

### Arduino Uno / Nano

| SPI Frequency [in Hz] | Average Delay for 'readAngleDegree()' [in µSec] |
|----------------------:|------------------------------------------------:|
| 100000                | 291                                             |
| 8000000               | 39                                              |
