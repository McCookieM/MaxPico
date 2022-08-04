/*
 *  Interrupt and PWM utilities for 16 bit Timer1 on ATmega168/328
 *  Original code by Jesse Tane for http://labs.ideo.com August 2008
 */

#define TIMER1_A_PIN   9
#define TIMER1_B_PIN   10
#define TIMER1_ICP_PIN 8
#define TIMER1_CLK_PIN 5

#define TIMER1_RESOLUTION 65536UL  // Timer1 is 16 bit

// Placing nearly all the code in this .h file allows the functions to be
// inlined by the compiler.  In the very common case with constant values
// the compiler will perform all calculations and simply write constants
// to the hardware registers (for example, setPeriod).

#if defined(__RASPBERRY_PI_PICO__)
  #include "RPi_Pico_TimerInterrupt.h"

  class TimerCounter : public RPI_PICO_Timer
  {
    typedef void (*timerCallback) ();
    
    public:
      TimerCounter(uint8_t numTimer) : RPI_PICO_Timer(numTimer) {};
      
      void setTimer(unsigned long microseconds, void (*callback)()) {
        _callback = callback;
        this->attachInterruptInterval(microseconds, (pico_timer_callback)_callback);
      }

      void setPeriod(unsigned long microseconds) __attribute__((always_inline)) {
        setTimer(microseconds, _callback);
      }

      void pause() {
        this->detachInterrupt();
      }
        
      void resume() {
        this->reattachInterrupt();
      }

    private:
      timerCallback _callback = NULL;
  };

#else
#error Missing definition of TimerCounter
#endif
//extern TimerCounter Timer1;
