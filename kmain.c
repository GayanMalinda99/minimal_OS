
#include "framebuffer.h"
#include "serial_port.h"
#include "memory_segments.h"
#include "keyboard.h"
#include "interrupts.h"


    
void kmain(){

    //char consoleOut[] = "Hello World";
    unsigned char scancode,ascii;
    char asciicode[1];
   
    segments_install_gdt();
    //serial_write(0x3F8, consoleOut, sizeof(consoleOut));
    //fb_write(consoleOut, sizeof(consoleOut));
    interrupts_install_idt();
    scancode = keyboard_read_scan_code();
    ascii = keyboard_scan_code_to_ascii(scancode);
    asciicode[0] = ascii;
    serial_write(asciicode, sizeof(asciicode));
    //fb_write(asciicode, sizeof(asciicode));
    
}
