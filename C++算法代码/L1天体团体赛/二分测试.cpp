#include<iostream>
using namespace std;

void fun(int ki,int a,int b,int *arr) {
	int suu;
	while(a<=b) {
		suu=(a+b)/2;
		if(arr[suu]>ki) {
			b=suu-1;
		} else if(arr[suu]<ki) {
			a=suu+1;
		} else {
			cout<<suu<<" "<<arr[suu];
			return ;
		}
	}
	cout<<suu<<" 没找到停在了此处 "<<arr[suu];
}
int main () {

	int arr[6]= {1,3,4,6,8,9};
	fun(5,0,5,arr);
}
