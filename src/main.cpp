#include <Arduino.h>
#include <AS5047P.h>
#include <inttypes.h>

// define the chip select port.
#define AS5047P_CHIP_SELECT_PORT 10 

// define the spi bus speed 
//#define AS5047P_CUSTOM_SPI_BUS_SPEED 100000
#define AS5047P_CUSTOM_SPI_BUS_SPEED 8000000
//#define AS5047P_CUSTOM_SPI_BUS_SPEED 20000000
//#define AS5047P_CUSTOM_SPI_BUS_SPEED 28000000


// initialize a new AS5047P sensor object.
AS5047P as5047p(AS5047P_CHIP_SELECT_PORT, AS5047P_CUSTOM_SPI_BUS_SPEED);

// number of measurements taken for performance analysis
#define NUMBER_OF_MEASUREMENTS 1000

void setup()
{
	// initialize the serial bus for the communication with your pc.
  	Serial.begin(115200);
	while (!Serial) {}

  	// initialize the AS5047P sensor and hold if sensor can't be initialized.
  	while (!as5047p.initSPI()) {
    	Serial.println(F("Can't connect to the AS5047P sensor! Please check the connection... "));
    	delay(5000);
  	}

	Serial.print(F("Press any key to restart... "));
	Serial.flush();

	while (Serial.available() == 0) {}
	Serial.println("");
	while (Serial.available() != 0) 
	{
		Serial.read();
	}
}

void loop()
{

	Serial.println(F("#########################################################################"));
	Serial.print(F("Testing AS5047P Libary Performance with a SPI frequency of: "));
	Serial.println(AS5047P_CUSTOM_SPI_BUS_SPEED);
	Serial.println(F("-------------------------------------------------------------------------"));
	Serial.flush();

	uint64_t timings = 0;

	for (uint16_t i  = 0; i < NUMBER_OF_MEASUREMENTS; i++)
	{
		uint32_t startTime = micros();
		//as5047p.readAngleDegree();
		as5047p.readAngleRaw();
		timings += micros() - startTime;
	}

	Serial.print(F("Total Time:   "));
	char buf[20] = {0};
	sprintf( buf, "%lu", timings);
	Serial.print(buf);
	Serial.println(F(" microseconds"));

	Serial.print(F("Average Time: "));
	sprintf( buf, "%lu", (uint32_t) timings/NUMBER_OF_MEASUREMENTS);
	Serial.print(buf);
	Serial.println(F(" microseconds"));

	Serial.println(F("-------------------------------------------------------------------------"));
	Serial.print(F("Press any key to restart... "));
	Serial.flush();

	while (Serial.available() == 0) {}
	Serial.println("");
	while (Serial.available() != 0) 
	{
		Serial.read();
	}
}