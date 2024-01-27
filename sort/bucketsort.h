#pragma once

#include "basesort.h"

struct bucket {
   int count; // количество элементов в корзине
   int* data; // массив элементов корзины
};

class BucketSort : public BaseSort
{
	private:
	   const std::string name = "Bucket Sorting Algorithm";
       void countSort(int *arr, int n);
	public:
	   void Sort(int* arr, int n);
	   std::string getNameSortingAlgorithm()
	   {
		   return name;
	   }	
};

void BucketSort::countSort(int *arr, int n)
{
    if (!n)
        return;
    int* output = new int[n];
    int max = getMax(arr, n);
    int* count = new int[max + 1];  
    
    for (int i = 0; i < max + 1; i++)
        count[i] = 0;

    for(int i = 0; i < n; i++)
        count[arr[i]]++;  // подсчитываем  частоту повторения элементов

    for(int i = 1; i <= max; i++)
        count[i] += count[i-1];  // вычисляем накопленные суммы

    for(int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];  // устанавливаем элемент на корректное место 
        count[arr[i]]--; // уменьшаем частоту, так как уже записали элемент
    }

    for (int i = 0; i < n; i++) 
        arr[i] = output[i];
        
    delete[] output;
    delete[] count;
}

void BucketSort::Sort(int* arr, int n)
{
    struct bucket buckets[10];
    // вычисляем значение экспоненты
    int exp = getExp(getMax(arr, n));

    for (int i = 0; i < 10; i++)
    {
        buckets[i].count = 0;
        buckets[i].data = new int[n];
    }
    for (int i = 0; i < n; i++) {
        int bi =  arr[i] / exp; // вычисляем индекс корзины
        buckets[bi].data[buckets[bi].count++] = arr[i]; // добавляем элемент в корзину
    }  
    
    for(int i = 0, k = 0; i < 10; ++i)
    {
        countSort(&buckets[i].data[0] , buckets[i].count);
        for(int j = 0; j < buckets[i].count; ++j)
        {
            arr[k] = buckets[i].data[j];
            ++k;
        }
    }

}
