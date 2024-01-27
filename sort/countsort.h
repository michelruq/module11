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

void countSort(int* arr, int n)
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
