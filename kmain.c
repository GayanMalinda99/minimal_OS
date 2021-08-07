#include "frameBuffer.h"
#include "serialPort.h"


int main()
{
    char consoleOut[] = "Hello World"; 
    serial_write(0x3F8, consoleOut, sizeof(consoleOut));
    fb_write(consoleOut, sizeof(consoleOut));
}
