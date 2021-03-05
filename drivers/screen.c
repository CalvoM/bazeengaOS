#include "screen.h"
#include "low_level.h"

int print_char_t(char chr, char attr,int col,int row);
int get_cursor();
void set_cursor(int offset);
int get_screen_offset_row(int offset);
int handle_scrolling(int offset);
int get_screen_offset_col(int offset);
void print_at(char* message, int col, int row);
int get_screen_offset(int col,int row);

void kmonitor(char *msg){
	kmonitor_at(msg,-1,-1);
}

void kmonitor_at(char *msg, int col, int row){
	int offset;
	if(col >= 0 && row >=0) 
		offset = get_screen_offset(col,row);
	else{
		offset = get_cursor();
		row = get_screen_offset_row(offset);
		col = get_screen_offset_col(offset);
	}
	char *temp;
	for(temp=msg;*temp!='\0';temp++){
		offset = print_char_t(*temp,white_on_black,col,row);
		row = get_screen_offset_row(offset);
		col = get_screen_offset_col(offset);
	}
}

int print_char_t(char chr, char attr, int col, int row){
	unsigned char *video_mem = (unsigned char*) video_addr;
	if(!attr) attr = white_on_black;
	int offset = get_screen_offset(col,row);
	video_mem[offset] = chr;
	video_mem[offset+1] = attr;
	offset+=2;
	return offset;
}
int get_screen_offset(int col, int row){
	return 2 * (row * max_cols + col);
}

int get_screen_offset_row(int offset){
	return offset/(2 * max_cols);
}

int get_screen_offset_col(int offset){
	return offset/2 - get_screen_offset_row(offset)*max_cols;
}

int get_cursor(){
	port_byte_out(reg_screen_ctrl,get_high_byte);
	int offset = port_byte_in(reg_screen_data);
	offset<<8;
	port_byte_out(reg_screen_ctrl,get_low_byte);
	offset |=port_byte_in(reg_screen_data);
	return 2*offset;
}

void clear_screen(){
	int screen_size = max_cols * max_rows;
	char *video_mem = (char *)video_addr;
	int i = 0;
	while(i < screen_size){
		video_mem[i] = ' ';
		video_mem[i+1] = white_on_black;
		i+=2;
	}
}
