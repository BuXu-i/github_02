#include<iostream>
using namespace std;
#include<algorithm>//��С��������������֮�����������Լ��
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
