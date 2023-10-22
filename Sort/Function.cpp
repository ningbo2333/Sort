#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"
#include<assert.h>
void Swap(int&a, int&b)//����������
{
	int temp=a;
	a = b;
	b = temp;
}

void print_arr(int* arr, int len) {//��ӡ����
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
}




void InsertSort(int* arr, int n)//��������
{
	
	assert(arr);
	for(int i=0;i<=n-2;i++){//ÿ�ν��е������򣬴ӵ�һ��λ�ÿ�ʼ��ֱ�����һ����ǰ�߽���
	//��������
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
	//�ϱߡ�������
	}
}

void ShellSort(int* arr, int len) {	//ϣ������:�൱�ڲ���������Ż�
	int gap=len;//������
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



void SelectSort(int*arr,int len)//ѡ������
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


void AdjustDown(int* arr, int len, int root)//����������µ���
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
void HeapInit(int* arr, int len, int root) {//��ʼ����
	root = (len - 1) / 2;
		while (root >= 0) {
			AdjustDown(arr, len, root);
			root--;
		}
}
void HeapSort(int* arr, int len, int root)//������
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
void QuickSort(int* arr, int left,int right) {//��������
	if (left >= right) {
		return;
	}
	int div = PartSort(arr, left, right);
	QuickSort(arr, left, div - 1);
	QuickSort(arr, div+1, right);


}




int PartSort(int* arr, int left,int right) {//���������еĵ���
	//��������
	//int key = arr[right];//ѡ�����ұߵ�����Ϊkey�������Ǳ��������ʱ��������
	//int key_index = right;//����key���±�
	//while (left < right) {
	//	while (left != right && arr[left] <= key)//����߿�ʼ�ң���������key��ֵС�ڻ��ߵ��ڣ���ô���������Ҳ���left!=right
	//	{
	//		left++;//left�����ƶ�
	//	}
	//	while (left!=right&&arr[right]>=key)
	//	{
	//		right--;//right�����ƶ�
	//	}
	//	//����λ�ñ�ʾ�ҵ�һ���ˣ���key���keyС�ģ���ʱ��������Ԫ��
	//	Swap(arr[left], arr[right]);
	//}
	////��left==rightʱ��ѭ���˳��ˣ���ʱ����Ҫ��key��left==right��λ�ý�������Ϊ�������ܱ�֤��ʱ�������߶���С��key��ֵ���ұ߶��Ǵ���key��ֵ
	//Swap(arr[left], arr[key_index]);
	//return left;//��ʱֵΪdiv��ֵ�����ʱ��key��λ�ù̶��ˣ���������




	//2.˫ָ�뷨
	int key = arr[right];
	int key_index = right;
	int prev = left - 1;//����һ��ʼ�ĵ���cur��ǰ�ߵ�һ��
	int cur = left;//����curΪ����ߵ�
	while (cur <right) {//��cur<�ұߣ����Ե����ұߵĺ�һ��
		if(arr[cur] < key) {//���������keyС����
			Swap(arr[++prev], arr[cur]);//��������������ʹ���Լ����Լ�����Ҳ����ν
		}
		cur++;//��������Ĳ��Ǳ�keyС��������ôcur������ǰ�ƶ���ֱ����һ���ҵ���keyС�������������Ļ���С��
	}
	Swap(arr[prev + 1], arr[key_index]);//���prev++1��λ�ÿ϶��Ǳ�key�����
	return prev + 1;
}



void MergeSort(int* arr, int len) {
	int* temp = new int[len];
	_MergeSort(arr, 0,len-1,temp);
	delete temp;
}


void _MergeSort(int*arr, int left, int right, int* temp)//�鲢����ĵݹ飬�Ӻ���
{
	//�ݹ鷽��
	if (left >= right) { //��ֻ��һ����ʱ�򷵻�
		return; }
	int mid = (left + right) / 2;
	_MergeSort(arr, left, mid, temp);
	_MergeSort(arr, mid+1, right, temp);
	//��ʱ����Ϊ[left,right]֮ǰ���Ե���
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
	for(int i=left;i<=right;i++){//������丳ֵ��ԭ��������arr
		arr[i] = temp[i];
	}
}



void CountSort(int* arr, int len) //��������
{
	int max=arr[0], min=arr[0];
	for (int i = 0; i < len; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
		if (arr[i] < min) {
			min = arr[i];
		}
	}//��ʱ�ҳ�������Сֵ
	int range = max - min+1;//�����������ӵ�е����ֻ���Ҫ��һ
	int* temp = new int[range]();

	for (int i = 0; i < len; i++) {//����Ӧֵ���±����Сֵ���±꣬����
		temp[arr[i] - min]++;
	}
	int index = 0;//����һ��ʼ�������Ԫ���±꣬��0��ʼ
	for (int  j= 0; j < range; j++) {
		while (temp[j]--) {//���������Ϊ0
			arr[index++] = j + min;
		}
	}
	delete temp;
}