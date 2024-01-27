#pragma once

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

void mergeSort(int* a, int p, int r)
{
   if(p >= r)
   {
      return;
   }
   int q = (p + r - 1)/2;
   mergeSort(a, p, q);
   mergeSort(a, q + 1, r);
   merge(a, p, q, r);
}

void mergeSort(int* a, int number)
{
   mergeSort(a, 0, number - 1);
}
