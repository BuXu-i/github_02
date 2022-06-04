#include<iostream>
using namespace std;
//快速排序  最快排序
//越是无序的数据，快速排序相对其他排序速度越快的
//---原理--
//分治法 和 挖坑填数
//先选择一个基准数
//-----快速排序使用递归完成------
//打印 
void PrintArr(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
void  QuickSort(int *arr, int start, int len) {
	int i = start;
	int j = len;
	int temp = arr[i];//等于第一个 记录
	if (i < j) {
		while (i < j) {   //5,9,6,3,77,8,94,5,1,6    10ge  0he 9
			while (i < j && arr[j]>temp) {
				j--;
			}
			if (i < j) {//避免是因为不满足i<j而退出循环
				arr[i] = arr[j];
				i++;
			}
			while (i < j && arr[i] < temp) {
				i++;
			}
			if (i < j) { //避免是因为不满足i<j而退出循环
				arr[j] = arr[i];
				j--;
			}
		}
		arr[j] = temp;//i和j相等时退出 即i和j都指在最后空出来的位置
		QuickSort(arr, start, i - 1);
		QuickSort(arr, i + 1, len);
	}
}
int main() {
	int arr[11] = { 12,25,17,19,51,32,45,18,22,37,15 };
	int len = sizeof(arr) / sizeof(int);
	PrintArr(arr, len);
	QuickSort(arr, 0, len - 1);
	PrintArr(arr, len);
	return 0;
}
//
//void PrintArr(int arr[], int len) {
//	for (int i = 0; i < len; i++) {
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//}
////快速排序
//void QuickSort(int arr[], int start, int len) { //int start--第一个   int len--最后一个
//	int i = start;
//	int j = len;
//	int temp = arr[start];//基准数
//	if (i < j) {
//		while (i < j) {
//			while (i < j&&arr[j] >= temp) {
//				j--;
//			}
//			if (i < j) { //填坑
//				arr[i] = arr[j];
//				i++;
//			}
//			while (i < j&&arr[i] <= temp) {
//				i++;
//			}
//			if (i < j) {
//				arr[j] = arr[i];
//				j--;
//			}
//		}
//		arr[i] = temp;//放入基准数
//		//左半部分
//		QuickSort(arr, start, i - 1);
//		//右半部分
//		QuickSort(arr, i + 1, len);
//	}
//}
//int main() {
//	int arr[10] = { 5,9,6,3,77,8,94,5,1,6 };
//	int len = sizeof(arr) / sizeof(int);
//	PrintArr(arr, len);
//	QuickSort(arr, 0, len - 1);
//	PrintArr(arr, len);
//	return 0;
//}
