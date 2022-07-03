#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
void fan(vector<bool>&arr,int pen,int k=0) {
	while (pen != 0) {
		if (pen % 2 == 0)
			k++;
		else
			arr[k++] = 1;
		pen = pen / 2;
	}
}
int  main() {
	int T, pen, k;
	cin >> T;
	vector<bool>arr(32, 0);
	while (T-- != 0) {
		cin >> pen;
		fan(arr, pen); //当前的数
		if (pen > 0) {
			arr[31] = 0;
		} else {
			arr[31] = 1;
			for (int i = 0; i < 30; i++) { //取反
				arr[i] = (arr[i] + 1) % 2;
			}
			k = -1;
			while (arr[++k] == 1) {
				arr[k] = 0;
			}
			arr[k] = 1;
		}
		for (int i = 31; i >= 0; i--) {
			cout << arr[i];
			arr[i] = 0;
		}
		cout << endl;
	}

}
