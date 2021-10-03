
#include "Platform_Types.h"


#define RCC_BASE 0x40021000

#define RCC_APB2ENR *((volatile uint32_t *)(RCC_BASE + 0x18))


#define GPIOA_BASE 0x40010800

#define GPIOA_CRH *((volatile uint32_t *)(GPIOA_BASE + 0x04))

#define GPIOA_ODR *((volatile uint32_t *)(GPIOA_BASE + 0x0C))


#define RCC_IOPAEN 1<<2



typedef union
{
	 vuint32_t reg_value;
	struct
	{
		vuint32_t reserved: 13;
		vuint32_t pin13: 1;
	} spin;
} ODR_ut;

volatile ODR_ut *R_ODR = (volatile ODR_ut *)(GPIOA_BASE + 0x0C);

int main(void)
{
	uint32_t i;
	RCC_APB2ENR |= RCC_IOPAEN ;
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0X00200000;

	while(1)
	{
		
		R_ODR->spin.pin13 = 1;
		for(i = 0; i < 7000; i++);
		
		R_ODR->spin.pin13 = 0;
		for(i = 0; i < 7000; i++);
	}

	return 0;
}