
#include "framebuffer.h"
#include "serial_port.h"
#include "memory_segments.h"
#include "keyboard.h"
#include "interrupts.h"
#include "multiboot.h"
#include "start_program.h"

/*function to intialize interrupts and segments*/
void init_segments_interrupts(){
	segments_install_gdt();
	interrupts_install_idt();

}

/*kernal main funcion*/
void kmain(unsigned int ebx){

	init_segments_interrupts();   //initialize interrunpts and segments
	run_custom_program(ebx);      //run the user program


}
