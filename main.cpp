#include <iostream>
using namespace std;

#include "sort.h"

typedef Util(*sort)(int[], int);

void print(int arr[], int n, Util(*sort)(int[], int)){

	int *tmp = new int[n]; //���ƻ�arr����������
	for (int i = 0; i < n; i++)
	{
		tmp[i] = arr[i];
	}	
	
	//cout << "����ǰ:" << endl;
	//for (int i = 0; i < n; i++)
	//	cout << tmp[i] << " ";
	//cout << endl;

	Util util = sort(tmp, n);

	cout << "�����:" << endl;
	for (int i = 0; i < n; i++)
		cout << tmp[i] << " ";

	cout << endl;
	cout << "�Ƚϴ���:" << util.cmpTime << endl;
	cout << "�ƶ�����:" << util.moveTime << endl;
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


	cout << "��������:" ;
	print(arr, len, InsertSort);

	cout << "ѡ������:";
	print(arr, len, SelectionSort);

	cout << "ϣ������:";
	print(arr, len, ShellSort);

	cout << "ð������:";
	print(arr, len, BubbleSort);

	cout << "˫��ð��:";
	print(arr, len, BidBubbleSort);

	cout << "��������:";
	print(arr, len, QuickSortPrint);

	cout << "��������:";
	print(arr, len, RadixSort);

}