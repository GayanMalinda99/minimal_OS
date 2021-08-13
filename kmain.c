#include "frame_buffer.h"
#include "serial_port.h"
#include "memory_segments.h"


int main()
{
    char consoleOut[] = "Hello World"; 
    
    serial_write(0x3F8, consoleOut, sizeof(consoleOut));
    fb_write(consoleOut, sizeof(consoleOut));
    segments_install_gdt();
    
}
