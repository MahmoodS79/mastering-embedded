ENTRY(reset)

MEMORY{
	MEM(RWX):ORIGIN =0x00000000,LENGTH =64M
	


}

SECTIONS{
	. = 0x10000;
	.reset . :
	{
		Startup.o(.text)
		
	}>MEM
	.text  :
	{
		*(.text)
		*(.rodata)
		
		
	}>MEM
	
	.data :
	{
	*(.data)
	}>MEM
	
	.bss :
	{
	*(.bss)
	}>MEM
	
	. = . + 0x1000;
	_stack_p = .;


}