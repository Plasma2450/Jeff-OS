#include "fb.h"

char *fb = (char *) 0x000B8000;

void fb_move_cursor(unsigned short pos)
{
    outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
    outb(FB_DATA_PORT,    ((pos >> 8) & 0x00FF));
    outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
    outb(FB_DATA_PORT,    pos & 0x00FF);
}

void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg)
{
    i*=2;
    fb[i] = c;
    fb[i+1] = (fg & 0x0F) | ((bg & 0x0F) << 4);
}

void fb_clear_screen()
{
    for(int i = 0; i < 80 * 25; i++)
    {
        fb_write_cell(i, ' ', FB_BLACK, FB_BLACK);
    }
}
