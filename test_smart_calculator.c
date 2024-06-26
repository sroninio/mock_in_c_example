#include <stdio.h>
#include "smart_calculator.h"
#include "my_lib_mock.h"


int mock_add(int x, int y)
{
	printf("I am a mock add function %d + %d\n", x, y);
	return x + y;
}

int mock_sub(int x, int y)
{
	printf("I am a mock sub function %d - %d\n", x, y);
	return x - y;
}

int mock_simple_calculator_init(char * name)
{
	printf("I am a mock simple_calculator init function\n");
	return 0;
}

int mock_simple_calculator_destroy()
{
	printf("I am a mock simple_calculator destroy function\n");
	return 0;
}


int basic_test()
{
	if (smart_calculator_init("my_calc")) {return 1;}
	printf ("TESTING 6 * 8\n");
	if (multiply(6, 8) != 48) {return 1;}
	printf ("TESTING 6 / 8\n");
	if (divide(6, 8) != 0) {return 1;}
	printf ("TESTING 6 * 0\n");
	if (multiply(6, 0) != 0) {return 1;}
	printf ("TESTING 51 / 7\n");
	if (divide(51, 7) != 7) {return 1;}
	if (smart_calculator_destroy()) {return 1;}
	return 0;
}

int main()
{
    mock("simple_calculator_init", mock_simple_calculator_init);
    mock("simple_calculator_destroy", mock_simple_calculator_destroy);

	printf ("<<<TEST 1 ADD IS NOT MOCKED SUB IS NOT MOCKED>>>\n");
	if (basic_test()) {return 1;}

	printf ("<<<TEST 2 ADD IS MOCKED SUB IS NOT MOCKED>>>\n");
	mock("add", mock_add);
	if (basic_test()) {return 1;}


	printf ("<<<TEST 3 SUB IS NOT MOCKED ADD NOT MOCKED>>>\n");
	mock("sub", mock_sub);
	unmock("add");
	if (basic_test()) {return 1;}

	printf ("<<<TEST 4 SUB IS NOT MOCKED ADD IS NOT MOCKED>>>\n");
	mock("add", mock_add);
	if (basic_test()) {return 1;}
	return 0;
}

