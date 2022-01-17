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
#include "uzv.h"

/// эта функция вызывается первой в startup файле
extern "C" void init_clock () { init_clock<F_CPU>(); }

using BUZZER = mcu::PA8;

using A  = mcu::PB10;
using B  = mcu::PB2;
using C  = mcu::PB0;
using D  = mcu::PA7;
using E  = mcu::PA6;
using F  = mcu::PB12;
using G  = mcu::PB11;
using H  = mcu::PB1;
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

   UZV<SSI<A, B, C, D, E, F, G, H, K1, K2, K3, K4, K5, K6>> uzv (buzzer);

   while(1){

      uzv();

      __WFI();
   }

}



