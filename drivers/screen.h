#ifndef SCREEN_H_
#define SCREEN_H_
#define video_addr 0xb8000
#define max_rows 25
#define max_cols 80
#define white_on_black 0x0f

#define reg_screen_ctrl 0x3d4
#define reg_screen_data 0x3d5

void print_char(char character, int col, int row, char attribute_byte);
int get_cursor();
void set_cursor(int offset);
void print_at(char* message, int col, int row);
int get_screen_offset(int col,int row);
int handle_scrolling(int offset);
void kprint_at(char * msg, int col, int row);
void k_print(char *msg);

#endif
