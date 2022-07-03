/*堆排序*/ 
/*  使用长度来确定  父亲个数  注意是个数 
*初始化堆--从最下面开始往上调整 直到头顶最大，再交换首末元素
*之后 从头开始往下调整，遍历左右树大数上浮，小数沉底 ,能够保证（注意尾下标时刻减一） 
*该算法保证了  上层数据始终大于下层数据（不包括已找到正确位子元素）
*/
#include<iostream>
using namespace std;
void PrintArr(int myArr[], int len) {
	for (int i = 0; i < len; i++) {
		cout << myArr[i] << " ";
	}
	cout << endl;	
}
//交换
void MySwap(int arr[], int a, int b) {
	cout << "打印交换的两个坐标" << arr[a] << " " << arr[b] << endl;
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}
/*
myArr 待调整的数组
incdex 待调整的结点下标  用于比较的父结点
len 数组的长度
*/ //比较出最大数    //只负责比较传入数据
void HeapAdjust(int myArr[], int index, int len) {
	//保存当前父结点下标 //默认最大为父
	int max = index;
	//保存左右孩子的数组下标
	int lchild = index * 2 + 1;
	int rchild = index * 2 + 2;
	if (lchild<len&&myArr[lchild]>myArr[max]) {    //结点存在&&比较大小 保存大者下标
		max = lchild;
	}
	if (rchild<len&&myArr[rchild]>myArr[max]) {
		max = rchild;
	}
	if (max != index) {
		//交换两个结点
		MySwap(myArr, max, index);//交换父和最大
		HeapAdjust(myArr, max, len);
		PrintArr(myArr, 9);//打印
	}
}
//初始化堆 大顶堆
void HeapSort(int myArr[], int len) {
	int index = len;
	//初始化堆
	for (int i = index / 2 - 1; i >= 0; i--) { //最后一个用于交换    //遍历需要交换的结点 
		cout << "********:" << endl;
		HeapAdjust(myArr, i, index);//index 为 需要 排序 数组 的 子数组 末尾坐标
	}

	cout << "*****11323464***:" << endl;
	//后续操作！！！ 
	for (int i = len - 1; i >= 0; i--) {
		MySwap(myArr, 0, i);
		HeapAdjust(myArr, 0, i);
	}
}
int main() {
	int myArr[] = { 4,2,8,0,5,7,1,3,9 };
	int len = 9;
	cout << "排序前：" << endl;
	PrintArr(myArr, len);
	HeapSort(myArr, len);//排序函数
	cout << "排序后：" << endl;
	PrintArr(myArr, len);
	return 0;
}
