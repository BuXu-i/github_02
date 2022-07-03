#include<iostream>
using namespace  std;

int main() {
	long long n;
	cin>>n;
	long long a=0,b=0;
	while (n>0) {
		if(a>b) {
			b+=30*3;
			n-=30;
		} else {
			n-=10;
			a+=9*10;
			b+=3*10;
		}
	}
	if(n!=0) {
		a+=n*9;
		b+=n*3;
	}
	if(a>b)cout<<"^_^ "<<a;
	else if(a==b)cout<<"-_- "<<a;
	else cout<<"@_@ "<<b;
	return 0;
}
