#include <stdio.h>
#include <stdlib.h>
#include "singleton.h"


int read_test() {
	nvram_t* my_nvram = get_nvram();
	my_nvram->read();
	return 1;
}

void write_test() {
	nvram_t* my_nvram = get_nvram();
	my_nvram->write();
}


int main()
{
	nvram_init();

	printf("Hello\n");

	read_test();
	printf("read done\n");


	write_test();
	printf("write done\n");


	return 0;
}
