#include<iostream>
using namespace std;
//  ��������
//  Ч�ʸߵ����
//  1.�����л�������������---��(С)�Ķ���һ��
//  2.�������бȽ���
int main() { //��������
	int arr[10] = { 5,9,6,3,77,8,94,5,1,6 };
	int j;
	for (int i = 1; i < 10; i++) {
		if (arr[i] < arr[i - 1]) { //���˾��ÿ��ԣ���һ���Ѿ��жϣ����Ͽ�ʼ�ڶ����ж� 
			int temp = arr[i];
			for (j = i; j > 0 && temp < arr[j - 1]; j--) {//���һ��������ѭ����j������ "j--" ��Ҫ��
				arr[j] = arr[j - 1];
			}
			arr[j] = temp;
		}
	}
	cout << "***********" << endl;
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << "_";
	}
	cout << endl;
	return 0;
}
