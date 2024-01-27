﻿#pragma once
#include <algorithm>

#include "basesort.h"

class TimSort : public BaseSort
{
	private:
	   const std::string name = "Tim Sorting Algorithm";
	   void merge(int* arr, int l, int m, int r);
	   void insertionSort(int* arr, int l, int r);
	
	public:
	   void Sort(int* arr, int n);
	   std::string getNameSortingAlgorithm()
	   {
	      return name;
	   }
};

void TimSort::merge(int* arr, int l, int m, int r)
{
   int nl = m - l + 1;
   int nr = r - m;

   // создаем временные массивы
   int left[nl], right[nr];

   // копируем данные во временные массивы
   for (int i = 0; i < nl; i++)
       left[i] = arr[l + i];
   for (int j = 0; j < nr; j++)
       right[j] = arr[m + 1 + j];

   int i = 0, j = 0;
   int k = l;  // начало левой части

   while (i < nl && j < nr) {
       // записываем минимальные элементы обратно во входной массив
       if (left[i] <= right[j]) {
           arr[k] = left[i];
           i++;
       }
       else {
           arr[k] = right[j];
           j++;
       }
       k++;
   }
   // записываем оставшиеся элементы левой части
   while (i < nl) {
       arr[k] = left[i];
       i++;
       k++;
   }
   // записываем оставшиеся элементы правой части
   while (j < nr) {
       arr[k] = right[j];
       j++;
       k++;
   }
}

void TimSort::insertionSort(int* arr, int l, int r) 
{
    for (int i = l + 1; i <= r; i++) {
        int key = arr[i]; 
        int j = i - 1; 
        // Сдвигаем элементы arr[0..i-1]
        // которые больше чем key на одну позицию вперед
        while (j >= l && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
      
        arr[j + 1] = key;
   } 
}

void TimSort::Sort(int* arr, int n)
{
    const int RUN = 16;
    // сортируем отдельные подмассивы размера RUN
    for (int i = 0; i < n; i+=RUN)
       insertionSort(arr, i, std::min((i + RUN - 1), (n - 1))); 
        
    // Объединяем все отсортированные подмассивы
    for (int size = RUN; size < n; size = 2*size)
    {
        // Объединяем arr [left..left + size-1] и arr [left + size, left + 2 * size-1]
        // После каждого слияния мы увеличиваем левый размер на 2
        for (int left = 0; left < n; left += 2*size)
        {
            // находим середину и правую границу
            int mid = left + size - 1;
            int right = std::min((left + 2*size - 1), (n-1));
            if (mid > right) 
                mid = left;
            // соединяем подмассивы arr[left.....mid] и arr[mid+1....right]
            merge(arr, left, mid, right);
        }
    }
}
