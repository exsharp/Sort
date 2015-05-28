#ifndef _SORT_H_
#define _SORT_H_ 

struct Util{
	int cmpTime;
	int moveTime;
	Util();
	void swap(int &, int &);
	bool cmp(int, int);
	void move(int, int&);
};

Util InsertSort(int arr[], int n);//插入排序
Util SelectionSort(int arr[], int n);//选择排序
Util ShellSort(int[], int);//希尔排序
//堆排序
Util BubbleSort(int[], int);//冒泡排序
Util BidBubbleSort(int[], int);//双向冒泡排序
Util QuickSort(int[],int,int);//快速排序
Util MergingSort(int[], int);//归并非递归
Util MergingSort_recursion(int[], int);//归并递归
Util RadixSort(int[], int);//基数排序

/*
	归并排序部分
*/
Util Merge(int[],int,int,int/*最高位的下标*/);

Util QuickSortPrint(int[], int);
#endif