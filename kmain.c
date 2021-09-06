
#include "framebuffer.h"
#include "serial_port.h"
#include "memory_segments.h"
#include "keyboard.h"
#include "interrupts.h"
#include "multiboot.h"
#include "start_program.h"
#include "paging.h"

/*function to intialize interrupts and segments*/
void init_segments_interrupts(){
	segments_install_gdt();
	interrupts_install_idt();
	init_paging();

}

/*kernal main funcion*/
void kmain(){

	init_segments_interrupts();   //initialize interrunpts and segments
	


}
