/*
�·� fun ����  ͨ������ֻ����  �� �� β ,�����д����ֲ�����������Щ���������㣬���� ��+1 ������ռ䴴���ڶ����������ʺϴ�С������ʱ�ͷţ�
*/
#include<iostream>
using  namespace std;
//��ӡ
void Prin(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
//����
void fun(int arr[], int i_fri, int i_len, int j_fri, int j_len) {//
	cout << "�Ա�����:" << i_fri << " " << i_len << " " << j_fri << " " << j_len << endl;
	static int arr_f[10];
	static int nafe;
	nafe = 0;
	int fri = i_fri;
	//����
	cout << "�Ա�����:";
	while (i_fri <= i_len && j_fri <=j_len )  //���Ұ��Լ�ǰ��Ƚ� �鿴�Ƿ��������
	{
		if (arr[i_fri] < arr[j_fri]) {
			arr_f[nafe++] = arr[i_fri];
			i_fri++;
		}
		else {
			arr_f[nafe++] = arr[j_fri];
			j_fri++;
		}
		cout << arr_f[nafe - 1] << " ";
	}
	cout << endl;
	cout << "ʣ������:";
	//�Ұ벿��δ���
	while (j_fri <= j_len)
	{
		arr_f[nafe++] = arr[j_fri];
		j_fri++;
		cout << arr_f[nafe - 1] << " ";
	}
	//��벿��Ϊ���
	while (i_fri <= i_len)
	{
		arr_f[nafe++] = arr[i_fri];
		i_fri++;
		cout << arr_f[nafe - 1] << " ";
	}
	cout << endl;
	//����
	cout << "��������ʵ�����ݸ�������:" ;
	for (int i = 0; i < nafe; i++) {
		arr[i + fri] = arr_f[i];
		cout << arr_f[i] <<" ";
	}
	cout << endl;
	cout << "*" << "һ��" << "*" <<endl;
	Prin(arr, 10);
	cout << "********����********" << endl;
}
//�ֿ�
void Fen(int arr[], int fri, int len) {
	if (fri == len)return; //��벿�� �����  �Ұ벿�ֻ��һ���ڡ�he��
	int mid = (fri + len) / 2;
	//��벿��
	Fen(arr, fri, mid);
	//�Ұ벿��
	Fen(arr, mid + 1, len);
	fun(arr, fri, mid, mid + 1, len);
}
//Ҫ����������
int main() {
	int arr[11] = { 12,25,17,19,51,32,45,18,22,37,15 };
	cout << "����ǰ:" << endl;
	Prin(arr, 10);
	Fen(arr, 0, 9);
	cout << "�����:" << endl;
	Prin(arr, 10);
	return 0;
}
