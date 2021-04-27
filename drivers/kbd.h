#ifndef KBD_H_
#define KBD_H_

#define KBD_DATA_PORT 0x60
#define KBD_STATUS_PORT 0x64 

#include "../cpu/types.h"
void init_kbd();
#endif