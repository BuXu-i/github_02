#include<iostream>
using namespace std;

int main() {
	int n;
	freopen("1.txt","r",stdin);
	int x;
	int s=0;
	while(true) {
		cin>>x;
		if(x<=0) {
			cout<<s;
			return 0;
		}
		if(x%2==1) {
			s+=x;
		}
	}
	return 0;
}
