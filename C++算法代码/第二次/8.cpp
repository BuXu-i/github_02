#include<iostream>
using namespace std;
#include<algorithm>
int main() {
	int n;
	freopen("1.txt","r",stdin);
	cin>>n;
	for(int i=n-1; i>1; i--) {
		int j=2;
		for(; j<i; j++) {
			if(i%j==0) {
				break;
			}
		}
		if(j==i) {
			cout<<i;
			return 0;
		}

	}
	return 0;
}
