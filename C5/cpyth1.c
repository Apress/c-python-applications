#include <stdio.h>
#include "include/Python.h"


int main()
{
	
	Py_Initialize();

	PyRun_SimpleString("print('Embedded Python string')");
	
	Py_Finalize();

	return 0;
}