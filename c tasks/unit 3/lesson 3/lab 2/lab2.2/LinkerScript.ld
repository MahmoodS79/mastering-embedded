ENTRY(Reset_Handler)		

MEMORY{
    flash (rx)  : ORIGIN = 0x08000000, LENGTH = 128k
    SRAM (rwx)  : ORIGIN = 0x20000000, LENGTH = 20k
}
SECTIONS{

    .text : {
        *(.vectors*)
        *(.text*)  
        *(.rodata*)
        _E_text = .;    /*tracking the flash*/
    }> flash
    
	.data : {
        _S_data = .;
        *(.data*)       /*is put originally on the flash*/
		. = ALIGN(4);
		_E_data = .;    /*tracking the ram*/
    }> SRAM AT> flash 
       
	.bss : {
        _S_bss = .;
        *(.bss*)
		. = ALIGN (4);
        _E_bss = .;
       }>SRAM
	   
	    . = . + 0x1000;
        _Stack_top = .;
	   
}