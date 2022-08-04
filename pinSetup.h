#ifndef PINSETUP_H_INCLUDED
#define PINSETUP_H_INCLUDED

#if defined(__RASPBERRY_PI_PICO__)
  #define outputPin           D9    // this pin is PWM output capable
  #define INIT_OUTPORT            pinMode(outputPin,OUTPUT)
  //gpio_set_function(outputPin, GPIO_FUNC_PWM)
  
  //#define INIT_OUTPORT            pinMode(outputPin,OUTPUT); GPIOA->regs->CRH |=  0x00000030  
  #define WRITE_LOW               digitalWrite(outputPin,LOW)
  //#define WRITE_LOW               GPIOA->regs->ODR &= ~0b0000001000000000
  //#define WRITE_LOW               gpio_write_bit(GPIOA, 9, LOW)
  #define WRITE_HIGH              digitalWrite(outputPin,HIGH)
  //#define WRITE_HIGH              GPIOA->regs->ODR |=  0b0000001000000000
  //#define WRITE_HIGH              gpio_write_bit(GPIOA, 9, HIGH)
#endif 

/////////////////////////////////////////////////////////////////////////////////////////////
  //General Pin settings
  //Setup buttons with internal pullup

#if defined(__RASPBERRY_PI_PICO__)
  #define chipSelect    D17            //Sd card chip select pin
  
  #define btnPlay       D7           //Play Button
  #define btnStop       D6           //Stop Button
  #define btnUp         D2           //Up button
  #define btnDown       D3           //Down button
  #define btnMotor      D9     //Motor Sense (connect pin to gnd to play, NC for pause)
  #define btnRoot       D15           //Return to SD card root

#endif


#if defined(__RASPBERRY_PI_PICO__)

  //General Pin settings
  //Setup buttons with internal pullup 
  pinMode(btnPlay,INPUT_PULLUP);
  digitalWrite(btnPlay,HIGH);
  pinMode(btnStop,INPUT_PULLUP);
  digitalWrite(btnStop,HIGH);
  pinMode(btnUp,INPUT_PULLUP);
  digitalWrite(btnUp,HIGH);
  pinMode(btnDown,INPUT_PULLUP);
  digitalWrite(btnDown,HIGH);
  pinMode(btnMotor, INPUT_PULLUP);
  digitalWrite(btnMotor,HIGH);
  pinMode(btnRoot, INPUT_PULLUP);
  digitalWrite(btnRoot, HIGH); 

#endif

#ifdef BUTTON_ADC
// for a 10-bit ADC, each button is calibrated to the band between this value and the next value above (or 1023 for upper limit)
// The bands are intentionally set very wide, and far apart
// Each button acts as a voltage divider between 10k and the following resistors:
#define btnADCPlayLow 980 // 0 ohm
#define btnADCStopLow 900 // 1k ohm
#define btnADCRootLow 700 // 2.4k ohm
#define btnADCDownLow 400 // 10k ohm
#define btnADCUpLow 200 // 20k ohm
#endif

#endif // #define PINSETUP_H_INCLUDED
