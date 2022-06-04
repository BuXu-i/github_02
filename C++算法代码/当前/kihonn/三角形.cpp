#include <iostream>
using namespace std;
#include<algorithm>
int main() {
	int n;
	cin>>n;
	n=n+1;
	int arr[n][n]={0};
	for(int i=1; i<n; i++) {
		for(int j=1; j<=i; j++) {
			cin>>arr[i][j];
		}
	}
	for(int i=n-2; i>=1; i--) {
		for(int j=1; j<=i; j++) {
			arr[i][j]+=max(arr[i+1][j],arr[i+1][j+1]);
			cout<<arr[i][j]<<" ";
		}
	}
	cout<<" "<<arr[1][1];
	return 0;
}
