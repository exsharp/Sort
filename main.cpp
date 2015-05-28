#include <iostream>
using namespace std;

#include "sort.h"

typedef Util(*sort)(int[], int);

void print(int arr[], int n, Util(*sort)(int[], int)){

	int *tmp = new int[n]; //不破坏arr，创建副本
	for (int i = 0; i < n; i++)
	{
		tmp[i] = arr[i];
	}	
	
	//cout << "排序前:" << endl;
	//for (int i = 0; i < n; i++)
	//	cout << tmp[i] << " ";
	//cout << endl;

	Util util = sort(tmp, n);

	cout << "排序后:" << endl;
	for (int i = 0; i < n; i++)
		cout << tmp[i] << " ";

	cout << endl;
	cout << "比较次数:" << util.cmpTime << endl;
	cout << "移动次数:" << util.moveTime << endl;
	cout << endl;

	delete[] tmp;
}

int main()
{

	int arr[] = { 49, 38, 65, 97, 76, 13, 27, 49 ,100};
	//int arr[] = { 4 ,2 ,6 ,1, 5, 3};
	int len = sizeof(arr)/sizeof(arr[0]);
	//int len = 40;
	//int *arr = new int[len];
	//for (int i = 0; i < len; i++)
	//{
	//	arr[i] = rand() % 1000;
	//}
	//for (int i = 0; i < len; i++)
	//	cout << arr[i] << " ";
	//cout << endl << endl;

	//Merge(arr,0,len/2,len-1);


	//for (int i = 0; i < len; i++)
	//	cout << arr[i] << " ";
	//cout << endl << endl;


	cout << "插入排序:" ;
	print(arr, len, InsertSort);

	cout << "选择排序:";
	print(arr, len, SelectionSort);

	cout << "希尔排序:";
	print(arr, len, ShellSort);

	cout << "冒泡排序:";
	print(arr, len, BubbleSort);

	cout << "双向冒泡:";
	print(arr, len, BidBubbleSort);

	cout << "快速排序:";
	print(arr, len, QuickSortPrint);

	cout << "基数排序:";
	print(arr, len, RadixSort);

}