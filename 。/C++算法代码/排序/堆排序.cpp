/*������*/ 
/*  ʹ�ó�����ȷ��  ���׸���  ע���Ǹ��� 
*��ʼ����--�������濪ʼ���ϵ��� ֱ��ͷ������ٽ�����ĩԪ��
*֮�� ��ͷ��ʼ���µ��������������������ϸ���С������ ,�ܹ���֤��ע��β�±�ʱ�̼�һ�� 
*���㷨��֤��  �ϲ�����ʼ�մ����²����ݣ����������ҵ���ȷλ��Ԫ�أ�
*/
#include<iostream>
using namespace std;
void PrintArr(int myArr[], int len) {
	for (int i = 0; i < len; i++) {
		cout << myArr[i] << " ";
	}
	cout << endl;	
}
//����
void MySwap(int arr[], int a, int b) {
	cout << "��ӡ��������������" << arr[a] << " " << arr[b] << endl;
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}
/*
myArr ������������
incdex �������Ľ���±�  ���ڱȽϵĸ����
len ����ĳ���
*/ //�Ƚϳ������    //ֻ����Ƚϴ�������
void HeapAdjust(int myArr[], int index, int len) {
	//���浱ǰ������±� //Ĭ�����Ϊ��
	int max = index;
	//�������Һ��ӵ������±�
	int lchild = index * 2 + 1;
	int rchild = index * 2 + 2;
	if (lchild<len&&myArr[lchild]>myArr[max]) {    //������&&�Ƚϴ�С ��������±�
		max = lchild;
	}
	if (rchild<len&&myArr[rchild]>myArr[max]) {
		max = rchild;
	}
	if (max != index) {
		//�����������
		MySwap(myArr, max, index);//�����������
		HeapAdjust(myArr, max, len);
		PrintArr(myArr, 9);//��ӡ
	}
}
//��ʼ���� �󶥶�
void HeapSort(int myArr[], int len) {
	int index = len;
	//��ʼ����
	for (int i = index / 2 - 1; i >= 0; i--) { //���һ�����ڽ���    //������Ҫ�����Ľ�� 
		cout << "********:" << endl;
		HeapAdjust(myArr, i, index);//index Ϊ ��Ҫ ���� ���� �� ������ ĩβ����
	}

	cout << "*****11323464***:" << endl;
	//�������������� 
	for (int i = len - 1; i >= 0; i--) {
		MySwap(myArr, 0, i);
		HeapAdjust(myArr, 0, i);
	}
}
int main() {
	int myArr[] = { 4,2,8,0,5,7,1,3,9 };
	int len = 9;
	cout << "����ǰ��" << endl;
	PrintArr(myArr, len);
	HeapSort(myArr, len);//������
	cout << "�����" << endl;
	PrintArr(myArr, len);
	return 0;
}
