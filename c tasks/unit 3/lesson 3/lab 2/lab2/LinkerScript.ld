
MEMORY
{
    Flash (RX): ORIGIN = 0x08000000, LENGTH = 128K
    SRAM (RWX): ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{
    .text :
    {
        *(.vectors*)
        *(.text*)
    } > Flash
    
    .bss :
    {
        *(.bss*)
    } > SRAM
}