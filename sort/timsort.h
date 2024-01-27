#pragma once
#include <algorithm>

void merge(int* arr, int l, int m, int r)
{
   int nl = m - l + 1;
   int nr = r - m;

   // ������� ��������� �������
   int left[nl], right[nr];

   // �������� ������ �� ��������� �������
   for (int i = 0; i < nl; i++)
       left[i] = arr[l + i];
   for (int j = 0; j < nr; j++)
       right[j] = arr[m + 1 + j];

   int i = 0, j = 0;
   int k = l;  // ������ ����� �����

   while (i < nl && j < nr) {
       // ���������� ����������� �������� ������� �� ������� ������
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
   // ���������� ���������� �������� ����� �����
   while (i < nl) {
       arr[k] = left[i];
       i++;
       k++;
   }
   // ���������� ���������� �������� ������ �����
   while (j < nr) {
       arr[k] = right[j];
       j++;
       k++;
   }
}

void insertionSort(int* arr, int l, int r) 
{
    for (int i = l + 1; i <= r; i++) {
        int key = arr[i]; 
        int j = i - 1; 
        // �������� �������� arr[0..i-1]
        // ������� ������ ��� key �� ���� ������� ������
        while (j >= l && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
      
        arr[j + 1] = key;
   } 
}

void timSort(int* arr, int n)
{
    const int RUN = 16;
    // ��������� ��������� ���������� ������� RUN
    for (int i = 0; i < n; i+=RUN)
       insertionSort(arr, i, std::min((i + RUN - 1), (n - 1))); 
        
    // ���������� ��� ��������������� ����������
    for (int size = RUN; size < n; size = 2*size)
    {
        // ���������� arr [left..left + size-1] � arr [left + size, left + 2 * size-1]
        // ����� ������� ������� �� ����������� ����� ������ �� 2
        for (int left = 0; left < n; left += 2*size)
        {
            // ������� �������� � ������ �������
            int mid = left + size - 1;
            int right = std::min((left + 2*size - 1), (n-1));
            if (mid > right) 
                mid = left;
            // ��������� ���������� arr[left.....mid] � arr[mid+1....right]
            merge(arr, left, mid, right);
        }
    }
}
