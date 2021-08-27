#include "multiboot.h"
#include "start_program.h"
#include "framebuffer.h"

/*function to load and run the user program*/
void run_custom_program(unsigned int ebx){

	multiboot_info_t *mbinfo = (multiboot_info_t *) ebx;
	
	if(mbinfo->mods_count == 0){
		char consoleOut[]="Error: no module loaded";
		fb_write(consoleOut, sizeof(consoleOut));
         
        /*the program will only be executed if the number of loaded programs equal to one*/
	}else if(mbinfo->mods_count == 1){
	
		char consoleOut[]="One module successfully loaded";
		fb_write(consoleOut, sizeof(consoleOut));
		multiboot_module_t* modules = (multiboot_module_t*) mbinfo->mods_addr;
		unsigned int address_of_module = modules->mod_start;
	    	typedef void (*call_module_t)(void);

	    	call_module_t start_program = (call_module_t) address_of_module;
	    	start_program();
	    	/* we'll never get here, unless the module code returns */    
	    		
	}else{
	    	char consoleOut[]="Error: multiplt modules loaded";
	    	fb_write(consoleOut, sizeof(consoleOut));
	    	
	}
}
