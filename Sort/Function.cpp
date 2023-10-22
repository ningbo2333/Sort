#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"
#include<assert.h>
void Swap(int&a, int&b)//交换两个数
{
	int temp=a;
	a = b;
	b = temp;
}

void print_arr(int* arr, int len) {//打印数组
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
}




void InsertSort(int* arr, int n)//插入排序
{
	
	assert(arr);
	for(int i=0;i<=n-2;i++){//每次进行单趟排序，从第一个位置开始，直至最后一个的前边结束
	//单趟排序
	int end=i;
	int temp = arr[end + 1];
	while (end >= 0) {
		if (arr[end] > temp) {
			arr[end + 1] = arr[end];
			end--;
		}
		else {
			break;
		}
	}
	arr[end + 1] = temp;
	//上边——单趟
	}
}

void ShellSort(int* arr, int len) {	//希尔排序:相当于插入排序的优化
	int gap=len;//定义间距
	while (gap > 1) {
		gap = gap / 3 + 1;
		for (int i = 0; i <= len - gap - 1; i++) {
			int end = i;
			int temp = arr[end + gap];
			while (end >= 0) {
				if (arr[end] > temp) {
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else {
					break;
				}
				arr[end + gap] = temp;
			}
		}
	}
}



void SelectSort(int*arr,int len)//选择排序
{
	int min_i;
	for (int i = 0; i < len; i++) {
		min_i = i;
		for (int j = i; j < len - i-1; j++) {
			min_i= arr[j] > arr[j + 1] ? j + 1 : j;
		}
		Swap(arr[i], arr[min_i]);
	}

}


void AdjustDown(int* arr, int len, int root)//堆排序的向下调整
{
	int parent = root;
	int child = 2*parent+1 ;
	while (child < len) {
		if (child+1<len&&arr[child+1] > arr[child]) { 
			child++; }
		if (arr[parent] < arr[child]) {
			Swap(arr[parent], arr[child]);
			parent = child;
			child = parent * 2;
		}
		else {
			break;
		}

	}

}
void HeapInit(int* arr, int len, int root) {//初始化堆
	root = (len - 1) / 2;
		while (root >= 0) {
			AdjustDown(arr, len, root);
			root--;
		}
}
void HeapSort(int* arr, int len, int root)//堆排序
{
	for(int i=len;i>0;i--){
		HeapInit(arr,i,root);
		Swap(arr[0], arr[i-1]);
	}
}



//int PartSort(int* arr, int begin, int end) 
//{
//	int key = arr[end];
//	int key_index = end;
//	while (begin < end) {
//		while (begin!=end&&arr[begin] <= key) {
//			begin++;
//		}
//		while (begin!=end&&arr[end] >= key) {
//			end--;
//		}
//		Swap(arr[begin], arr[end]);
//	}
//	Swap(arr[begin], arr[key_index]);
//	return begin;
//
//}
void QuickSort(int* arr, int left,int right) {//快速排序
	if (left >= right) {
		return;
	}
	int div = PartSort(arr, left, right);
	QuickSort(arr, left, div - 1);
	QuickSort(arr, div+1, right);


}




int PartSort(int* arr, int left,int right) {//快速排序中的单次
	//单趟排序
	//int key = arr[right];//选定最右边的数字为key，故我们必须排序的时候从左边找
	//int key_index = right;//保存key的下标
	//while (left < right) {
	//	while (left != right && arr[left] <= key)//从左边开始找，如果比这个key的值小于或者等于，那么继续往下找并且left!=right
	//	{
	//		left++;//left向左移动
	//	}
	//	while (left!=right&&arr[right]>=key)
	//	{
	//		right--;//right向右移动
	//	}
	//	//到此位置表示找到一组了，比key大比key小的，此时交换两个元素
	//	Swap(arr[left], arr[right]);
	//}
	////当left==right时候，循环退出了，此时我们要把key与left==right的位置交换，因为这样才能保证此时数组的左边都是小于key的值，右边都是大于key的值
	//Swap(arr[left], arr[key_index]);
	//return left;//此时值为div的值，这个时候key的位置固定了，在数祖里




	//2.双指针法
	int key = arr[right];
	int key_index = right;
	int prev = left - 1;//定义一开始的等于cur的前边的一个
	int cur = left;//定义cur为最左边的
	while (cur <right) {//当cur<右边，可以等于右边的后一个
		if(arr[cur] < key) {//如果遇到比key小的数
			Swap(arr[++prev], arr[cur]);//交换两个数，即使是自己和自己交换也无所谓
		}
		cur++;//如果遇到的不是比key小的数，那么cur继续往前移动，直到下一次找到比key小的数，把这个大的换成小的
	}
	Swap(arr[prev + 1], arr[key_index]);//最后prev++1的位置肯定是比key大的数
	return prev + 1;
}



void MergeSort(int* arr, int len) {
	int* temp = new int[len];
	_MergeSort(arr, 0,len-1,temp);
	delete temp;
}


void _MergeSort(int*arr, int left, int right, int* temp)//归并排序的递归，子函数
{
	//递归方法
	if (left >= right) { //当只有一个数时候返回
		return; }
	int mid = (left + right) / 2;
	_MergeSort(arr, left, mid, temp);
	_MergeSort(arr, mid+1, right, temp);
	//此时区间为[left,right]之前可以调整
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;
	while (begin1 <= end1 && begin2 <= end2) {
		if (arr[begin1] < arr[begin2])
		{
			temp[index++] = arr[begin1++];
		}
		else {
			temp[index++] = arr[begin2++];
		}
	}
	while (begin1 <= end1) {
		temp[index++] = arr[begin1++];
	}
	while (begin2 <= end2) {
		temp[index++] = arr[begin2++];
	}
	for(int i=left;i<=right;i++){//最后将区间赋值给原来的数组arr
		arr[i] = temp[i];
	}
}



void CountSort(int* arr, int len) //计数排序
{
	int max=arr[0], min=arr[0];
	for (int i = 0; i < len; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
		if (arr[i] < min) {
			min = arr[i];
		}
	}//此时找出最大和最小值
	int range = max - min+1;//两个数相减，拥有的数字还需要加一
	int* temp = new int[range]();

	for (int i = 0; i < len; i++) {//将对应值的下标减最小值的下标，计数
		temp[arr[i] - min]++;
	}
	int index = 0;//定义一开始的数组的元素下标，从0开始
	for (int  j= 0; j < range; j++) {
		while (temp[j]--) {//如果计数不为0
			arr[index++] = j + min;
		}
	}
	delete temp;
}