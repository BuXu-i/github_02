#include<iostream>
using namespace std;

int main() {
	int m,n;
	freopen("1.txt","r",stdin);
	cin>>m>>n;
	int arr[n][n];
	m=m%n;
	int ki;
	cout<<n<<" "<<m;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cout<<arr[i][j]<<" ";
		}
	}
	return 0;
}
