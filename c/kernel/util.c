#include "util.h"

void memory_copy(char *src, char *dest, int byte_count){
	int i;
	for (i=0; i < byte_count; i++) {
		*(dest+i) = *(src+i);
	}
}
