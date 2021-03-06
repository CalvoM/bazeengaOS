#ifndef SCREEN_H_
#define SCREEN_H_
#define video_addr 0xb8000
#define white_on_black 0x0f
#define red_on_black 0x04
#define max_rows 25
#define max_cols 80
#define reg_screen_ctrl 0x3d4
#define reg_screen_data 0x3d5
#define get_high_byte 0x0e
#define get_low_byte 0x0f
void clear_screen();
void kmonitor_at(char * msg, int col, int row);
void kmonitor(char *msg);
#endif
