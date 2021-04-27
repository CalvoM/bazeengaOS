#ifndef KBD_H_
#define KBD_H_

#define KBD_DATA_PORT 0x60
#define KBD_STATUS_PORT 0x64 

#include "low_level.h"
#include "screen.h"
#include "../kernel/util.h"
#include "../cpu/isr.h"
#include "../cpu/types.h"
#include "../shell/shell.h"
void init_kbd();
#endif