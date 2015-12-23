/*
*****************************************************************************



*****************************************************************************
*/



#define RCC_AHB1EN       (*((volatile unsigned long*)0x40023830))   //  enable registers
#define GPIOD_Mode       (*((volatile unsigned long*)0x40020c00))   //  make register(out_p or in_p or analog)
#define GPIOD_OTYPER     (*((volatile unsigned long*)0x40020c04))   // type of register(push_pull or open drain)
#define GPIOD_OSPEEDR    (*((volatile unsigned long*)0x40020c08))   // speed of register
#define GPIOD_PUPDR      (*((volatile unsigned long*)0x40020c0c))   // pull_up or pull_down
#define GPIOD_BRSRR      (*((volatile unsigned long*)0x40020c18))   //  set/reset register pins




void delay( long  count)
	{
		while(count--)
		{

		}

	 }

/**
**===========================================================================
**
**  Abstract: main program
**
**===========================================================================
*/
int main(void)
{

	    RCC_AHB1EN |= 0x00000008;    // enable register D
		GPIOD_Mode |= 0x01000000;    // pin 12--> out
		GPIOD_OTYPER &= 0xffffefff;  // pin 12--> push_pull
		GPIOD_OSPEEDR |= 0x01000000; //speed --> medium
		GPIOD_PUPDR &= 0xfcffffff;   // non pull_up /pull_down




  /* Infinite loop */
  while (1)
  {


	  GPIOD_BRSRR |=0xefffffff;   //set pin 12

      delay(16000000);      // delay

      GPIOD_BRSRR |=0xffffefff;   // reset pin 12

      delay(16000000);     // delay


  }
}


/*
 * Callback used by stm32f4_discovery_audio_codec.c.
 * Refer to stm32f4_discovery_audio_codec.h for more info.
 */
void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}

/*
 * Callback used by stm324xg_eval_audio_codec.c.
 * Refer to stm324xg_eval_audio_codec.h for more info.
 */
uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}
