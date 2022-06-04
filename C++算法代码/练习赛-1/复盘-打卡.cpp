#include<iostream>
using namespace std;
#include<algorithm>
int s=0;
int nb;
void fun(int arr1[],int arr2[],int ki,int m,int ski) {
	if(m-arr1[ki]<0||ki>=nb) {
		return ;
	}
	s=max(s,ski+arr2[ki]);
	fun(arr1,arr2,ki+1,m-arr1[ki],ski+arr2[ki]);//È¡
	fun(arr1,arr2,ki+1,m,ski);//²»È¡
}
int main() {
	freopen("1.txt","r",stdin);
	int n,m;
	cin>>n>>m;
	nb=n;
	int arr1[n],arr2[n];
	for(int i=0; i<n; i++) {
		cin>>arr1[i];
	}
	for(int i=0; i<n; i++) {
		cin>>arr2[i];
	}
//	for(int i=0; i<n; i++) {
//		cout<<arr1[i]<<" ";
//	}
//	cout<<endl;
//	for(int i=0; i<n; i++) {
//		cout<<arr2[i]<<" ";
//	}
//	cout<<endl;
	fun(arr1,arr2,0,m,0);
	cout<<s;
	return 0;
}
