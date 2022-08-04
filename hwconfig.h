#define Use_SoftI2CMaster
//#define Use_SoftWire
#define I2CFAST

#if defined(I2CFAST)
  #define I2C_FASTMODE  1
  #define I2CCLOCK  400000L   //100000L for StandarMode, 400000L for FastMode and 1000000L for FastModePlus
#else
  #define I2C_FASTMODE  0
  #define I2CCLOCK  100000L   //100000L for StandarMode, 400000L for FastMode and 1000000L for FastModePlus
#endif

#if defined(__RASPBERRY_PI_PICO__)
  #ifdef Use_SoftI2CMaster
    #undef Use_SoftI2CMaster
  #endif
  #ifdef Use_SoftWire
    #undef Use_SoftWire
  #endif
#endif

#if defined(__RASPBERRY_PI_PICO__)
  #include "TimerCounter.h"
  TimerCounter timer(2);
#endif


#include <SdFat.h>


#define scrollSpeed   250           //text scroll delay
#define scrollWait    3000          //Delay before scrolling starts

#ifdef LCDSCREEN16x2
  //#include <Wire.h>
  #include "LiquidCrystal_I2C_Soft.h"
  LiquidCrystal_I2C lcd(LCD_I2C_ADDR,16,2); // set the LCD address to 0x27 for a 16 chars and 2 line display
  char indicators[] = {'|', '/', '-',0};
  uint8_t SpecialChar [8]= { 0x00, 0x10, 0x08, 0x04, 0x02, 0x01, 0x00, 0x00 };
  #define SCREENSIZE 16  

#elif defined(OLED1306)
  #if defined(Use_SoftI2CMaster) && defined(__AVR_ATmega2560__) 
    #define SDA_PORT PORTD
    #define SDA_PIN 1 
    #define SCL_PORT PORTD
    #define SCL_PIN 0 
    #include <SoftI2CMaster.h>         
  #elif defined(Use_SoftI2CMaster) && defined(__AVR_ATmega32U4__) 
    #define SDA_PORT PORTD
    #define SDA_PIN 1 
    #define SCL_PORT PORTD
    #define SCL_PIN 0 
    #include <SoftI2CMaster.h> 
  #elif defined(Use_SoftI2CMaster) 
    #define SDA_PORT PORTC
    #define SDA_PIN 4 
    #define SCL_PORT PORTC
    #define SCL_PIN 5 
    #include <SoftI2CMaster.h>        
  #elif defined(Use_SoftWire) && defined(__AVR_ATmega2560__) 
    #define SDA_PORT PORTD
    #define SDA_PIN 1 
    #define SCL_PORT PORTD
    #define SCL_PIN 0 
    #include <SoftWire.h>
    SoftWire Wire = SoftWire();
   #elif defined(Use_SoftI2CMaster) && defined(__AVR_ATmega32U4__) 
    #define SDA_PORT PORTD
    #define SDA_PIN 1 
    #define SCL_PORT PORTD
    #define SCL_PIN 0 
    #include <SoftWire.h>
    SoftWire Wire = SoftWire();  
  #elif defined(Use_SoftWire) 
    #define SDA_PORT PORTC
    #define SDA_PIN 4 
    #define SCL_PORT PORTC
    #define SCL_PIN 5 
    #include <SoftWire.h>
    SoftWire Wire = SoftWire();  
  #else
    #include <Wire.h>
  #endif
  //#include "U8glib.h"
  //U8GLIB_SSD1306_128X32 u8g(U8G_I2C_OPT_NONE);  // I2C / TWI 
  //char line0[17];
  //char line1[17];
  char indicators[] = {'|', '/', '-',92};
  #define SCREENSIZE 16  
#elif defined(P8544)
  #include <pcd8544.h>
  #define ADMAX 1023
  #define ADPIN 0
  #include <avr/pgmspace.h>
  byte dc_pin = 5;
  byte reset_pin = 3;
  byte cs_pin = 4;
  pcd8544 lcd(dc_pin, reset_pin, cs_pin);
  #define backlight_pin 2
  char indicators[] = {'|', '/', '-',0};
  uint8_t SpecialChar [8]= { 0x00, 0x10, 0x08, 0x04, 0x02, 0x01, 0x00, 0x00 };
  #define SCREENSIZE 14
  
  const byte Play [] PROGMEM = {
    0x00, 0x7f, 0x3e, 0x1c, 0x08, 0x00, 0x00
  };
  const byte Paused [] PROGMEM = {
    0x00, 0x7f, 0x7f, 0x00, 0x7f, 0x7f, 0x00
  };
  const byte Stop [] PROGMEM = {
    0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e
  };
#else
  #define SCREENSIZE 16
#endif
