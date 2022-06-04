#include<iostream>
using namespace std;
#include<algorithm>
int main() {
	int n;
	freopen("1.txt","r",stdin);
	int m;
	cin>>n>>m;
	int arr1[n][m];
	for(int i=0; i<n; i++) {
		for(int j=0;j<m; j++) {
			cin>>arr1[i][j];
		}
	}
	int x;
	for(int i=0; i<n; i++) {
		for(int j=0;j<m; j++) {
			cin>>x;
			cout<<arr1[i][j]+x<<" ";
		}
		if(i!=n-1) {
			cout<<endl;
		}
	}
	return 0;
}
