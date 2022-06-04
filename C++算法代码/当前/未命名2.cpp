#include<iostream>
using namespace std;
#include<algorithm>
void fun(int arr[3],int k) {
	if(k==4) {
		for(int i=0; i<5; i++) {
			cout<<arr[i]<<" ";
		}
		cout<<endl;
		return;
	}
	for(int i=k; i<5; i++) {
		swap(arr[k], arr[i]);
		fun(arr,k+1);

		swap(arr[k], arr[i]);
	}
}

int main() {
	int arr[5]= {1,2,3,4,5};
	fun(arr,0);
}
