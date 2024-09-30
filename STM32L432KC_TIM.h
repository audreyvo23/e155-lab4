// STM32L432KC_TIM.h
// Header for RCC functions

#ifndef STM32L4_TIM_H
#define STM32L4_TIM_H

#include <stdint.h>

///////////////////////////////////////////////////////////////////////////////
// Definitions
///////////////////////////////////////////////////////////////////////////////

#define __IO volatile

// Base addresses
#define TIM16_BASE (0x40014400UL) // base address of Tim16
#define TIM15_BASE (0x40014000UL) // base address of Tim15



typedef struct
{
  __IO uint32_t TIMx_CR1;          /*!< RCC clock control register,                                              Address offset: 0x00 */
  __IO uint32_t TIMx_CR2;       /*!< RCC internal clock sources calibration register,                         Address offset: 0x04 */
    uint32_t      RESERVED;   /*!< Reserved,                                                                Address offset: 0x08 */
  __IO uint32_t TIMx_DIER;        /*!< RCC clock configuration register,                                        Address offset: 0x0C */
  __IO uint32_t TIMx_SR;     /*!< RCC system PLL configuration register,                                   Address offset: 0x10 */
  __IO uint32_t TIMx_EGR; /*!< RCC PLL SAI1 configuration register,                                     Address offset: 0x14 */
  __IO uint16_t TIMx_CCMR1;        /*!< RCC clock interrupt enable register,                                     Address offset: 0x18 */
    uint32_t      RESERVED1;   /*!< Reserved,                                                                Address offset: 0x1C */
  __IO uint32_t TIMx_CCER;        /*!< RCC clock interrupt clear register,                                      Address offset: 0x20 */
  __IO uint32_t TIMx_CNT;    /*!< RCC AHB1 peripheral reset register,                                      Address offset: 0x24 */
  __IO uint32_t TIMx_PSC;    /*!< RCC AHB2 peripheral reset register,                                      Address offset: 0x28 */
  __IO uint32_t TIMx_ARR;    /*!< RCC AHB3 peripheral reset register,                                      Address offset: 0x2C */
  __IO uint32_t TIMx_RCR;   /*!< RCC APB1 peripheral reset register 1,                                    Address offset: 0x30 */
  __IO uint32_t TIMx_CCR1;   /*!< RCC APB1 peripheral reset register 2,                                    Address offset: 0x34 */
   uint32_t      RESERVED2;   /*!< Reserved,                                                                Address offset:0x38 */
   uint32_t      RESERVED3;   /*!< Reserved,                                                                Address offset: 0x3C */
   uint32_t      RESERVED4;   /*!< Reserved,                                                                Address offset:0x40 */
  __IO uint32_t TIMx_BDTR;    /*!< RCC APB2 peripheral reset register,                                      Address offset: 0x44 */
  __IO uint32_t TIMx_DCR;     /*!< RCC AHB1 peripheral clocks enable register,                              Address offset: 0x48 */
  __IO uint32_t TIMx_DMAR;     /*!< RCC AHB2 peripheral clocks enable register,                              Address offset: 0x4C */
  __IO uint32_t TIM16_OR1;     /*!< RCC AHB3 peripheral clocks enable register,                              Address offset: 0x50 */
     uint32_t      RESERVED5;   /*!< Reserved,                                                                Address offset:0x54 */
     uint32_t      RESERVED6;   /*!< Reserved,                                                                Address offset:0x58 */
     uint32_t      RESERVED7;   /*!< Reserved,                                                                Address offset:0x5C */
  __IO uint32_t TIM16_OR2;    /*!< RCC APB1 peripheral clocks enable register 1,                            Address offset: 0x60 */
} TIM_TypeDef;

#define TIM16 ((TIM_TypeDef *) TIM16_BASE)
#define TIM15 ((TIM_TypeDef *) TIM15_BASE)

///////////////////////////////////////////////////////////////////////////////
// Function prototypes
///////////////////////////////////////////////////////////////////////////////

void initTIMpwm(TIM_TypeDef * TIMx);
void delay_millis(TIM_TypeDef * TIMx, uint32_t ms);
void initTIMduration(TIM_TypeDef * TIMx);
void setPitch(TIM_TypeDef * TIMx, uint32_t Hz);


#endif