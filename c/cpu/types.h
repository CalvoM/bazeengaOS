#ifndef TYPES_H_
#define TYPES_H_

#define CODE_SEG 0x8 //from GDT
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int s32;
typedef short s16;
typedef char s8;

#define low_16(addr) (u16)((addr) & 0xffff)
#define high_16(addr) (u16)((addr>>16)&0xffff)
#endif
