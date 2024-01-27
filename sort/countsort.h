#pragma once

#include "basesort.h"

class CountSort : public BaseSort
{
private:
    const std::string name = "Count Sorting Algorithm";
    
	void build_output(int* output, int* count, int max);

public:
    void Sort (int* arr, int n);
    std::string getNameSortingAlgorithm()
    {
       return name;
	}		
};

void CountSort::build_output(int* output, int* count, int max)
{
    for(int i = 0, j = 0; i < max + 1; ++i)
    {
       while (count[i]--)
       {
          output[j++] = i;
       }
    }
}

void CountSort::Sort(int* arr, int n)
{
    int* output = new int[n];
    int max = getMax (arr, n);
    int* count = new int[max + 1];

    for(int i = 0; i < max + 1; ++i) 
    {
        count[i] = 0;
    }

    for(int i = 0; i < n; ++i)
    {
        count[arr[i]]++;
    }
    
    build_output(output, count, max);

    for(int i = 0; i < n; ++i)
    {
        arr[i] = output[i];
    }

    delete[] output;
    delete[] count;
}
