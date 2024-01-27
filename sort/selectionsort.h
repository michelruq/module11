#pragma once

#include "basesort.h"

class SelectSort : public BaseSort
{
	private:	
        const std::string name = "Select Sorting Algorithm";
		
	public:	
	    void Sort(int* arr, int n);
		std::string getNameSortingAlgorithm()
	    {
	       return name;
	    }
};

void SelectSort::Sort(int* arr, int n)
{
    for(int j {0}; j < n; ++j)
    {
        for(int i {j}; i < n; ++i)
        {
            if (arr[j] > arr[i])
            {
                swap(&arr[j], &arr[i]);
            }
        }
    }
}
