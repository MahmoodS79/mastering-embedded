
#include "Platform_Types.h"
#define RCC_BASE   0x40021000
#define PortA_BASE 0x40010800

#define RCC_APB2ENR  *(volatile uint32_t *) (RCC_BASE + 0x18)
#define GPIOA_CRH    *(volatile uint32_t *) (PortA_BASE + 0x04)
#define GPIOA_ODR    *(volatile uint32_t *) (PortA_BASE + 0x0C)


typedef union{
	uint32_t all_fields;
	struct{
		uint32_t reserved: 13;
		uint32_t P_13: 1;
	}Pin;
}R_ODR_t;
R_ODR_t* R_ODR = (R_ODR_t*)(PortA_BASE + 0x0C);


int main(void)
{
        int i;
	    RCC_APB2ENR |= 1<<2;
		GPIOA_CRH &= 0xFF0FFFFF;
		GPIOA_CRH |= 0x00200000;
		while(1){

				R_ODR->Pin.P_13 = 1;
				for( i = 0; i < 10000; i++);
				R_ODR->Pin.P_13 = 0;
				for( i = 0; i< 10000; i++);

			}



}
