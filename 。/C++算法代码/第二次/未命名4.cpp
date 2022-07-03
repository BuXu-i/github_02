#include<iostream>
using namespace std;
#include<algorithm>
int main() {
	int n;
	freopen("1.txt","r",stdin);
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++) {
		cin>>arr[i];
	}
	for(int i=1; i<n; i++) {
		if(arr[i-1]==arr[i]) {
			int j=0;
			for(;j<n; j++) {
				if(arr[i-1]!=arr[j]) {
					swap(arr[j],arr[i]);
					break;
				}
			}
			if(j==n) {
				cout<<"NO";
				return 0;
			}
		}
	}
	cout<<"YES";

	return 0;
}
