#pragma once
#include <stdint.h>
#include "../../port/port.cpp"
#include "../../definitions.cpp"
class Display
{
public:
    char* buffer;
    Point Cursor;
    Color color;
    Display(char* Buffer); // Constructor
    Display(); // Constructor
    char* Init();
    void Clear();
    void PutChar( char c );
    void PutInt( int i );
    void PutString( const char* str );
    void SetCursor( int x, int y );
    void SetCursor( Point p );
    Point GetCursor();
    void Scroll();
    void SetColor( FG_COLOR fg, BG_COLOR bg );
    void SetColor( FG_COLOR color );
    void SetColor( BG_COLOR color );
    void SetColor( Color color );
    Color GetColor();
};

/// Constructor for initializing the display with a buffer
Display::Display(char* Buffer)
{
    buffer = Buffer;
}
/// Constructor for initializing the display with the default buffer
Display::Display()
{

}
/// Set the cursor position
void Display::SetCursor( int x, int y )
{
    Cursor.x = x;
    Cursor.y = y;
    //Write 
    Port::outb(0x3D4, 14);
    Port::outb(0x3D5, (y * 80 + x) >> 8);
    Port::outb(0x3D4, 15);
    Port::outb(0x3D5, (y * 80 + x));
}
/// Set the cursor position
void Display::SetCursor( Point p )
{
    SetCursor(p.x, p.y);
}
/// Scroll the void Display
void Display::Scroll()
{
    for (int i = 0; i < 24 * 80; i++)
    {
        buffer[i] = buffer[i + 80];
    }
    for (int i = 24 * 80; i < 25 * 80; i++)
    {
        buffer[i] = 0;
    }
    Cursor.y--;
}
/// Get the cursor position
Point Display::GetCursor()
{
    return Cursor;
}
/// Put a character on the display
void Display::PutChar( char c )
{
    if (c == '\n')
    {
        //Set cursor to the beginning of the next line
        Cursor.x = 0;
        Cursor.y++;
        SetCursor(Cursor);
        return;
    }
    //odd bytes are color, even bytes are character
    buffer[Cursor.y * 80 + Cursor.x] = c;
    buffer[Cursor.y * 80 + Cursor.x + 1] = color.fg + color.bg;
    Cursor.x += 2;

    if (Cursor.x >= 80)
    {
        Cursor.x = 0;
        Cursor.y++;
    }
    if (Cursor.y >= 25)
    {
        Scroll();
    }
    SetCursor(Cursor);
}
/// Put an integer on the display
void Display::PutInt( int i )
{
    char str[11];
    int j = 0;
    if (i < 0)
    {
        PutChar('-');
        i = -i;
    }
    while (i > 0)
    {
        str[j] = i % 10 + '0';
        i /= 10;
        j++;
    }
    for (int k = j - 1; k >= 0; k--)
    {
        PutChar(str[k]);
    }
}
/// Put a string on the display
void Display::PutString( const char* str )
{
    // Put each character on the display
    int strlen = GetCharPointerLength((char*)str);
    for (int i = 0; i < strlen; i++)
    {
        PutChar(str[i]);
    }
}
/// Clear the display
void Display::Clear()
{
    for (int i = 0; i < 80 * 25; i++)
    {
        buffer[i] = 0;
    }
    SetCursor(0, 0);
}
/// Get the color
Color Display::GetColor()
{
    return color;
}
/// Set the foreground and background color
void Display::SetColor( FG_COLOR fgc, BG_COLOR bgc )
{
    color.fg = fgc;
    color.bg = bgc;
}
/// Set the foreground color
void Display::SetColor( FG_COLOR FGColor )
{
    color.fg = FGColor;
}
/// Set the background color
void Display::SetColor( BG_COLOR BGColor )
{
    color.bg = BGColor;
}
/// Set the color
void Display::SetColor( Color color )
{
    this->color = color;
}
/// Initialize the display and return the buffer
char* Display::Init()
{
    buffer = (char*)0xB8000;
    //set cursor
    SetCursor(0, 0);
    //set color
    SetColor(FG_WHITE, BG_BLACK);
    //clear
    return buffer;
}