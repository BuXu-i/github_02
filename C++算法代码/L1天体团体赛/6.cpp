#include<iostream>
using namespace std;
#include<algorithm>//最小公倍数等于两数之积除以其最大公约数
int main() {
	int n,m;
	//freopen("1.txt","r",stdin);

	cin>>n>>m;
	int a=m,b=n;
	if(b>a) {
		swap(a,b);
	}
	while(b!=0) {
		a=a%b;
		swap(a,b);
	}
	cout<<a<<" "<<n*m/a;
		return 0;
}
