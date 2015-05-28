#include "sort.h"
#include <queue>
Util::Util()
{
	cmpTime = 0;
	moveTime = 0;
}

void Util::swap(int&a, int&b)
{
	int temp = a;
	a = b;
	b = temp;
	this->moveTime+=2;
}

bool Util::cmp(int a, int b)
{
	this->cmpTime++;
	return a >= b ? true : false;
}

void Util::move(int a, int &b)
{
	this->moveTime++;
	b = a;
}

Util InsertSort(int arr[], int n)
{
	Util util;
	for (int i = 1; i < n; i++){
		int key = arr[i];
		int j = i - 1;
		for (; j >= 0 ; j--){
			if (util.cmp(arr[j], key)){
				util.move(arr[j], arr[j + 1]);
			}
			else{
				break;
			}
		}
		if (i != (j + 1))
			util.move(key, arr[j + 1]);
	}

	return util;
}

Util SelectionSort(int arr[], int n)
{
	Util util;
	for (int i = 0; i < n; i++){
		int key = i;
		for (int j = i + 1; j < n; j++)
		{
			if (!util.cmp(arr[j], arr[key])){
				key = j;
			}
		}
		if (i!=key)
			util.swap(arr[i], arr[key]);
	}
	return util;
}

Util ShellSort(int arr[], int n)
{
	Util util;

	for (int gap = n / 2; gap > 0; gap /= 2) //����
	{
		for (int i = gap; i < n; i++){ //�������ǲ�������
			int key = arr[i];
			int j = i - gap;
			for (; j >= 0; j -= gap){
				if (util.cmp(arr[j],key)){
					util.move(arr[j], arr[j + gap]);
				}
				else{
					break;
				}
			}
			if (i != (j + gap))
				util.move(key, arr[j + gap]);
		}
	}

	return util;
}

Util BubbleSort(int a[], int n)
{
	Util util;

	int flag = n;
	while (flag > 0)
	{
		int k = flag;
		flag = 0;
		for (int j = 1; j < k; j++){//����С������
			if (util.cmp(a[j - 1],a[j]))
			{
				util.swap(a[j - 1], a[j]);
				flag = j;//��¼����󽻻���λ��
			}
		}
	}

	return util;
}

Util BidBubbleSort(int arr[], int n)
{
	Util util;
	int low, high, flag, i;
	low = 0;
	high = n - 1;
	while (low < high)
	{
		flag = 0;
		for (i = low; i<high; i++)  //����ð��  
		{
			if (util.cmp(arr[i] , arr[i + 1])) //�ҵ�ʣ��������  
			{
				util.swap(arr[i], arr[i + 1]);
				flag = 1;    //��־�� �����ݽ���  
			}
		}
		if (!flag)
			break;
		high--;
		for (i = high; i>low; i--) //����ð��  
		{
			if (util.cmp(arr[i-1], arr[i]))   //�ҵ�ʣ������С��  
				util.swap(arr[i], arr[i - 1]);
		}
		low++;
	}
	return util;
}

//Util MerginSort()

Util QuickSort(int arr[],int low, int high)
{
	Util util;
	if (low < high)
	{
		int originLow = low;
		int originHigh = high;
		  
		int key = arr[low];
		
		while (low < high)
		{
			while (low < high && util.cmp(arr[high], key)) // ���������ҵ�һ��С��x����  
				high--;
			util.move(arr[high], arr[low]);

			while (low < high && !util.cmp(arr[low],key)) // ���������ҵ�һ�����ڵ���x����  
				low++;
			util.move(arr[low], arr[high]);
		}
		arr[low] = key;
		Util u1 = QuickSort(arr,originLow, low-1); // �ݹ����   
		Util u2 = QuickSort(arr, low+1, originHigh);
		util.cmpTime += u1.cmpTime + u2.cmpTime;
		util.moveTime += u1.moveTime + u2.moveTime;
	}
	return util;
}

Util Merge(int a[],int low,int mid,int high)
{
	Util util;
	int *tmp = new int[high];
	int i = 0;
	
	int left = low;
	int right = mid;

	while(!util.cmp(left,mid)&&util.cmp(high,right))
	{
		if (!util.cmp(a[left],a[right])){  //left bigger than right
			util.move(a[left++],tmp[i++]);
		}else{
			util.move(a[right++],tmp[i++]);
		}
	}

	while(!util.cmp(left,mid)){
		util.move(a[left++],tmp[i++]);
	}

	while(util.cmp(high,right)){
		util.move(a[right++],tmp[i++]);
	}
	
	for (i = 0;i<=high;i++){
		a[i]=tmp[i];
	}

	return util;
}


Util RadixSort(int arr[], int n)
{
	Util util;
	//��������
	int maxInt = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (util.cmp(arr[i], maxInt)){
			util.move(arr[i], maxInt);
		}
	}
	//������λ
	int max = 0;
	for (;maxInt>0; max++)
	{
		maxInt /= 10;
	}
	std::queue<int> q[10];
	for (int k = 1,time=1; k <= max; k++,time*=10){//����

		for (int i = 0; i < n; i++){//��
			int bit = (arr[i]/time) % 10;
			util.moveTime++;
			q[bit].push(arr[i]);
		}

		for (int i = 0,j=0; i < 10; i++){//��
			while (!q[i].empty()){
				util.moveTime++;
				arr[j] = q[i].front();
				q[i].pop();
				j++;
			}
		}
	}
	return util;
}

Util MergingSort(int arr[], int n)
{
	Util util;
	return util;
}


Util QuickSortPrint(int arr[], int n)
{
	return QuickSort(arr, 0, n - 1);
}