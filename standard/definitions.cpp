#pragma once
#include <stdint.h>

#define NULL 0

typedef struct Point
{
    int x;
    int y;
} Point;

enum FG_COLOR
{
    FG_BLACK = 0,
    FG_BLUE = 1,
    FG_GREEN = 2,
    FG_CYAN = 3,
    FG_RED = 4,
    FG_MAGENTA = 5,
    FG_BROWN = 6,
    FG_LIGHT_GREY = 7,
    FG_DARK_GREY = 8,
    FG_LIGHT_BLUE = 9,
    FG_LIGHT_GREEN = 10,
    FG_LIGHT_CYAN = 11,
    FG_LIGHT_RED = 12,
    FG_LIGHT_MAGENTA = 13,
    FG_LIGHT_BROWN = 14,
    FG_WHITE = 15
};
enum BG_COLOR
{
    BG_BLACK = 0,
    BG_BLUE = 16,
    BG_GREEN = 32,
    BG_CYAN = 48,
    BG_RED = 64,
    BG_MAGENTA = 80,
    BG_BROWN = 96,
    BG_LIGHT_GREY = 112,
    BG_DARK_GREY = 128,
    BG_LIGHT_BLUE = 144,
    BG_LIGHT_GREEN = 160,
    BG_LIGHT_CYAN = 176,
    BG_LIGHT_RED = 192,
    BG_LIGHT_MAGENTA = 208,
    BG_LIGHT_BROWN = 224,
    BG_WHITE = 240
};

typedef struct Color {
    FG_COLOR fg;
    BG_COLOR bg;
} Color;


int GetCharPointerLength(char* str)
{
    int i = 0;
    while (str[i] != NULL)
    {
        i++;
    }
    return i;
}