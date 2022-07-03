#include<iostream>
using namespace std;
//  插入排序
//  效率高的情况
//  1.在序列基本有序的情况下---大(小)的都在一侧
//  2.数据序列比较少
int main() { //升序排列
	int arr[10] = { 5,9,6,3,77,8,94,5,1,6 };
	int j;
	for (int i = 1; i < 10; i++) {
		if (arr[i] < arr[i - 1]) { //个人觉得可以：第一次已经判断，马上开始第二次判断 
			int temp = arr[i];
			for (j = i; j > 0 && temp < arr[j - 1]; j--) {//最后一不成立的循环，j运行了 "j--" 重要点
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
