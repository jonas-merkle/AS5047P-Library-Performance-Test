#include <Arduino.h>
#include <inttypes.h>
#include <AS5047P.h>

// define the chip select port.
#define AS5047P_CHIP_SELECT_PORT 10 

// define the spi bus speed 
//#define AS5047P_CUSTOM_SPI_BUS_SPEED 100000
//#define AS5047P_CUSTOM_SPI_BUS_SPEED 8000000
//#define AS5047P_CUSTOM_SPI_BUS_SPEED 20000000
//#define AS5047P_CUSTOM_SPI_BUS_SPEED 28000000
#define AS5047P_CUSTOM_SPI_BUS_SPEED 29900000


// initialize a new AS5047P sensor object.
AS5047P as5047p(AS5047P_CHIP_SELECT_PORT, AS5047P_CUSTOM_SPI_BUS_SPEED);

// number of measurements taken for performance analysis
#define NUMBER_OF_MEASUREMENTS 10000

void setup()
{
	// initialize the serial bus for the communication with your pc.
  	Serial.begin(115200);
	while (!Serial) {}

  	// initialize the AS5047P sensor and hold if sensor can't be initialized.
  	while (!as5047p.initSPI()) {
    	Serial.println(F("Can't connect to the AS5047P sensor! Please check the connection..."));
    	delay(5000);
  	}

	Serial.print(F("Press any key to start... "));
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
	Serial.flush();

	// inital variable definition
	uint64_t timings[3] = {0};
	char buf[20] = {0};

	// performace tests
	for (uint16_t i  = 0; i < NUMBER_OF_MEASUREMENTS; i++)
	{
		uint32_t startTime = 0;

		// dummy reads
		as5047p.readMagnitude();
		as5047p.readAngleDegree();
		as5047p.readAngleRaw();

		startTime = micros();
		as5047p.readMagnitude();
		timings[0] += micros() - startTime;

		startTime = micros();
		as5047p.readAngleDegree();
		timings[1] += micros() - startTime;

		startTime = micros();
		as5047p.readAngleRaw();
		timings[2] += micros() - startTime;
	}

	// results 
	Serial.println(F("-------------------------------------------------------------------------"));
	Serial.println(F("Function: readMagnitude()"));

	Serial.print(F("Total Time:   "));
	#if defined(ARDUINO_ARCH_SAMD) || defined(CORE_TEENSY)
	sprintf( buf, "%llu", timings[0]);
	#else
	sprintf( buf, "%lu", timings[0]);
	#endif
	Serial.print(buf);
	Serial.println(F(" microseconds"));

	Serial.print(F("Average Time: "));
	#if defined(ARDUINO_ARCH_SAMD) || defined(CORE_TEENSY)
	sprintf( buf, "%lf", timings[0]/(float)NUMBER_OF_MEASUREMENTS);
	#else
	sprintf( buf, "%lu", (uint32_t) timings[0]/NUMBER_OF_MEASUREMENTS);
	#endif
	Serial.print(buf);
	Serial.println(F(" microseconds"));

	Serial.println(F("-------------------------------------------------------------------------"));
	Serial.println(F("Function: readAngleDegree()"));

	Serial.print(F("Total Time:   "));
	#if defined(ARDUINO_ARCH_SAMD) || defined(CORE_TEENSY)
	sprintf( buf, "%llu", timings[1]);
	#else
	sprintf( buf, "%lu", timings[1]);
	#endif
	Serial.print(buf);
	Serial.println(F(" microseconds"));

	Serial.print(F("Average Time: "));
	#if defined(ARDUINO_ARCH_SAMD) || defined(CORE_TEENSY)
	sprintf( buf, "%lf", timings[1]/(float)NUMBER_OF_MEASUREMENTS);
	#else
	sprintf( buf, "%lu", (uint32_t) timings[1]/NUMBER_OF_MEASUREMENTS);
	#endif
	Serial.print(buf);
	Serial.println(F(" microseconds"));

	Serial.println(F("-------------------------------------------------------------------------"));
	Serial.println(F("Function: readAngleRaw()"));

	Serial.print(F("Total Time:   "));
	#if defined(ARDUINO_ARCH_SAMD) || defined(CORE_TEENSY)
	sprintf( buf, "%llu", timings[2]);
	#else
	sprintf( buf, "%lu", timings[2]);
	#endif
	Serial.print(buf);
	Serial.println(F(" microseconds"));

	Serial.print(F("Average Time: "));
	#if defined(ARDUINO_ARCH_SAMD) || defined(CORE_TEENSY)
	sprintf( buf, "%lf", timings[2]/(float)NUMBER_OF_MEASUREMENTS);
	#else
	sprintf( buf, "%lu", (uint32_t) timings[2]/NUMBER_OF_MEASUREMENTS);
	#endif
	Serial.print(buf);
	Serial.println(F(" microseconds"));

	Serial.println(F("-------------------------------------------------------------------------"));
	Serial.println(F("#########################################################################"));
	Serial.print(F("Press any key to restart... "));
	Serial.flush();

	while (Serial.available() == 0) {}
	Serial.println("");
	while (Serial.available() != 0) 
	{
		Serial.read();
	}
}