CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m3 -gdwarf-2  -mthumb -g
INCS= -I .
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
LIB=
As=$(wildcard *.s)
AsOBJ=$(As:.s=.o)
ProjectName=cortex-M4
all: $(ProjectName).bin $(ProjectName).hex
		@echo "===============$(ProjectName) Build is done ================" 
%.o:%.s
	$(CC)as   $(CFLAGS) $< -o $@ 
%.o:%.c
	$(CC)gcc   $(CFLAGS) $(INCS) -c $< -o $@
$(ProjectName).elf:$(OBJ) $(AsOBJ) 
	$(CC)ld   -T Linker_Script.ld $(OBJ) $(AsOBJ) $(LIB) -o $@ -Map=Map_file.map
$(ProjectName).bin:$(ProjectName).elf
	$(CC)objcopy   -O binary $< $@
	cp $(ProjectName).elf $(ProjectName).axf
$(ProjectName).hex:$(ProjectName).elf
	$(CC)objcopy   -O ihex $< $@
clean :
	rm *.elf *.bin *.hex
clean_all:
	rm *.elf *.o *.bin *.hex *.axf
	@echo "===============$(ProjectName) clean is done ================" 