The project gives an example how to create C unittesting infrastructure.

there are 2 units:
  simple_calculator
    implements add/sub functions/simple_calculator_init/simple_calculator_destroy
  smart_calculator
    implements multiply/divide using simple_calculator's add/sub

there is a unit test for the smart_calculator test_smart_calculator.c, which mocks/unmocks the API functions of simple_calculator.

The structure is the following:
there is a file my_lib_mock.c
each API function  that we wish to be able to mock, should be added to the FUNCTIONS table in this file (following the format there)
**for** **each** function **_foo_** that appears in this FUNCTION table the X macro automatically generates the following function:
__wrap_foo which will be called every time when foo is called in the code, in case --wrap=foo flag is passed to the linker.

my_lib_mock unit also provides 2 API functions:
1. mock(func_name, func_ptr)
   sets _map_name_to_funcptr_[func_name] := func_ptr
3. unmock(func_name)
   deleted func_name from _map_name_to_funcptr_

The implementation of the generated __wrap_foo is the following:
if "_foo_" in _map_name_to_funcptr_ then call _global_map["foo"]_ (with the original arguments)
else call __real_foo (with the original arguments)  //__real_foo is the original foo in case --wrap=foo flag was passed to the linker

Assume u want wrote new function g()  and you want to be able to mock it in unittests
you need to do 2 things:
1. add g() to the FUNCTIONS table in my_lib_mock.c
2. add --wrap=g to the makefile

BUILD:
just run make

NOTE:
I implemented simple my_map O(N) just for the example (its C after all, u dont get nothing for free) obviously it should be some normal O(1) map. 



  
  
  



