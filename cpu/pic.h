#ifndef PIC_H_
#define PIC_H_

#include "types.h"
#define PIC1 0x20
#define PIC2 0xA0

#define PIC1_CMD PIC1
#define PIC1_DATA (PIC1 + 1)

#define PIC2_CMD PIC2
#define PIC2_DATA (PIC2 + 1)

#define PIC_EOI 0x20

// The 8259 Programmable Interrupt Controller can be initialized with four ICWs;
// the first two are compulsory,and the other two are optional based on the
// modes being used. These words must be issued in a given sequence.After
// initialization, the 8259A can be set up to operate in various modes by using
// three different OCWs; however, they are not necessary to be issued in a
// specific sequence.

// ICW registers (Initialization Command Word)
// OCW registers (Operation Command Word)

// ICW1 ref pic
// https://www.eeeguide.com/wp-content/uploads/2018/08/Programming-8259-1.jpg
#define ICW1_ICW4 0x01      /* ICW4 (not) needed */
#define ICW1_SINGLE 0x02    /* Single (cascade) mode */
#define ICW1_INTERVAL4 0x04 /* Call address interval 4 (8) */
#define ICW1_LEVEL 0x08     /* Level triggered (edge) mode */
#define ICW1_INIT 0x10      /* Initialization - required! */

// ICW4 ref pic
// https://www.eeeguide.com/wp-content/uploads/2018/08/Programming-8259-4.jpg
#define ICW4_8086 0x01       /* 8086/88 (MCS-80/85) mode */
#define ICW4_AUTO 0x02       /* Auto (normal) EOI */
#define ICW4_BUF_SLAVE 0x08  /* Buffered mode/slave */
#define ICW4_BUF_MASTER 0x0C /* Buffered mode/master */
#define ICW4_SFNM 0x10       /* Special fully nested (not) */
void PIC_sendEOI(u8 irq);
void PIC_remap(int offset, int offset2);
#endif
