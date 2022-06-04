#include<iostream>
using namespace std;

int main () {
	int n;
	//freopen("1.txt","r",stdin);
	cin>>n;
	int arr=2;
	int s=0;
	for(int i=3; i<=n; i++) {
		int j=2;
		for(; j<i; j++) {
			if(i%j==0) {
				break;
			}
		}
		if(j==i) {
			//	cout<<j<<" ";
			if(i-arr==2) {
				s++;
				//	cout<<endl;
			}
			arr=i;
			i++;

		}
	}
	//cout<<endl ;
	cout<<s;
	return 0;
}
