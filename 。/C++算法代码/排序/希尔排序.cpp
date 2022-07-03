#include<iostream>
using namespace std;
//希尔排序  可以说是插入排序的升级版
//1.数据量大时效率高
// ----原理 ----
//分组插入排序
// 先分组 对每组进行插入排序
//增量的选择  序列个数 / 3 + 1 ;
//每一次进行插入排序
int main() {
	int increasement = 10;
	int i, j, k;
	int arr[10] = { 5,9,6,3,77,8,94,5,1,6 };
	do {
		increasement = increasement / 3 + 1;    //确定分组区间 大小
		for (i = 0; i < increasement; i++) {    //确定各区间的首元素,increasement多个则几个为一组
			for (j = i + increasement; j < 10; j += increasement) {   //j=i+increasement j表示分组的第二个
				if (arr[j] < arr[j - increasement]) {    //第二个和第一个比较
					int temp = arr[j];   //将小的拿出来，坐标是大的
					for (k = j - increasement; k >= 0 && temp < arr[k]; k -= increasement) {
						arr[k + increasement] = arr[k];
					}
					arr[k + increasement] = temp;     //这里的arr【】为arr【k】;
				}
			}
		}
	} while (increasement > 1);
	for (i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}
