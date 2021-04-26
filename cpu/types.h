#ifndef TYPES_H_
#define TYPES_H_

#define CODE_SEG 0x8 //from GDT
#define PIC_MST_CMD_ADDR 0x20
#define PIC_SLV_CMD_ADDR 0xa0
#define PIC_MST_DATA_ADDR 0x21
#define PIC_SLV_DATA_ADDR 0xa1
#define ICW1 0b00010001
#define ICW2_MST 0x20 //remapping master vector offset to 32
#define ICW2_SLV 0x28 //remapping pci slave vector offset to 40
#define ICW3_SLV 0b00000010 //default input for slave to master is IN#2
#define ICW3_MST 0b00000100 
#define EOI_CMD 0x20
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int s32;
typedef short s16;
typedef char s8;

#define low_16(addr) (u16)((addr) & 0xffff)
#define high_16(addr) (u16)((addr>>16)&0xffff)
#endif
