#include  <stdio.h>
#include  <stdlib.h>
#include "my_map.h"


struct MyMap map;

#define FUNCTIONS \
	X(int, sub, sub(int x, int y), int (*)(int, int), x, y) \
	X(int, add, add(int x, int y), int (*)(int, int), x, y) \ 
	X(int, simple_calculator_init, simple_calculator_init(char *x), int (*)(char *), x)\  
	X(int, simple_calculator_destroy, simple_calculator_destroy(), int (*)())  




#define X(ret_val, func_name, func, ptr_sig, ...)							\
ret_val __wrap_##func														\
{   ret_val ret;															\
	if (getElem(&map,#func_name))											\
	{																		\
		ret = ((ptr_sig)(getElem(&map,#func_name)))(__VA_ARGS__);			\
	} else {																\
		ret = __real_##func_name(__VA_ARGS__);								\
	}																		\
	return ret;																\
} 

FUNCTIONS
#undef X

void mock(char * funcName, void * func)
{
	addElem(&map, funcName, func);
}
void unmock(char * funcName)
{
	removeElem(&map, funcName);
}




