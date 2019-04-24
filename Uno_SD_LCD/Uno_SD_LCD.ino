// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       Uno_SD_LCD.ino
    Created:	14.04.2019 18:04:00
    Author:     NOUT-HAG\hag
*/

// Define User Types below here or use a .h file
//


// Define Function Prototypes that use User Types below here or use a .h file
//


// Define Functions below here or use other .ino or cpp files
//

// The setup() function runs once each time the micro-controller starts
#include <SPI.h>
#include <UTFT.h>
#include <memorysaver.h>
#include <SD.h>
#define SD_CS 5
File file1;

void setup()
{
	
	Serial.begin(9600);
	bool good = SD.begin(SD_CS);
	 if (!good) {
		 Serial.println(F("cannot start SD"));
		 while (1);
	 }
	 else
	 {
		Serial.println(F("start SD"));
	 }
	
	
	file1 = SD.open("File1.txt", FILE_WRITE);
	if (!file1)
	{
		Serial.println("ERROR");
	}
	else
	{
		Serial.println("File OK");
	}

	file1.println ("Test");

	Serial.write (file1.read());

}

// Add the main program code into the continuous loop() function
void loop()
{
	

}
