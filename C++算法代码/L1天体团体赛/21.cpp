#include<iostream>
using namespace std;
#include<algorithm>
#include<math.h>
int main() {
	double n;
	freopen("1.txt","r",stdin);
	double a,b,c;
	cin>>a>>b>>c;
	if(a+b>c&&c+a>b&&c+b>a) {
		n=(a+b+c)/2.0;
		n=sqrt(n*(n-a)*(n-b)*(n-c));
		cout<<n;
	}
	else cout<<"No;
	return 0;
}
