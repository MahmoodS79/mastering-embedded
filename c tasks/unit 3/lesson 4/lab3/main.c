
#include "Platform_Types.h"

#define SYSCTL_RCGC2_BASE  0x400FE000
#define Port_F  0x40025000
#define SYSCTL  *((volatile uint32_t *)(SYSCTL_RCGC2_BASE+0x108))
#define GPIO_PORTF_DATA_R  *((volatile uint32_t *)(Port_F+0x3FC))
#define GPIO_PORTF_DIR_R   *((volatile uint32_t *)(Port_F+0x400))
#define GPIO_PORTF_DEN_R *((volatile uint32_t *)(Port_F+0x51C))



int main(void)
{
        SYSCTL|=0x00000020; 
	volatile uint64_t delay;
	for(delay=0;delay<7000;delay++); 
	GPIO_PORTF_DEN_R  |=1<<3;
	GPIO_PORTF_DIR_R  |=1<<3;
	while(1){
		GPIO_PORTF_DATA_R |=1<<3;
		for(delay=0;delay<70000;delay++);
		GPIO_PORTF_DATA_R &=~(1<<3);
		for(delay=0;delay<70000;delay++);
	}


}
