#include <stdio.h>
#include "simple_calculator.h"
#include "smart_calculator.h"

unsigned int multiply(unsigned int x, unsigned int y)
{
	unsigned int res = 0;
	for (int i = 0; i < y; i++) {res = add(res, x);}
	return res;
}

unsigned int divide(unsigned int x, unsigned int y)
{
	unsigned int res = 0;
	while (x >= y) {x = sub(x, y); res++;}
	return res;
}


int smart_calculator_init(char * name)
{
	return simple_calculator_init(name);
}

int smart_calculator_destroy()
{
	return simple_calculator_destroy();
}
