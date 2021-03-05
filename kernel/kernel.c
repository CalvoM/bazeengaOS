#include "../drivers/screen.h"
void dummy(){

}
void main(){
   char *video_mem = (char *)0xb8000;
   video_mem[0] = 'M';
   video_mem[1] = 0x0f;
   video_mem[2] = 'X';
   video_mem[3] = 0x0b;
   int target = 10;
   int i = 0;
   char let = 0x41;
   while(i<10){
	video_mem[i] = let;
	video_mem[i+1] = 0x0b;
	i+=2;
	let++;
}
}
