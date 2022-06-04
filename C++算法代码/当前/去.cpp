#include<iostream>
using namespace std;
#include<algorithm>
void fun(int arr[4],int k) {
	if(k==3) {
		for(int i=0; i<3; i++) {
			cout<<arr[i]<<" ";
		}
		cout<<arr[3]<<endl;
		return;
	}
	for(int i=k; i<4; i++) {
		swap(arr[k], arr[i]);
		fun(arr,k+1);
		if(k!=0) {
			swap(arr[k], arr[i]);
		}
	}
}

int main() {
	int arr[4]= {1,2,3,4};
	fun(arr,0);
}
