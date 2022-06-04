/*
下方 fun 函数  通常做法只传入  首 中 尾 ,函数中创建局部变量保存这些数据来计算，包括 中+1 ，额外空间创建在堆区，创建适合大小，并适时释放；
*/
#include<iostream>
using  namespace std;
//打印
void Prin(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
//并归
void fun(int arr[], int i_fri, int i_len, int j_fri, int j_len) {//
	cout << "对比区间:" << i_fri << " " << i_len << " " << j_fri << " " << j_len << endl;
	static int arr_f[10];
	static int nafe;
	nafe = 0;
	int fri = i_fri;
	//排序
	cout << "对比数据:";
	while (i_fri <= i_len && j_fri <=j_len )  //左右半自己前后比较 查看是否排序完成
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
	cout << "剩余数据:";
	//右半部分未完成
	while (j_fri <= j_len)
	{
		arr_f[nafe++] = arr[j_fri];
		j_fri++;
		cout << arr_f[nafe - 1] << " ";
	}
	//左半部分为完成
	while (i_fri <= i_len)
	{
		arr_f[nafe++] = arr[i_fri];
		i_fri++;
		cout << arr_f[nafe - 1] << " ";
	}
	cout << endl;
	//覆盖
	cout << "排序区间实际数据覆盖数据:" ;
	for (int i = 0; i < nafe; i++) {
		arr[i + fri] = arr_f[i];
		cout << arr_f[i] <<" ";
	}
	cout << endl;
	cout << "*" << "一次" << "*" <<endl;
	Prin(arr, 10);
	cout << "********结束********" << endl;
}
//分块
void Fen(int arr[], int fri, int len) {
	if (fri == len)return; //左半部分 会等于  右半部分会加一等于‘he’
	int mid = (fri + len) / 2;
	//左半部分
	Fen(arr, fri, mid);
	//右半部分
	Fen(arr, mid + 1, len);
	fun(arr, fri, mid, mid + 1, len);
}
//要求：升序排列
int main() {
	int arr[11] = { 12,25,17,19,51,32,45,18,22,37,15 };
	cout << "排序前:" << endl;
	Prin(arr, 10);
	Fen(arr, 0, 9);
	cout << "排序后:" << endl;
	Prin(arr, 10);
	return 0;
}
