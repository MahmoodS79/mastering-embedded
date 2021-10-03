CC= arm-none-eabi-
MACH= cortex-m3
CFLAGS= -mcpu=$(MACH) -mthumb -gdwarf-2 -g 
INCS= -I.
LIBS=
O_OPERATOR=-h 
O_FILE= Cortex-m3_lab2.elf
OBJ= main.o StartupS.o
PROJECT_NAME=Cortex-m3_lab2

all: $(PROJECT_NAME).bin

StartupS.o:StartupS.s
	$(CC)as $(CFLAGS) $^ -o $@

%.o:%.c
	$(CC)gcc $(CFLAGS) -c $(INCS) $^ -o $@ 

$(PROJECT_NAME).elf:LinkerScript.ld $(OBJ)
	$(CC)ld -T $(LIBS) $^ -o $@  -Map=$(PROJECT_NAME).map


$(PROJECT_NAME).bin:$(PROJECT_NAME).elf
	$(CC)objcopy $^ -O binary $@  
	
nm:
	$(CC)nm   $(O_FILE)
	
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
