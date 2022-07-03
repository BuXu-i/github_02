//ÀËÂşÊ÷
#include<iostream>
using namespace std;
#include<deque> 
int ki, n;
void  fun(int arr1[], int arr2[], int arr3[], int a, int b, int c, int s) {
	//ÓÒ
	//cout<<"?"<<endl;
	for (int i = c + 1; i <=b; i++) {
		if (arr2[ki] == arr1[i]) {
			arr3[s * 2 + 2] = arr2[ki];
			ki--;
			cout<<i<<endl; 
			fun(arr1, arr2, arr3, c, b, i, s * 2 + 2);
		}
	}
	for (int i = a ; i <=c; i++) {
		if (arr2[ki] == arr1[i]) {
			arr3[s * 2 + 1] = arr2[ki];
			ki--;
			fun(arr1, arr2, arr3, a, c, i, s * 2 + 1);
		}
	}
}
int main () {
	//int n;
	freopen("1.txt", "r", stdin);
	cin >> n;
	int arr1[n], arr2[n];
	for (int i = 0; i < n; i++) {
		//TODO
		cin >> arr1[i];
	}
	for (int i = 0; i <= n; i++) {
		//TODO
		cin >> arr2[i];
	}

	int arr3[1000]={0};//¹¹½¨Ç°Ğò
	ki = n - 2;
	arr3[0] = arr2[n - 1];
	int c;
	for (int i = 0; i < n; i++) {
		if (arr2[n - 1] == arr1[i]) {
			c = i;
			cout << " i " << i << endl;
			break;
		}
	}
//	cout << " i " << c << endl;
	for (int i = 0; i < n; i++) {
		cout << arr1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << arr2[i] << " ";
	}
	cout << endl;
	cout << c << endl;
	cout<<n<<" "<<ki<<endl;
	fun(arr1, arr2, arr3, 0, n - 1, c, 0);
	for (int i = 0; i < 30; i++) {
		if(arr3[i]!=0)
		cout << arr3[i] << " ";
	}
	return  0 ;
}
