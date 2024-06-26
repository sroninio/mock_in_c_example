#include <stdio.h>
#include "simple_calculator.h"

int add(int x, int y)
{
	printf("I am a real add function %d + %d\n", x, y);
	return x + y;
}

int sub(int x, int y)
{
	printf("I am a real sub function %d - %d\n", x, y);
	return x - y;
}

int simple_calculator_init(char * name)
{
	printf("I am a real simple_calculator init function\n");
	return 0;
}

int simple_calculator_destroy()
{
	printf("I am a real simple_calculator destroy function\n");
	return 0;
}
