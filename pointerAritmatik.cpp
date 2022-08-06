#include <stdio.h>
#include <stdint.h>

int main ()
{
	
	uint8_t aid [] ={0xA0, 0x01, 0x01, 0x10, 0x20, 0x10, 0x10, 0x11};
	
	uint64_t *AID =  (uint64_t*) aid;
	
	printf("AID = %x",*AID);
	
	if(*AID==0x11101020100101A0)
	{
		printf(" \n esit !!!");
	}
}
