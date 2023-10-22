#pragma once
#include<iostream>
#include<algorithm>
#include<time.h>
#include<vector>
using std::cout;
using std::endl;
using std::cin;
using std::min;
void Swap(int&, int&);//交换两个数
void print_arr(int*, int);
void InsertSort(int*,int);//插入排序



void ShellSort(int*, int);//希尔排序  : 对插入排序的优化

void SelectSort(int*,int);//选择排序

void AdjustDown(int*, int, int);//堆排序的向下调整
void HeapSort(int*, int, int);//堆排序

void QuickSort(int* arr, int left,int right);//快速排序
int PartSort(int*, int, int);//快速排序中的单趟排序

void MergeSort(int*, int n);//归并排序，这个排序也适用于对文件的数据排序
void _MergeSort(int*, int, int, int*);//归并排序的递归，子函数

void CountSort(int*, int);//计数排序