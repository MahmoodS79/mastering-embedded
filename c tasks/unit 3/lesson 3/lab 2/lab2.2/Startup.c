#include "Platform_Types.h"

extern uint32 _E_text; 
extern uint32 _S_data; 
extern uint32 _E_data; 
extern uint32 _S_bss; 
extern uint32 _E_bss;
extern uint32 _Stack_top;
extern int main(void);


void Reset_Handler();
void NMI_Handler() __attribute__((weak, alias("Default_Handler")));
void H_Fault_Handler() __attribute__((weak, alias("Default_Handler")));
void MM_Fault_Handler() __attribute__((weak, alias("Default_Handler")));
void Bus_Fault_Handler() __attribute__((weak, alias("Default_Handler")));
void Usage_Fault_Handler() __attribute__((weak, alias("Default_Handler")));


uint32 vectors[] __attribute__((section(".vectors"))) = 
{
    (uint32) &_Stack_top,
    (uint32) &Reset_Handler,
    (uint32) &NMI_Handler,
    (uint32) &H_Fault_Handler,
    (uint32) &MM_Fault_Handler,
    (uint32) &Bus_Fault_Handler,
    (uint32) &Usage_Fault_Handler
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
