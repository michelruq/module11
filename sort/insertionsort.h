#pragma once

#include "basesort.h"

class InsertSort : public BaseSort
{
	private:
	   const std::string name = "Insert Sorting Algorithm";
	
	public:
	   void Sort(int* arr, int n);
	   std::string getNameSortingAlgorithm()
	   {
	      return name;
	   }
};

void InsertSort::Sort(int* arr, int n) 
{ 
   for (int i = 1; i < n; i++) {
       int key = arr[i]; 
       int j = i - 1; 
       
       // —двигаем элементы arr[0..i-1], которые больше чем key, на одну позицию вперед
       while((key < arr[j]) && (j >= 0))
	   {
			arr[j + 1] = arr[j];
			--j;
	   }
       
	   arr[j + 1] = key;
   }
}