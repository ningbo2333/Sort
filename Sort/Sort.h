#pragma once
#include<iostream>
#include<algorithm>
#include<time.h>
#include<vector>
using std::cout;
using std::endl;
using std::cin;
using std::min;
void Swap(int&, int&);//����������
void print_arr(int*, int);
void InsertSort(int*,int);//��������



void ShellSort(int*, int);//ϣ������  : �Բ���������Ż�

void SelectSort(int*,int);//ѡ������

void AdjustDown(int*, int, int);//����������µ���
void HeapSort(int*, int, int);//������

void QuickSort(int* arr, int left,int right);//��������
int PartSort(int*, int, int);//���������еĵ�������

void MergeSort(int*, int n);//�鲢�����������Ҳ�����ڶ��ļ�����������
void _MergeSort(int*, int, int, int*);//�鲢����ĵݹ飬�Ӻ���

void CountSort(int*, int);//��������