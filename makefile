CC 	   = arm-none-eabi-gcc

MACH   = cortex-m4 

CFLAGS = -c -mcpu=$(MACH)  -mthumb -std=gnu11 -Wall       # Wall for Warning for all(Force Warning)


main.o : main.c
	$(CC) $(CFLAGS) $^ -o $@

MGPIO_Program.o : MGPIO_Program.c
	$(CC) $(CFLAGS) $^ -o $@

STM32_startup.o : STM32_startup.c
	$(CC) $(CFLAGS) $^ -o $@
 
Startup_Secions : STM32_startup.o
	arm-none-eabi-objdump -h STM32_startup.o
	arm-none-eabi-objdump -d STM32_startup.o
	arm-none-eabi-objdump -D STM32_startup.o


clean : 										# remove force all extensions files 
	rm -rf *.o *.elf *.txt *.s     				


MakeALL : main.o MGPIO_Program.o STM32_startup.o