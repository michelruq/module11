#pragma once

#include "basesort.h"

class BubbleSort : public BaseSort
{
	private:
	    const std::string name = "Bubble Sorting Algorithm";
	
    public:
	    void Sort(int* arr, int n);
		std::string getNameSortingAlgorithm()
	    {
		   return name;
	    }
};

void BubbleSort::Sort(int* arr, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n-1; j++)
		{
			if(arr[j+1] < arr[j])
			{
			   swap(&arr[j], &arr[j+1]); 
			}
		}
	}
}