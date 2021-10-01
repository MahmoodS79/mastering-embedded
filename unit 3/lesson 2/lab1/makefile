CC= arm-none-eabi-
MACH= arm926ej-s
CFLAGS= -mcpu=$(MACH) -g 
INCS= -I.
LIBS=
OBJ= Uart.o app.o Startup.o
O_OPERATOR= -h
O_FILE= Learn-In-Depth.elf
PROJECT_NAME=Learn-In-Depth


all: $(PROJECT_NAME).bin

Startup.o:Startup.s
	$(CC)as $(CFLAGS) $^ -o $@ 

%.o:%.c
	$(CC)gcc $(CFLAGS) -c $(INCS) $^ -o $@ 

$(PROJECT_NAME).elf:LinkerScript.ld $(OBJ)
	$(CC)ld -T $(LIBS) $^ -o $@ -Map=$(PROJECT_NAME).map


$(PROJECT_NAME).bin:$(PROJECT_NAME).elf
	$(CC)objcopy $^ -O binary $@
	cp $(PROJECT_NAME).bin $(PROJECT_NAME).axf

O_analyze:
	$(CC)objdump $(O_OPERATOR) $(O_FILE)
	
nm:
	$(CC)nm $(O_FILE)

	

clean:
	rm *.o *.bin
clean_all:
	rm *.o *.bin *.elf *.map
	
sim: 
	qemu-system-arm -M versatilepb -m 128M -nographic -kernel Learn-In-Depth.bin
start_debug:
	qemu-system-arm -M versatilepb -m 128M -nographic -s -S -kernel Learn-In-Depth.bin
load:
	openocd -f 'C:\Users\Sence79\Desktop\xpack-openocd-0.10.0-15\scripts\board\stm32f4discovery.cfg'
