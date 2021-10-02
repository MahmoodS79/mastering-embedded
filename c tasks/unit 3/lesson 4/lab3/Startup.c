#include "Platform_Types.h"

extern uint32 _E_text; 
extern uint32 _S_data; 
extern uint32 _E_data; 
extern uint32 _S_bss; 
extern uint32 _E_bss; 
extern int main(void);


void Reset_Handler();
void NMI_Handler() __attribute__((weak, alias("Default_Handler")));
void H_Fault_Handler() __attribute__((weak, alias("Default_Handler")));
void MM_Fault_Handler() __attribute__((weak, alias("Default_Handler")));
void Bus_Fault_Handler() __attribute__((weak, alias("Default_Handler")));
void Usage_Fault_Handler() __attribute__((weak, alias("Default_Handler")));

static uint32 stack[256]; // above & including .bss 256 x 4 bytes = 1024B        1024B+.bss

void (* const vectors[])() __attribute__((section(".vectors"))) = 
{
    (void (*)()) (stack + sizeof(stack)),
    (void (*)())&Reset_Handler,
    (void (*)())&NMI_Handler,
    (void (*)())&H_Fault_Handler,
    (void (*)())&MM_Fault_Handler,
    (void (*)())&Bus_Fault_Handler,
    (void (*)())&Usage_Fault_Handler
};
//pointer to array of functions
void Default_Handler()
{
    Reset_Handler();
}

void Reset_Handler()
{
    uint32 _data_size =(uint32)&_E_data - (uint32)&_S_data
    , _bss_size=(uint32)&_E_bss - (uint32)&_S_bss, i;
    uint8 *_src_ptr, *_dst_ptr;

    
    _src_ptr = (uint8 *)&_E_text; //flash
    _dst_ptr = (uint8 *)&_S_data; //sram

    for(i = 0; i < _data_size; i++)
    {
        *_dst_ptr++ = *_src_ptr++;
    }

    
    _dst_ptr = (uint8 *)&_S_bss;
    
    for(i = 0; i < _bss_size; i++)
    {
        *_dst_ptr++ = 0;
    }

    
    main();
}
