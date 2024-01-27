#pragma once

int getMax (int* arr, int n )
{
   int max = arr[0];
   for(int i = 1; i < n; ++i)
   {
      if( arr[i] > max)
      {
        max = arr[i];
      }
   }
   return max;
}

void build_output(int* output, int* count, int max)
{
    for(int i = 0, j = 0; i < max + 1; ++i)
    {
       while (count[i]--)
       {
          output[j++] = i;
       }
    }
}

void countSort(int* arr, int n, int exp )
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

void radixSort(int* arr, int n) 
{
    int m = getMax(arr, n); // находим максимальное число
    // выполняем сортировку массива, пока не дойдем до старшего разряда наибольшего числа 
    std::cout << m << " ";
    std::cout << std::endl; 
   
    int exp = 1; 
    while(m/exp)
    {
       countSort(arr, n, exp);
       exp*= 10;
    }  
}
