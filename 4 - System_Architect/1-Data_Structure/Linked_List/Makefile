#*******************************************************************
# *  FILE DESCRIPTION
#-----------------------
# *  Author:  Khaled El-Sayed (@t0ti20)
# *  Created:  05.02.2023
# *  File:  Makefile
# *  Module:  Global
# *  Description:  Make File For Auto Generation
#*******************************************************************
#Compiler Flags
CFLAGS= 
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
Application=Application
#*******************************************************************
#*******************************************************************
Make: $(Application)
	@./$(Application)
#Link All Files And Generate ELF File
$(Application): $(SRC)
	@gcc $(CFLAGS) $(SRC) $(INCS) $(LIBS) -o $@ 
#Clean All Files
clean:
	@rm -rf *.o $(Application)
	@echo "========== Done Cleaning =========="
#*******************************************************************
#*******************************************************************
