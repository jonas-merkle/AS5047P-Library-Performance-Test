# AS5047P Library Performance Test

This software is for testing the performance of the [AS5047P library](https://github.com/jonas-merkle/AS5047P).

## Contents

- [AS5047P Library Performance Test](#as5047p-library-performance-test)
  - [Contents](#contents)
  - [Results](#results)
    - [Teensy 4.1](#teensy-41)

## Results

### Teensy 4.1

| SPI Frequency [in Hz] | Average Delay for 'readAngleRaw()' [in µSec] | Average Delay for 'readAngleRaw()' [in µSec] |
|----------------------:|---------------------------------------------:|---------------------------------------------:|
| 100000                | 37                                           | 37                                           |
| 8000000               | 7                                            | 7                                            |
| 20000000              | 4                                            | 4                                            |
| 28000000              | 4                                            | 4                                            |
