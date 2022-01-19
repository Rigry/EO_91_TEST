#define STM32F030x6
#define F_OSC   8000000UL
#define F_CPU   48000000UL

#include "init_clock.h"
#include "periph_rcc.h"
#include "periph_flash.h"
#include "flash.h"
#include "pin.h"
#include "adc.h"
#include "button.h"
#include "NTC_table.h"
#include "buzzer.h"
#include "seven_segment_indicator.h"

/// эта функция вызывается первой в startup файле
extern "C" void init_clock () { init_clock<F_CPU>(); }

using BUZZER = mcu::PA8;

using A  = mcu::PA6;
using B  = mcu::PA7;
using C  = mcu::PB0;
using D  = mcu::PB1;
using E  = mcu::PB2;
using F  = mcu::PB10;
using G  = mcu::PB11;
using H  = mcu::PB12;
using K1 = mcu::PB3;
using K2 = mcu::PA15;
using K3 = mcu::PB9;
using K4 = mcu::PB8;
using K5 = mcu::PB7;
using K6 = mcu::PB6;

int main()
{
   decltype (auto) pwm = PWM::make<mcu::Periph::TIM1, BUZZER>();
   Buzzer buzzer{pwm};

   SSI<A, B, C, D, E, F, G, H, K1, K2, K3, K4, K5, K6> ssi{};

   buzzer.longer();

   while(1){

      ssi.buffer[0] = 8;
      ssi.buffer[1] = 8;
      ssi.buffer[2] = 8;
      ssi.buffer[3] = 8;
      ssi.buffer[4] = 8;
      ssi.buffer[5] = 8;

      ssi.point[0]  = true;
      ssi.point[1]  = true;
      ssi.point[2]  = true;
      ssi.point[3]  = true;
      ssi.point[4]  = true;
      ssi.point[5]  = true;

   }

}



