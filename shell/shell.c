#include "shell.h"

void parse_user_input(char *input){
    if(strcmp(input,"END") == 0){
       clear_screen();
       kmonitor("BYE !!"); 
       __asm__ __volatile__("hlt");
    }

}