#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <chrono>
#include "files.h"
#include "countsort.h"
#include "radixsort.h"
#include "bucketsort.h"
#include "bubblesort.h"
#include "mergesort.h"
#include "selectionsort.h"
#include "insertionsort.h"
#include "timsort.h"
#include "qsort.h"

const int numberOfSortingAlgorithm = 9;
CountSort oCountSort;
RadixSort oRadixSort;
BucketSort oBucketSort;
BubbleSort oBubbleSort;
MergeSort oMergeSort;
SelectSort oSelectSort;
InsertSort oInsertSort;
TimSort oTimSort;
QSort oQSort;

struct Test
{
	BaseSort* pAlgorithm;
	std::string filenameOutput;
};

Test array [numberOfSortingAlgorithm] = {
	                                          {&oCountSort, "C://education/module11/files/sortedcountdata.txt"},
	                                          {&oRadixSort, "C://education/module11/files/sortedradixdata.txt"},
											  {&oBucketSort, "C://education/module11/files/sortedbucketdata.txt"},
											  {&oBubbleSort, "C://education/module11/files/sortedbubbledata.txt"},
											  {&oMergeSort, "C://education/module11/files/sortedmergedata.txt"},
											  {&oSelectSort, "C://education/module11/files/sortedselectdata.txt"},
											  {&oInsertSort, "C://education/module11/files/sortedinsertdata.txt"},
											  {&oTimSort, "C://education/module11/files/sortedtimdata.txt"},
                                              {&oQSort, "C://education/module11/files/sortedqdata.txt"}
											 };

int main(int argc, char* argv[])
{
	std::string filenameInput = "C://education/module11/files/unsorteddata.txt";
	const int size = (argc==2)?static_cast<int>(std::atof(argv[1])):static_cast<int>(5000);
	std::cout << size << std::endl;
    int* rand_arr = new int[size];
	
	srand(time(nullptr)); 
	
	int lef_border = 5;
    int range_len = 10;
	
	for (int i = 0; i < size; i++)
	{
		rand_arr[i] = lef_border + rand() % range_len; 
	}
	
	FileManager::WriteDataUsePtrToFile(filenameInput, rand_arr, size); 
	
	delete[] rand_arr;
	
	for (int i {0}; i < numberOfSortingAlgorithm; ++i)
	{
		int* array_from_file = nullptr;
        int n = 0;
        FileManager::ReadDataUsePtrFromFile(filenameInput, array_from_file, n); 
		auto start = std::chrono::high_resolution_clock::now(); 
		array[i].pAlgorithm->Sort(array_from_file, n);
		
		auto finish = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = finish - start;
		std::cout << "Elapsed time of " << array[i].pAlgorithm->getNameSortingAlgorithm() << " : " << elapsed.count() << " sec" << std::endl;
		
		FileManager::WriteDataUsePtrToFile(array[i].filenameOutput, array_from_file, size); 
		delete[] array_from_file;
	}
	
	return 0;
}