﻿#include "stdafx.h"
#include <iostream>

using namespace System;

int main(array<System::String ^> ^args)
{
	// getting a number from user for prime factoring
	int i,j,k; 
	std::cout << "Please enter an integer bigger than 2:";
	std::cin >>i;
	k = i; 
	// divideing the number repeatedly to find out its undividable factors
	//I tryed to avoid unnecessary calculation by applying the j<=i condition
	for (j = 2; j <= i; ++j)
	{
		while (i%j == 0)
		{
			std::cout << j<<" ";
			i = i / j;
		}
	}
	//at the end it checks if the number itself is a prime number or not for mentioning to user
	if ( j-1== k)
		std::cout << "itself is a prime number!";
	else
		std::cout << "are prime factors of " << k;
		
    return 0;
}
 
