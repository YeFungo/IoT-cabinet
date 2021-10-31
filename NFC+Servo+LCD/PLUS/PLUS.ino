
#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define RST_PIN         9          // Configurable, see typical pin layout above
#define SS_PIN          10         // Configurable, see typical pin layout above

LiquidCrystal_I2C lcd(0x3f,16,2); 

  Servo myservo;
  MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance
  int count = 1;
  int angle = 0;
void setup() {

  myservo.attach(A3);
  
	Serial.begin(9600);		// Initialize serial communications with the PC
	while (!Serial);		// Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
	SPI.begin();			// Init SPI bus
	mfrc522.PCD_Init();		// Init MFRC522
	mfrc522.PCD_DumpVersionToSerial();	// Show details of PCD - MFRC522 Card Reader details
	Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));


  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("H");
  lcd.print("e");
  lcd.print("l");
  lcd.print("l");
  lcd.print("o");
  lcd.print(" ");
  lcd.print("W");
  lcd.print("o");
  lcd.print("r");
  lcd.print("l");
  lcd.print("d");

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
          if( count % 2 == 0)
          {
         lcd.clear();
         lcd.setCursor(0, 0);
          lcd.print("O");
          lcd.print("p");
          lcd.print("e");
          lcd.print("n");
          lcd.print("e");
          lcd.print("d");
          lcd.print(" ");
          lcd.print("C");
          lcd.print("o");
          lcd.print("m");
          lcd.print("p");
          lcd.print("l");
          lcd.print("e");
          lcd.print("t");
          lcd.print("e");
          lcd.print("!");
          delay(1000);
          lcd.clear();
          }
     
      }

      if ( count % 2 )
      {
        angle = 90;
        myservo.write(angle);
        delay(1000);
          
          lcd.setCursor(0, 0);
      }
          if( count % 2 == 1)
          {
          lcd.clear();
          lcd.print("C");
          lcd.print("l");
          lcd.print("o");
          lcd.print("s");
          lcd.print("e");
          lcd.print("d");
          lcd.print(" ");
          lcd.print("C");
          lcd.print("o");
          lcd.print("m");
          lcd.print("p");
          lcd.print("l");
          lcd.print("e");
          lcd.print("t");
          lcd.print("e");
          lcd.print("!");
           delay(1000);
          lcd.clear();
          }
        

        lcd.clear();
        lcd.print("S");
        lcd.print("e");
        lcd.print("c");
        lcd.print("u");
        lcd.print("r");
        lcd.print("i");
        lcd.print("t");
        lcd.print("y");
        lcd.print(" ");
        lcd.print("a");
        lcd.print("l");
        lcd.print("r");
        lcd.print("e");
        lcd.print("a");
        lcd.print("d");
        lcd.print("y");
	      // Dump debug info about the card; PICC_HaltA() is automatically called
	  
	      mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
       
}
