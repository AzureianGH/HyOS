#pragma once
// Create static class called Port
class Port
{
public:
	// Write a byte out to the specified port
	static void outb( unsigned short port, unsigned char data )
	{
		asm volatile( "outb %0, %1" : : "a"(data), "Nd"(port) );
	}

	// Read a byte from the specified port
	static unsigned char inb( unsigned short port )
	{
		unsigned char result;
		asm volatile( "inb %1, %0" : "=a"(result) : "Nd"(port) );
		return result;
	}
};