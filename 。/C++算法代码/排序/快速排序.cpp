#include<iostream>
using namespace std;
//��������  �������
//Խ����������ݣ���������������������ٶ�Խ���
//---ԭ��--
//���η� �� �ڿ�����
//��ѡ��һ����׼��
//-----��������ʹ�õݹ����------
//��ӡ 
void PrintArr(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
void  QuickSort(int *arr, int start, int len) {
	int i = start;
	int j = len;
	int temp = arr[i];//���ڵ�һ�� ��¼
	if (i < j) {
		while (i < j) {   //5,9,6,3,77,8,94,5,1,6    10ge  0he 9
			while (i < j && arr[j]>temp) {
				j--;
			}
			if (i < j) {//��������Ϊ������i<j���˳�ѭ��
				arr[i] = arr[j];
				i++;
			}
			while (i < j && arr[i] < temp) {
				i++;
			}
			if (i < j) { //��������Ϊ������i<j���˳�ѭ��
				arr[j] = arr[i];
				j--;
			}
		}
		arr[j] = temp;//i��j���ʱ�˳� ��i��j��ָ�����ճ�����λ��
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
////��������
//void QuickSort(int arr[], int start, int len) { //int start--��һ��   int len--���һ��
//	int i = start;
//	int j = len;
//	int temp = arr[start];//��׼��
//	if (i < j) {
//		while (i < j) {
//			while (i < j&&arr[j] >= temp) {
//				j--;
//			}
//			if (i < j) { //���
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
//		arr[i] = temp;//�����׼��
//		//��벿��
//		QuickSort(arr, start, i - 1);
//		//�Ұ벿��
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
