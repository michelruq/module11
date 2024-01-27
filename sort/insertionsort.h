#pragma once

void insertionSort(int* arr, int n) 
{ 
   for (int i = 1; i < n; i++) {
       int key = arr[i]; 
       int j = i - 1; 
       
       // �������� �������� arr[0..i-1], ������� ������ ��� key, �� ���� ������� ������
       while((key < arr[j]) && (j >= 0))
	   {
			arr[j + 1] = arr[j];
			--j;
	   }
       
	   arr[j + 1] = key;
   }
}