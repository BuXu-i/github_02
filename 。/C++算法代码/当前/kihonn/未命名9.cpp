#include<iostream>
using namespace std;

int main() {
	int m,n;
	freopen("1.txt","r",stdin);
	cin>>m>>n;
	int arr[n+1][n+1];
	m=m%n-1;
	int ki;
//	cout<<"m="<<m<<endl;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin>>arr[i][j];
		}
		ki=m;
		for(int k=n; k>0; k--) {
			if(ki==n)ki=0;
			cout<<arr[i][ki++]<<" ";
		}
		if(i!=n-1)
			cout<<endl;
	}
	return 0;
}
