#pragma once

void swap(int *a, int *b) // функция для смены местами двух значений
{
   int temp = *a;
   *a = *b;
   *b = temp;
}

void selectionSort(int* arr, int n)
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
