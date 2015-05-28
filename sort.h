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

Util InsertSort(int arr[], int n);//��������
Util SelectionSort(int arr[], int n);//ѡ������
Util ShellSort(int[], int);//ϣ������
//������
Util BubbleSort(int[], int);//ð������
Util BidBubbleSort(int[], int);//˫��ð������
Util QuickSort(int[],int,int);//��������
Util MergingSort(int[], int);//�鲢�ǵݹ�
Util MergingSort_recursion(int[], int);//�鲢�ݹ�
Util RadixSort(int[], int);//��������

/*
	�鲢���򲿷�
*/
Util Merge(int[],int,int,int/*���λ���±�*/);

Util QuickSortPrint(int[], int);
#endif