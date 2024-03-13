#include <stdint.h>
#include "standard/drivers/display/display.cpp"
#include "standard/port/port.cpp"
extern "C" int GetEAXRegisterValue();
extern "C" int GetEBXRegisterValue();
extern "C" int GetECXRegisterValue();
extern "C" int GetEDXRegisterValue();
extern "C" int GetESIRegisterValue();
extern "C" int GetEDIRegisterValue();
extern "C" int GetEBPRegisterValue();
extern "C" int GetESPRegisterValue();
extern "C" int Test_INT();

extern "C" void PopErrorAndIRET(int intNum);
//include standard memory manager

Display display;
extern "C" void halt()
{
	display.SetColor(FG_BLACK, BG_WHITE);
	display.SetCursor(0, 0);
	display.PutChar('H');
	display.PutChar('A');
	display.PutChar('L');
	display.PutChar('T');
	display.PutChar('E');
	display.PutChar('D');
	display.PutChar('!');
	while (true) {asm("hlt");}
}
extern "C" void halt_notext()
{
	while (true) {asm("hlt");}
}
extern "C" void kernel_main()
{
	
	display.Init();
	//display.Clear();
	display.SetColor(FG_BLACK, BG_WHITE);
	//set eax to 0 and call interrupt 0x70
	Test_INT();
	halt_notext();
}

extern "C" void interrupt_handler( int interrupt_number )
{
	//if divide by zero, print error message and hlt
	if(interrupt_number == 0)
	{
		
	}
	else if (interrupt_number == 11)
	{

	}
	else if (interrupt_number == 13)
	{
		//push and iret
		PopErrorAndIRET(interrupt_number);
		return;
	}
	else if (interrupt_number == 32)
	{
		//Clock interrupt
	}
	else if (interrupt_number == 64)
	{
		//The kernel call to do something 0x40
		display.PutChar('I');
	}
	else if (interrupt_number == 112) // The kernel call to do something 0x70
	{
		display.PutChar('I');
	}
	else
	{
		display.PutInt(interrupt_number);
	}
}

extern "C" void PopErrorAndIRET(int intNum)
{
	asm("pop %eax");
	asm("iret");
}