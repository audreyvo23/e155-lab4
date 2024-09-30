// STM32L432KC_TIM.c
// Source code for RCC functions

#include "STM32L432KC_TIM.h"


void initTIMpwm(TIM_TypeDef * TIMx) {

  // auto-reload register and prescaler pg 959
  TIMx->TIMx_PSC = 39;
  // set auto-reload preload enable
  TIMx -> TIMx_CR1 |= (1 << 7);
  // set ARR to some random value
  TIMx->TIMx_ARR = 0xffff;



 // set CCMR1 to PWM mode pg 934
 TIMx->TIMx_CCMR1 &= ~(0b11 << 0);
 TIMx->TIMx_CCMR1 |= (1 << 6);
 TIMx->TIMx_CCMR1 |= (1 << 5);
 TIMx->TIMx_CCMR1 |= (1 << 3);

 // duty cycle
  TIMx->TIMx_CCR1 = TIMx->TIMx_ARR/2;

 // set CC1 channel as output
  //TIMx->TIMx_CCMR1 &= (0 << 1);
  //TIMx->TIMx_CCMR1 &= (0 << 0);

     
  // oc1 signal is on; capture compare 1 output enable
  TIMx -> TIMx_CCER |= (1 << 0);

  //main output enable OC and OCN outputs are enabled
  TIMx->TIMx_BDTR |= (1 << 15);

   // update generation set to 1 pg 953
  TIMx->TIMx_EGR |= (1 << 0);

  // enable counter for timer pg 950
  TIMx->TIMx_CR1 |= (1 << 0);

}

void setPitch(TIM_TypeDef * TIMx, uint32_t pitch) {

  // change arr bfore the while loop based on ms
 TIMx->TIMx_ARR = 100000/pitch;

    // set duty cycle of CCR1 to 50%
 TIMx->TIMx_CCR1 = TIMx->TIMx_ARR/2;

 // update generation set to 1 pg 953
 TIMx->TIMx_EGR |= (1 << 0);


 
}

void delay_millis(TIM_TypeDef * TIMx, uint32_t ms)  {
 // change arr bfore the while loop based on ms
 TIMx->TIMx_ARR = 100*ms;
 // update generation set to 1 pg 953
 //TIMx->TIMx_EGR |= (1 << 0);
  // reset counter to 0
 TIMx->TIMx_CNT = 0;
 // reset status register pg 953
 TIMx->TIMx_SR &= (0 << 1);
 TIMx->TIMx_SR &= (0 << 0);
 // check if status register is on
 // ((TIMx->TIMx_SR & 0b1) != 1)
 //(TIMx->TIMx_CNT < TIMx->TIMx_ARR)
  while((TIMx->TIMx_SR & 0b1) != 1) {
  }
__asm("nop");
}

void initTIMduration(TIM_TypeDef * TIMx) {
  // auto-reload register and prescaler pg 959
  TIMx->TIMx_PSC = 39;
  TIMx->TIMx_ARR |=  0xffff;
 // TIMx->TIMx_EGR |= (1 << 0);
  // enable counter for timer pg 950
  TIMx->TIMx_CR1 |= (1 << 0);
  TIMx->TIMx_CNT = 0;
}

