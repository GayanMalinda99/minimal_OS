#include "frame_buffer.h"
#include "serial_port.h"
#include "memory_seg.h"
#include "keyboard.h"
#include "interrupts.h"
#include "start_program.h"
#include "paging.h"


/*function to intialize interrupts and segments*/
void init(){
	segments_install_gdt();
	interrupts_install_idt();
	init_paging();

}

/*kernal main funcion*/
void kmain(){

	init();   //initialize interrunpts and segments
	

}
