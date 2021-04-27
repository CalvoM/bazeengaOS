#include "util.h"

void memory_copy(char *src, char *dest, int byte_count){
	int i;
	for (i=0; i < byte_count; i++) {
		*(dest+i) = *(src+i);
	}
}

void stringify(int src, char dest[]){
char is_signed;
	if(src < 0) src = -src;
	int i = 0;
	while((src%10) || (src/10)){
		dest[i] = (src %10) + '0';
		src = src/10;
		i++;
	}
	i--;
	dest[i+1] = 0;
	int temp;
	if(i%2 != 0) temp = (i/2)+0.5;
	else temp = i/2;
	char temp_s[10] = {0};
	int j;
	for(j=i;j>=temp;j--){
		temp_s[i-j] = dest[j];
		dest[j] = dest[i-j];
	}
	temp_s[temp+1] = 0;
	j=0;
	for (j=temp;j>=0;j--) dest[j] = temp_s[j];	
}
