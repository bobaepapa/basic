#include <stdio.h>
#include "log_debug.h"


int main()
{
	int i = 3;
	log_error("Error");
	log_info("Info");
	log_debug("Debug");
	log_trace("Trace");
}


