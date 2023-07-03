/*LINKER script FOR STM32F103C6*/
/*ENG : Ahmed Ali Mohammed*/


MEMORY
{
FLASH (RX) : ORIGIN = 0x08000000 ,LENGTH = 128K
SRAM (RWX) : ORIGIN = 0x20000000 , LENGTH = 20K

}

SECTIONS
{
	.text :
	{
	*(.vectors*)
	*(.text*)
	*(.rodata)
	_E_text = . ;
	}> FLASH
	.data :
	{
	_S_DATA = .;
	*(.data)
	_E_DATA = .;
	. = ALIGN(4);
	}> SRAM AT> FLASH
	
	.bss :
	{
	_S_BSS = .;
	*(.bss*)
	. = ALIGN(4);
	_E_BSS = .;
	. = ALIGN(4);
	. = . +0x1000;
	_stack_top = .;
	}> SRAM
}