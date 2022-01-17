#pragma once

#include "pin.h"
#include "timers.h"
#include "NTC_table.h"
#include "literals.h"
#include "seven_segment_indicator.h"


template<class SSI>
class UZV
{

public:

   UZV (Buzzer& buzzer)  : buzzer      {buzzer}
   {
      buzzer.longer();
   }

   void operator() () {

   }

private:
 
   SSI ssi;

   Buzzer& buzzer;

   Timer refresh {500_ms};
   Timer timer;
   
};