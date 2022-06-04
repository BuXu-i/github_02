#include<iostream>
using namespace std;
int main() {
	int n;
//	freopen("1.txt","r",stdin);
	cin>>n;
	int s=1;
	while(--n) {
		s=(s+1)*2;
	}
	cout<<s;
	return 0;
}
