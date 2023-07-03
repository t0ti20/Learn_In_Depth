#*******************************************************************
# *  FILE DESCRIPTION
#-----------------------
# *  Author:  Khaled El-Sayed (@t0ti20)
# *  Created:  05.02.2023
# *  File:  Makefile
# *  Module:  Global
# *  Description:  Make File For Auto Generation
#*******************************************************************
#Compiler Name
CC=arm-none-eabi-
#Compiler Flags
CFLAGS= -g -mcpu=cortex-m3 -gdwarf-2 -mthumb
#Linker Flags
LFLAGS= -Map=Map_File.map
INCS= \
		-I .
LIBS= 
#*******************************************************************
#*******************************************************************
# (@)					-hide command
# (%.o)					-all object files
# $(CC)					-replace variable
# ($<)					-One Dependency at time
# ($@)					-One Output at time
# ($(wildcard *.c))		-all fiiles .c
# $(CC)					-replace variable
#Generate Hex File
#*******************************************************************
#*******************************************************************
SRC=$(wildcard *.c)
SRS=$(wildcard *.s)
SRL=$(wildcard *.ld)
OBJ=$(SRC:.c=.o) $(SRS:.s=.o)
Application=Application
#*******************************************************************
#*******************************************************************
Make: $(Application).hex
	@echo "========== Build Finished ========="
#Compile And Assimble C Files Files
%.o:%.c
	@$(CC)gcc $(CFLAGS) $(INCS) -c $< -o $@
#Assimble Assimply Files
%.o:%.s
	@$(CC)as $(CFLAGS) $< -o $@
#Link All Files And Generate ELF File
$(Application).elf: $(OBJ)
	@$(CC)ld $(LFLAGS) -T $(SRL) $(OBJ) $(LIBS) -o $@ 
#Generate Hex File
$(Application).hex: $(Application).elf
	@$(CC)objcopy -O ihex $< $@
#Clean All Files
clean:
	@rm -rf *.hex *.elf *.o *.map
	@echo "========== Done Cleaning =========="
#*******************************************************************
#*******************************************************************
