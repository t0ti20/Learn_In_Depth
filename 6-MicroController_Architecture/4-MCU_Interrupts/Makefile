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
LOCA= ./Application
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
SRC=$(shell find $(SOURCEDIR) -name '*.c')
SRS=$(shell find $(SOURCEDIR) -name '*.s')
SRL=$(shell find $(SOURCEDIR) -name '*.ld')
OBJ=$(SRC:.c=.o) $(SRS:.s=.o)
Application=Application
#*******************************************************************
#*******************************************************************
Make: $(Application).hex
	@find $(SOURCEDIR) -path ./Debug -prune -o -type f -iname '*.map' -exec mv -t Debug {} +
	@find $(SOURCEDIR) -path ./Debug -prune -o -type f -iname '*.o' -exec mv -t Debug {} +
	@echo "========== Build Finished ========="
#Compile And Assimble C Files Files
%.o:%.c
	@$(CC)gcc $(CFLAGS) -c $< $(INCS) -o $@
#Assimble Assimply Files
%.o:%.s
	@$(CC)as $(CFLAGS) $< -o $@
#Link All Files And Generate ELF File
$(Application).elf: $(OBJ)
	@$(CC)ld $(LFLAGS) -T $(SRL) $(OBJ) $(LIBS) -o ./Debug/$@ 
#Generate Hex File
$(Application).hex: $(Application).elf
	@$(CC)objcopy -O ihex ./Debug/$< ./Debug/$@ 
#Clean All Files
clean:
	@find $(SOURCEDIR) -name '*.o' -exec rm {} \;
	@find $(SOURCEDIR) -name '*.hex' -exec rm {} \;
	@find $(SOURCEDIR) -name '*.elf' -exec rm {} \;
	@find $(SOURCEDIR) -name '*.map' -exec rm {} \;
	@echo "========== Done Cleaning =========="
#*******************************************************************
#*******************************************************************
