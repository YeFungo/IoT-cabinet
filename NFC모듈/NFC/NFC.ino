#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#define RST_PIN         9          // Configurable, see typical pin layout above
#define SS_PIN          10         // Configurable, see typical pin layout above

Servo myservo;
MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance
int count = 0;
int angle = 0;
void setup() {
  myservo.attach(A3);
	Serial.begin(9600);		// Initialize serial communications with the PC
	while (!Serial);		// Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
	SPI.begin();			// Init SPI bus
	mfrc522.PCD_Init();		// Init MFRC522
	mfrc522.PCD_DumpVersionToSerial();	// Show details of PCD - MFRC522 Card Reader details
	Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));

}

void loop() {
	// Look for new cards
  
  
	    if ( ! mfrc522.PICC_IsNewCardPresent()) {
		    return;
	    }

	    // Select one of the cards
	    if ( ! mfrc522.PICC_ReadCardSerial()) {
		    return;
	    }
      if ( Serial.print("Card SAK: 20") )
      {
        count++;
         angle = 180;
         myservo.write(angle);
         delay(1000);
      }

      if ( count % 2 )
      {
        angle = 90;
        myservo.write(angle);
        delay(1000);
        }
	      // Dump debug info about the card; PICC_HaltA() is automatically called
	      mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
       
}
