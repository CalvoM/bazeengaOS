#include "screen.h"
#include "low_level.h"
#include "../kernel/util.h"

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
	char *video_mem = (char*) video_addr;
	if(!attr) attr = white_on_black;
	int screen_size = max_cols * max_rows;
	if(col > max_cols || row > max_rows){//print beyond screen
		clear_screen();
		print_char_t('E',red_on_black,0,0);
		return get_screen_offset(col,row);
	}
	int offset; 
	if(col >= 0 && row >= 0){
		offset = get_screen_offset(col,row);
	}else{
		offset = get_cursor();
	}
	if (chr == '\n'){
		row = get_screen_offset_row(offset);//get row
		offset = get_screen_offset(0,row+1);//update offset
	}else{
	video_mem[offset] = chr;
	video_mem[offset+1] = attr;
	offset+=2;
	}
	set_cursor(offset);
	return handle_scrolling(offset); 
}
int get_screen_offset(int col, int row){
	return (int)(2 * (row * max_cols + col));
}

int get_screen_offset_row(int offset){
	// This is an approximation with an error of col/max_cols.
	return (int)(offset/(2 * max_cols));
}

int get_screen_offset_col(int offset){
	return (int)(offset/2 - get_screen_offset_row(offset)*max_cols);
}

int get_cursor(){
	port_byte_out(reg_screen_ctrl,get_high_byte);
	int offset = port_byte_in(reg_screen_data);
	offset<<=8;
	port_byte_out(reg_screen_ctrl,get_low_byte);
	offset |=port_byte_in(reg_screen_data);
	return 2*offset;
}

void set_cursor(int offset){
	offset /=2;
	port_byte_out(reg_screen_ctrl, get_high_byte);
	port_byte_out(reg_screen_data,offset>>8);
	port_byte_out(reg_screen_ctrl,get_low_byte);
	port_byte_out(reg_screen_data,offset);

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
	set_cursor(get_screen_offset(0,0));//update cursor
}

int handle_scrolling(int offset){
	int screen_size = max_cols * max_rows;	
	char *video_mem = (char *)video_addr;
	//make sure offset is beyond screen offset
	if(offset < screen_size*2){
		return offset;
	}
	//move the rows upwards
	int i;
	for(i = 0; i < max_rows; i++){
		memory_copy(&video_mem[get_screen_offset(0,i)],
				&video_mem[get_screen_offset(0,i-1)],
					max_cols*2);
	}
	char *last_line = &video_mem[get_screen_offset(0,max_rows-1)];
	for(i=0;i<max_cols*2;i++){
		last_line[i] = '-';
	}
	offset -= 2*max_cols;
	return offset;
}
