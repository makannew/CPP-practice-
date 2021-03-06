#include "stdafx.h"
#include <iostream>

using namespace System;

int main(array<System::String ^> ^args)
{
	int x[] = { 20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1}; // Example array of integers that needs to be sorted
	int x_sorted[20] = {0};
	int array_size = sizeof(x) / sizeof(x[0]); // calculate the number of array elements
	//
	int step_number = 1;
	int final_groups = 2;
	int total_groups_number = 1;
	int group_a_size;
	int group_b_size;
	int group_a_number;
	int group_b_number;
	int counter_a;
	int counter_b;
	int start_index;
	int lot_a_size;
	int lot_b_size;
	int counter_index;
	int lot_a_index;
	int lot_b_index;
	int x_sorted_index;
	//
	std::cout << "Array actual size:" << array_size << std::endl;
	//
	//print unsorted array
	for (int i = 0; i < array_size; ++i) std::cout << x[i] << " ";
	std::cout << std::endl << std::endl;

	//detect final groups number and dividing steps
	while (final_groups * 2 <= array_size)
	{
		final_groups = final_groups * 2;
		step_number = step_number + 1;
	}

	//calculate initial group sizes
	if ((2 * final_groups) - array_size == 0)
	{
		group_a_size = 2; group_b_size = 2;
	}
	else if (array_size - final_groups == 0)
	{
		group_a_size = 1; group_b_size = 1;
	}
	else 
	{
		group_a_size = 2; group_b_size = 1;
	}

	for (int i = step_number; i > 0; --i) 
	{
		total_groups_number=std::pow(2,i);//calculate total groups equal to 2 power of step_number 
		//calculate group_a number of members
		if (group_b_size == group_a_size)
			group_a_number = array_size / group_a_size;
		else
			group_a_number = ((group_b_size*total_groups_number) - array_size) / (group_b_size - group_a_size);
		//calculate group_b number of members		
		group_b_number = total_groups_number - group_a_number;
		//

		if (group_a_number == 0)
		{
			lot_a_size = group_b_size;
			lot_b_size = group_b_size;
		}
		else if (group_b_number == 0)
		{
			lot_a_size = group_a_size;
			lot_b_size = group_a_size;
		}
		counter_a = group_a_number;
		counter_b = group_b_number;
		start_index = 0;
		counter_index = 1;
		while (counter_index<total_groups_number)
		{

			if (group_a_number != 0 && group_b_number != 0)
			{
				if (group_a_number <= group_b_number)
				{
					if ((counter_index % (total_groups_number / group_a_number)) == 0 && counter_a>0)
					{
						lot_a_size = group_a_size;
						--counter_a;
					}
					else
					{
						lot_a_size = group_b_size;
						--counter_b;
					}
						
				}
				else
				{
					if ((counter_index % (total_groups_number / group_b_number)) == 0 && counter_b > 0)
					{
						lot_a_size = group_b_size;
						--counter_b;

					}
						
					else
					{
						lot_a_size = group_a_size;
						--counter_a;

					}
				}
				
			}
			++counter_index;
			if (group_a_number != 0 && group_b_number != 0 )
			{
				if (group_a_number <= group_b_number)
				{
					if ((counter_index % (total_groups_number / group_a_number)) == 0 && counter_a > 0)
					{
						lot_b_size = group_a_size;
						--counter_a;

					}
					else
					{
						lot_b_size = group_b_size;
						--counter_b;

					}
				}
				else
				{
					if ((counter_index % (total_groups_number / group_b_number)) == 0 && counter_b > 0)
					{
						lot_b_size = group_b_size;
						--counter_b;

					}
					else
					{
						lot_b_size = group_a_size;
						--counter_a;

					}
				}
			}

			++counter_index;
			//sort if it is final divided stage
			if (total_groups_number == final_groups)
			{
				if (lot_a_size == 2)
				{
					if (x[start_index] > x[start_index + 1])
					{
						std::swap (x[start_index] , x[start_index + 1]);

					}
				}
				if (lot_b_size == 2)
				{
					if (x[start_index+lot_a_size] > x[start_index+lot_a_size + 1])
					{
						std::swap(x[start_index + lot_a_size] , x[start_index + lot_a_size + 1]);

					}
				}

			}
			
			
				//merge two groups
				lot_a_index = 0;
				lot_b_index = 0;
				x_sorted_index = start_index;
				do
				{
					if (lot_a_index >= lot_a_size)
					{
						x_sorted[x_sorted_index] = x[start_index + lot_a_size + lot_b_index];
						++lot_b_index;
						++x_sorted_index;
					}
					else if (lot_b_index >= lot_b_size)
					{
						x_sorted[x_sorted_index] = x[start_index + lot_a_index];
						++lot_a_index;
						++x_sorted_index;
					}
					else if (x[start_index + lot_a_index] <= x[start_index + lot_a_size + lot_b_index])
					{
						x_sorted[x_sorted_index] = x[start_index + lot_a_index];
						++lot_a_index;
						++x_sorted_index;
					}
					else
					{
						x_sorted[x_sorted_index] = x[start_index + lot_a_size + lot_b_index];
						++lot_b_index;
						++x_sorted_index;
					}
					

				}

				while ((lot_a_index < lot_a_size || lot_b_index < lot_b_size));
				
				std::cout << "Stage: " <<  i << "  Total groups:" << total_groups_number << "  Group A from " << start_index + 1 << " to " << start_index + lot_a_size;
				std::cout<< "  Group B from " << start_index + lot_a_size + 1 << " to " << start_index + lot_a_size + lot_b_size << std::endl;
				std::cout << "Array:";

				for (int j = start_index; j < (start_index + lot_a_size + lot_b_size); ++j)
				{
					x[j] = x_sorted[j];
				}
				//print sorted array
				for (int j = 0; j < array_size; ++j) std::cout << x_sorted[j] << " ";
				std::cout << std::endl << std::endl;
		
			start_index += (lot_a_size + lot_b_size);
					
		}
		if (group_a_number > group_b_number)
		{
			group_b_size = group_a_size + group_b_size;
			group_a_size = group_a_size * 2; 
		}
		else if (group_a_number < group_b_number)
		{
			group_a_size = group_a_size + group_b_size;
			group_b_size = group_b_size * 2; 
		}
		else if (group_a_number == group_b_number)
		{
			group_a_size = group_a_size + group_b_size;
			group_b_size = group_a_size;
		}
			

	}

    return 0;
}
