#include "frameBuffer.h"
#include "serialPort.h"


int main()
{
    char consoleOut[] = "Hello World"; 
    serial_write(0x3F8, consoleOut, 19);
    fb_write(consoleOut, 19);
}
