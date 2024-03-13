; Functions for CPP

[global GetEAXRegisterValue] ; C++ funct to include: extern "C" int GetEAXRegisterValue();
[global GetEBXRegisterValue]
[global GetECXRegisterValue]
[global GetEDXRegisterValue]
[global GetESIRegisterValue]
[global GetEDIRegisterValue]
[global GetEBPRegisterValue]
[global GetESPRegisterValue]
[global GetTopStackValue]
[global GetSegmentNotPresentInstruction] ;C function to include: extern "C" int GetSegmentNotPresentInstruction();
[global Test_INT]

GetEAXRegisterValue:
    ret ; Return the value of EAX

GetEBXRegisterValue:
    mov eax, ebx ; Move the value of EBX into EAX
    ret ; Return the value of EAX

GetECXRegisterValue:
    mov eax, ecx ; Move the value of ECX into EAX
    ret ; Return the value of EAX

GetEDXRegisterValue:
    mov eax, edx ; Move the value of EDX into EAX
    ret ; Return the value of EAX

GetESIRegisterValue:
    mov eax, esi ; Move the value of ESI into EAX
    ret ; Return the value of EAX

GetEDIRegisterValue:
    mov eax, edi ; Move the value of EDI into EAX
    ret ; Return the value of EAX

GetEBPRegisterValue:
    mov eax, ebp ; Move the value of EBP into EAX
    ret ; Return the value of EAX

GetESPRegisterValue:
    mov eax, esp ; Move the value of ESP into EAX
    ret ; Return the value of EAX
Test_INT:
    int 0 ; Call the interrupt 0x70 (112 in decimal) Kernel function
    ret ; Return the value of EAX