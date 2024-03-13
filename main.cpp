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
//include standard memory manager
Display display;
extern "C" void KernelSystemCall( int system_call_number, int param1, int param2, int param3, int param4, int param5, int param6, int param7 );
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
	halt();
	//Test_INT();
	halt();
}

extern "C" void interrupt_handler( int interrupt_number )
{
	//if divide by zero, print error message and hlt
	if(interrupt_number == 0)
	{
		
	}
	else if (interrupt_number == 32)
	{
		//Clock interrupt
	}
	else if (interrupt_number == 112) // The kernel call to do something 0x70
	{
		// Get the system call number
		int system_call_number = GetEAXRegisterValue();
		// Get the parameters
		int param1 = GetEBXRegisterValue();
		int param2 = GetECXRegisterValue();
		int param3 = GetEDXRegisterValue();
		int param4 = GetESIRegisterValue();
		int param5 = GetEDIRegisterValue();
		int param6 = GetEBPRegisterValue();
		int param7 = GetESPRegisterValue();
		// Call the kernel system call
		halt();
		KernelSystemCall(system_call_number, param1, param2, param3, param4, param5, param6, param7);
	}
	else
	{
		display.PutInt(interrupt_number);
	}
}
extern "C" void KernelSystemCall( int system_call_number, int param1, int param2, int param3, int param4, int param5, int param6, int param7 )
{
	halt();
	//switch on the system call number
	switch (system_call_number)
	{
		
		case 0:
			display.PutChar('a');
			return;
			break;
	}
}

