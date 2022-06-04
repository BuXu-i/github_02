#include<iostream>
using namespace std;
#include<algorithm>
bool npm(int a,int b) {
	return a>b;
}
int main() {
	int n;
	//freopen("1.txt","r",stdin);

	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++) {
		cin>>arr[i];
	}
	sort(arr,arr+n,npm);
	for(int i=0; i<n; i++) {
		cout<<arr[i];
		if(i!=n-1)
			cout<<" ";
	}
	return 0;
}
