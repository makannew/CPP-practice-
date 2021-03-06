#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <math.h>


using namespace System;

int main(array<System::String ^> ^args)
{
	//defining long double data type to reach maximum 16 digits precision
	long double k,i=16,pi=0;
	//using the BBP formula to calculate pi number
	for (k=0; k < i; ++k)
	{
		pi = pi + (((120 * pow(k, 2)) + (151 * k) + 47) / ((((512 * pow(k, 4)) + (1024 * pow(k, 3)) + (712 * pow(k, 2)) + (194 * k) + 15))*pow(16, k)));
		//print pi number in comparison with the refrence
			std::cout <<std::endl<< "PI with (" <<std::setw(2)<< k+1 << ") decimal digits= " << std::setprecision(k+1) << pi << std::endl;
			std::cout << "        Refrenced PI number= " << "3.141592653589793238462643383279502884197169399375105820974944592307816406286" << std::endl;
		
	}
	return 0;
}
