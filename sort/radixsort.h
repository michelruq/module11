#pragma once

#include "basesort.h"

class RadixSort : public BaseSort
{
	private:
	   const std::string name = "Radix Sorting Algorithm";
       void countSort(int* arr, int n, int exp );

    public:
	   void Sort(int* arr, int n);
	   std::string getNameSortingAlgorithm()
	   {
		   return name;
	   }		
};

void RadixSort::countSort(int* arr, int n, int exp )
{
	int* output = new int[n];
	int count[10] = {0};

	for(int i = 0; i < n; ++i)
	{
		count[(arr[i]/exp) % 10]++;
	}
	
	 for (int i = 1; i < 10; i++) 
		count[i] += count[i - 1];

	for (int i = n - 1; i >= 0; i--) { 
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
	
	for (int i = 0; i < n; i++) 
		arr[i] = output[i];

	delete[] output;   
}

void RadixSort::Sort(int* arr, int n) 
{
	int m = getMax(arr, n); // находим максимальное число

	int exp = 1; 
	while(m/exp)
	{
	   countSort(arr, n, exp);
	   exp*= 10;
	}  
}