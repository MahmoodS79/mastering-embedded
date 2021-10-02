CC= arm-none-eabi-
MACH= cortex-m4
CFLAGS= -mcpu=$(MACH) -mthumb -gdwarf-2 -g 
INCS= -I.
LIBS=
O_OPERATOR=-h 
O_FILE= Cortex-m4_lab3.elf
OBJ= main.o Startup.o
PROJECT_NAME=Cortex-m4_lab3

all: $(PROJECT_NAME).bin

 

%.o:%.c
	$(CC)gcc $(CFLAGS) -c $(INCS) $^ -o $@ 

$(PROJECT_NAME).elf:LinkerScript.ld $(OBJ)
	$(CC)ld -T $(LIBS) $^ -o $@  -Map=$(PROJECT_NAME).map


$(PROJECT_NAME).bin:$(PROJECT_NAME).elf
	$(CC)objcopy $^ -O binary $@  
	
nm:
	$(CC)nm   $(PROJECT_NAME).elf
	
O_analyze:
	$(CC)objdump $(O_OPERATOR) $(O_FILE)

clean:
	rm *.o *.bin
clean_all:
	rm *.o *.bin *.elf *.map

sim: 
	qemu-system-arm -M versatilepb -m 128M -nographic -kernel $(PROJECT_NAME).bin
start_debug:
	qemu-system-arm -M versatilepb -m 128M -nographic -s -S -kernel $(PROJECT_NAME).bin
load:
	openocd -f 'C:\Users\Sence79\Desktop\xpack-openocd-0.10.0-15\scripts\board\stm32f4discovery.cfg'
