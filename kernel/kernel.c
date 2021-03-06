#include "../drivers/screen.h"
void dummy(){

}
void main(){
	clear_screen();
	int i=0;
	while(i++<25){
	kmonitor("Hey There! tell me something about you \n");
	}
}
