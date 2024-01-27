#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib> //for getting random
#include <ctime>
#include <chrono> // для получения времени
#include "files.h"
//#include "countsort.h"
//#include "radixsort.h"
//#include "bucketsort.h"
//#include "bubblesort.h"
//#include "mergesort.h"
//#include "selectionsort.h"
//#include "insertionsort.h"
//#include "timsort.h"
#include "qsort.h"

int main(int argc, char* argv[])
{
	std::string filenameInput = "C://education/module11/files/unsorteddata.txt";
	std::string filenameOutput = "C://education/module11/files/sorteddata.txt";
	const int size = 50000;
    int* rand_arr = new int[size];
	
	srand(time(nullptr)); 
	
	int lef_border = 5;
    int range_len = 10;
	
	for (int i = 0; i < size; i++)
	{
		rand_arr[i] = lef_border + rand() % range_len; 
	}
	
	FileManager::WriteDataUsePtrToFile(filenameInput, rand_arr, size); 
	
	int* array_from_file = nullptr;
    int n = 0;
    FileManager::ReadDataUsePtrFromFile(filenameInput, array_from_file, n); 
	
	auto start = std::chrono::high_resolution_clock::now(); 
	// insert calling of sorting here
	//countSort(array_from_file, n); 
	//radixSort(array_from_file, n); 
	//bucketSort(array_from_file, n); 
	//bubbleSort(array_from_file, n); 
	//mergeSort(array_from_file, n); 
	//selectionSort(array_from_file, n); 
	//insertionSort(array_from_file, n); 
	//timSort(array_from_file, n);
	quickSort(array_from_file, n);
	
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Elapsed time: " << elapsed.count() << " sec" << std::endl;
	
	FileManager::WriteDataUsePtrToFile(filenameOutput, array_from_file, size); 
	
	delete[] rand_arr;
    delete[] array_from_file;
	return 0;
}