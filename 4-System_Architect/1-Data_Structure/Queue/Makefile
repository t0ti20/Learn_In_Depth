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
CC=
#Compiler Flags
CFLAGS= -g
#Linker Flags
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
OBJ=$(SRC:.c=.o) $(SRS:.s=.o)
Application=Application
#*******************************************************************
#*******************************************************************
Make: $(Application)
	@rm -rf *.o
	@./$(Application)
#Compile And Assimble C Files Files
%.o:%.c
	@$(CC)gcc $(CFLAGS) -c $< $(INCS) -o $@
#Assimble Assimply Files
%.o:%.s
	@$(CC)as $(CFLAGS) $< -o $@
#Link All Files And Generate ELF File
$(Application): $(OBJ)
	@gcc $(OBJ) -o $@ 
#Clean All Files
clean:
	@rm -rf *.o $(Application)
	@echo "========== Done Cleaning =========="
#*******************************************************************
#*******************************************************************
