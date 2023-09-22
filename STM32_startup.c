#include <stdint.h>


/* Calculater the MSP value */
#define SRAM_START          0x20000000UL
#define SRAM_SIZE           96*1024             //For the STM32f401CC  the Size RAM = 96 KB and every location = 4 Bytes// then all addersses  = 96*(2^32)
#define SRAM_END            ( (SRAM_START) + (SRAM_SIZE) )
#define MSP_VALUE           SRAM_END

/*
it Not recommended because we have some problems
problems 
    1- Hadek in me because i will write all expention 
    2- Vector array will Stored in .data section 
    3- if write the handler will be empty and the compiler when call this Handler it work the some instruction for context switching , 
       this instruction will stored in flash and will give size Ex=1KB which the handlers will empety?
    4- if i write the Handlers here  ,and user will write it in main it will have Linker Error because multiFunction 

void Reset_Handler(void)
{

}

void NMI_Handler(void)
{

}

void HardFault_Handler(void)
{

}
*/


/***************************************************************************************************************/
/***************** Prototypes Function using Weak and Aliasing Name to Default_Handler *************************/
/***************************************************************************************************************/
void Reset_Handler(void);
void Default_Handler(void);

void NMI_Handler 					(void) __attribute__ ((weak, alias("Default_Handler")));
void HardFault_Handler 				(void) __attribute__ ((weak, alias("Default_Handler")));
void MemManage_Handler 				(void) __attribute__ ((weak, alias("Default_Handler")));
void BusFault_Handler 				(void) __attribute__ ((weak, alias("Default_Handler")));
void UsageFault_Handler 			(void) __attribute__ ((weak, alias("Default_Handler")));
void SVC_Handler 					(void) __attribute__ ((weak, alias("Default_Handler")));
void DebugMon_Handler 				(void) __attribute__ ((weak, alias("Default_Handler")));
void PendSV_Handler   				(void) __attribute__ ((weak, alias("Default_Handler")));
void SysTick_Handler  				(void) __attribute__ ((weak, alias("Default_Handler")));
void WWDG_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));
void PVD_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));             
void TAMP_STAMP_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));      
void RTC_WKUP_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler"))); 
void FLASH_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));             
void RCC_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));             
void EXTI0_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));           
void EXTI1_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));           
void EXTI2_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));           
void EXTI3_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));           
void EXTI4_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));           
void DMA1_Stream0_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));    
void DMA1_Stream1_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));    
void DMA1_Stream2_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));    
void DMA1_Stream3_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));    
void DMA1_Stream4_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));    
void DMA1_Stream5_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));    
void DMA1_Stream6_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));    
void ADC_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));             
void EXTI9_5_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));         
void TIM1_BRK_TIM9_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));   
void TIM1_UP_TIM10_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));   
void TIM1_TRG_COM_TIM11_IRQHandler 	(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM1_CC_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));         
void TIM2_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));            
void TIM3_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));            
void TIM4_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));            
void I2C1_EV_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));         
void I2C1_ER_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));         
void I2C2_EV_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));         
void I2C2_ER_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));         
void SPI1_IRQHandler  				(void) __attribute__ ((weak, alias("Default_Handler")));           
void SPI2_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));            
void USART1_IRQHandler  			(void) __attribute__ ((weak, alias("Default_Handler")));         
void USART2_IRQHandler  			(void) __attribute__ ((weak, alias("Default_Handler")));        
void EXTI15_10_IRQHandler   		(void) __attribute__ ((weak, alias("Default_Handler")));     
void RTC_Alarm_IRQHandler    		(void) __attribute__ ((weak, alias("Default_Handler")));    
void DMA1_Stream7_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void SDIO_IRQHandler             	(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM5_IRQHandler             	(void) __attribute__ ((weak, alias("Default_Handler")));
void SPI3_IRQHandler             	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream0_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream1_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream2_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream3_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream4_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void OTG_FS_IRQHandler           	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream5_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream6_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream7_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void USART6_IRQHandler           	(void) __attribute__ ((weak, alias("Default_Handler")));
void I2C3_EV_IRQHandler          	(void) __attribute__ ((weak, alias("Default_Handler")));
void I2C3_ER_IRQHandler          	(void) __attribute__ ((weak, alias("Default_Handler")));
void FPU_IRQHandler          	    (void) __attribute__ ((weak, alias("Default_Handler")));        
void SPI4_IRQHandler             	(void) __attribute__ ((weak, alias("Default_Handler")));                 





/***************************************************************************************************************/
/*********** Array Which stored the addresses function in Vector table in section .Isr_Vectors *****************/
/***************************************************************************************************************/


uint32_t Vectors[]  __attribute__ ((section(".isr_vector"))) =
{
    //First we needed the value of SP this is the SIZE of SRAM (Full descending) -->> SP will pointed the Top address in SRAM and decrement every push 
MSP_VALUE,									
(uint32_t)&Reset_Handler,
(uint32_t)&NMI_Handler,
(uint32_t)&HardFault_Handler,
(uint32_t)&MemManage_Handler,
(uint32_t)&BusFault_Handler,
(uint32_t)&UsageFault_Handler,
0,
0,
0,
0,
(uint32_t)&SVC_Handler,
(uint32_t)&DebugMon_Handler,
0,
(uint32_t)&PendSV_Handler,
(uint32_t)&SysTick_Handler,
0,                            					/* Reserved                                                           */		
(uint32_t)&PVD_IRQHandler,                      /* PVD through EXTI line detection interrupt                          */
(uint32_t)&TAMP_STAMP_IRQHandler,               /* Tamper and TimeStamp interrupts through the EXTI line              */
(uint32_t)&RTC_WKUP_IRQHandler,                 /* RTC Wakeup interrupt through the EXTI line                         */
(uint32_t)&FLASH_IRQHandler,                    /* FLASH global interrupt                                             */
(uint32_t)&RCC_IRQHandler,                      /* RCC global interrupt                                               */
(uint32_t)&EXTI0_IRQHandler,                    /* EXTI Line0 interrupt                                               */
(uint32_t)&EXTI1_IRQHandler,                    /* EXTI Line1 interrupt                                               */
(uint32_t)&EXTI2_IRQHandler,                    /* EXTI Line2 interrupt                                               */
(uint32_t)&EXTI3_IRQHandler,                    /* EXTI Line3 interrupt                                               */
(uint32_t)&EXTI4_IRQHandler,                    /* EXTI Line4 interrupt                                               */
0,                                              /* Reserved                                                           */
0,                                              /* Reserved                                                           */
0,                                              /* Reserved                                                           */
0,                                              /* Reserved                                                           */
0,                                              /* Reserved                                                           */
0,                                              /* Reserved                                                           */
0,                                              /* Reserved                                                           */
(uint32_t)&ADC_IRQHandler,                      /* ADC1 global interrupt                                              */
0,                                              /* Reserved                                                           */
0,                                              /* Reserved                                                           */
0,                                              /* Reserved                                                           */
0,                                              /* Reserved                                                           */
(uint32_t)&EXTI9_5_IRQHandler,                  /* EXTI Line[9:5] interrupts                                          */
(uint32_t)&TIM1_BRK_TIM9_IRQHandler,            /* TIM1 Break interrupt and TIM9 global interrupt                     */
(uint32_t)&TIM1_UP_TIM10_IRQHandler,            /* TIM1 Update interrupt and TIM10 global interrupt                   */
(uint32_t)&TIM1_TRG_COM_TIM11_IRQHandler,       /* TIM1 Trigger and Commutation interrupts and TIM11 global interrupt */
(uint32_t)&TIM1_CC_IRQHandler,                  /* TIM1 Capture Compare interrupt                                     */
(uint32_t)&TIM2_IRQHandler,                     /* TIM2 global interrupt                                              */
(uint32_t)&TIM3_IRQHandler,                     /* TIM3 global interrupt                                              */
0,                                              /* Reserved                                                           */
(uint32_t)&I2C1_EV_IRQHandler,                  /* I2C1 event interrupt                                               */
(uint32_t)&I2C1_ER_IRQHandler,                  /* I2C1 error interrupt                                               */
(uint32_t)&I2C2_EV_IRQHandler,                  /* I2C2 event interrupt                                               */
(uint32_t)&I2C2_ER_IRQHandler,                  /* I2C2 error interrupt                                               */
(uint32_t)&SPI1_IRQHandler,                     /* SPI1 global interrupt                                              */
(uint32_t)&SPI2_IRQHandler,                     /* SPI2 global interrupt                                              */
0,                                              /* Reserved                                                           */
0,                                              /* Reserved                                                           */
0,                                              /* Reserved                                                           */
(uint32_t)&EXTI15_10_IRQHandler,                /* EXTI Line[15:10] interrupts                                        */
(uint32_t)&RTC_Alarm_IRQHandler,                /* RTC Alarms (A and B) through EXTI line interrupt                   */
(uint32_t)&OTG_FS_IRQHandler,                   /* USB On-The-Go FS Wakeup through EXTI line interrupt                */
0,                                              /* Reserved                                                           */
0,                                              /* Reserved                                                           */
0,                                              /* Reserved                                                           */
0,                                              /* Reserved                                                           */
0,                                              /* Reserved                                                           */
0,                                              /* Reserved                                                           */
(uint32_t)&SDIO_IRQHandler,                     /* SDIO global interrupt                                              */
0,                                              /* Reserved                                                           */
(uint32_t)&SPI3_IRQHandler,                     /* SPI3 global interrupt                                              */
0,                                              /* Reserved                                                           */
0,                                              /* Reserved                                                           */
0,                                              /* Reserved                                                           */
0,                                              /* Reserved                                                           */
0,                                              /* Reserved                                                           */
0,                                              /* Reserved                                                           */
0,                                              /* Reserved                                                           */
0,                                              /* Reserved                                                           */
0,                                              /* Reserved                                                           */
0,                                              /* Reserved                                                           */
0,                                              /* Reserved                                                           */
0,                                              /* Reserved                                                           */
0,                                              /* Reserved                                                           */
0,                                              /* Reserved                                                           */
0,                                              /* Reserved                                                           */
(uint32_t)&OTG_FS_IRQHandler,                   /* USB On The Go FS global interrupt                                  */
0,                                              /* Reserved                                                           */
0,                                              /* Reserved                                                           */
0,                                              /* Reserved                                                           */
0,                                              /* Reserved                                                           */
(uint32_t)&I2C3_EV_IRQHandler,                  /* I2C3 event interrupt                                               */
(uint32_t)&I2C3_ER_IRQHandler,                  /* I2C3 error interrupt                                               */
0,                                              /* Reserved                                                           */
0,                                              /* Reserved                                                           */
0,                                              /* Reserved                                                           */
0,                                              /* Reserved                                                           */
0,                                              /* Reserved                                                           */
0,                                              /* Reserved                                                           */
0,                                              /* Reserved                                                           */
(uint32_t)&FPU_IRQHandler,                      /* Floating point interrupt                                           */
0,                                              /* Reserved                                                           */
0,                                              /* Reserved                                                           */
(uint32_t)&SPI4_IRQHandler                      /* SPI4 global interrupt                                              */
};



void Default_Handler(void)
{
    while (1)
    {
        /* code */
    }
    
}


void Reset_Handler(void)
{
    
}
