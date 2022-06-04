#include<iostream>
using namespace std;
void dy(int arr[][3]) {//二维数组 有些死脑经 尽量是同STL 
	for(int i=0; i<4; i++) {
		for(int j=0; j<3; j++) {
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}
void dy1(int *arr) {
	for(int i=0; i<4; i++) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main() {
	int arr[4][3]= {{1,2,3},{1,2,3},{1,2,3},{1,2,3}};
	dy(arr);
	int arr1[4]= {1,2,3,4};
	dy1(arr1);
}
