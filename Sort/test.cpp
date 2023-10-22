#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"
void test_InsertSort() {
	int arr[] = { 5,6,2,7,8,4,10 };
	int len = sizeof(arr) / sizeof(int);
	print_arr(arr,len);
	cout << endl;
	InsertSort(arr, len);
	print_arr(arr, len);
}

void test_ShellSort() {
	int arr[] = { 9,1,2,5,7,4,8,6,3,5 };
	int len = sizeof(arr) / sizeof(int);
	print_arr(arr, len);
	cout << endl;
	ShellSort(arr, len);
	print_arr(arr, len);
}

void test_SelectSort() {
	int arr[] = { 10,2,3,1 };
	int len = sizeof(arr) / sizeof(int);
	print_arr(arr, len);
	cout << endl;
	SelectSort(arr,len);
	print_arr(arr, len);
}

void test_AdjustDown() {
	int arr[] = { 5,2,3,4,1,0 };
	int len = sizeof(arr) / sizeof(int);
	AdjustDown(arr,len, 0);
	print_arr(arr, len);
}

void test_HeapSort(){
	int arr[] = { 5,1,2,6,4,3 };
	int len = sizeof(arr) / sizeof(int);
	HeapSort(arr, len, 0);
	print_arr(arr, len);
}

void test_PartSort() {
//	int  arr[] = { 5,9,51,25,36,12,1,5,46,5,8,15,20 };
	int arr[] = { 6,11,0,2,10,8 };
	int len = sizeof(arr) / sizeof(int);
	int a=PartSort(arr, 0, len - 1);
	print_arr(arr, len);
}

void test_QuickSort() {
	int arr[] = { 5,21,13,25,5,7,8,1,0,37,11 };
	int len = sizeof(arr) / sizeof(int);
	QuickSort(arr, 0, len - 1);
	print_arr(arr,len);
}

void test_MergeSort(){
	int arr[] = { 1,12,51,23,10,8,16,20,45,10,15,85};
	int len = sizeof(arr) / sizeof(int);
	int begin = clock();
	MergeSort(arr, len);
	int end = clock();
	print_arr(arr, len);
	cout << endl << "ºÄÊ±:" <<begin- end<<endl;
}

void test_CountSort() {
	int arr[] = { 1,5,2,45,12,54,63,36,78,95,12,120 };
	int len = sizeof(arr) / sizeof(int);
	CountSort(arr, len);
	print_arr(arr, len);
}

int main() {

	//test_InsertSort();//²âÊÔ²åÈëÅÅÐò
	//test_ShellSort();//²âÊÔÏ£¶ûÅÅÐò
	//test_SelectSort();//²âÊÔÑ¡ÔñÅÅÐò
	//test_AdjustDown();//²âÊÔ¶ÑÅÅÐòÖÐµÄÏòÏÂµ÷ÕûËã·¨
	//test_HeapSort();//²âÊÔ¶ÑÅÅÐò
	//test_PartSort();//²âÊÔ¿ìËÙÅÅÐòÖÐµÄÒ»´Îµ¥ÌËÅÅÐò
	//test_QuickSort();//²âÊÔ¿ìËÙÅÅÐò
	//test_MergeSort();//²âÊÔ¹é²¢ÅÅÐò
	test_CountSort();//²âÊÔ¼ÆÊýÅÅÐò
	return 0;
}
