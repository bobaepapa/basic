#include <stdio.h>

typedef void (*func)(void);

void callback(void) 
{
	printf("%s()\n", __func__);
}

//void controller(func f)
void controller(void (*f)())
{
	printf("%s()\n", __func__);
	(*f)();
}


int main() 
{
	printf("%s()\n", __func__);

	printf("callback addr=%p\n", callback);
	printf("&callback addr=%p\n", &callback);
	controller(&callback);

	return 0;
}
