#define PY_SSIZE_T_CLEAN
#include <stdio.h>
#include <conio.h>
#include "include/Python.h"


int main()
{
	char filename[] = "pyemb7.py";
	FILE* fp;

	Py_Initialize();

	fp = _Py_fopen(filename, "r");
	PyRun_SimpleFile(fp, filename);

	Py_Finalize();
	return 0;
}