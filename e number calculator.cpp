#include "stdafx.h"
#include <iostream>
#include <iomanip> //allows using setprecision function

using namespace System;

int main(array<System::String ^> ^args)
{
	long double e = 1,j=1,i;
	// calculate e number as the sum of the infinite series.
	for (int i = 0; i <= 16; ++i)
	{
		j += i*j;
		e += 1 / j;
	}
	std::cout << "Calculated e=" <<std::setprecision(16) << e<<std::endl;
	std::cout << "Refrenced  e=" << "2.7182818284590452353602874713527" << std::endl;

    return 0;
}
