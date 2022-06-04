#include<iostream>
using namespace std;
#include<algorithm>
int main() {
	freopen("1.txt","r",stdin);
	string a,b,c;
	cin>>a>>b;
	if(a.size()<b.size())swap(a,b);
	if(a.size()==b.size())a='0'+a;
	for(int i=b.size()-1,j=a.size()-1; i>=0; i--,j--) {
		
		if(b[i]+a[j]-'0'-'0'>=10) {
			a[j-1]++;
			a[j]=a[j]+b[i]-'0'-10;
		} else {
			a[j]=a[j]+b[i]-'0';
		}
	}
//	cout<<a<<" "<<b<<endl;
	if(a[0]>'9') {
		a='1'+a;
		a[1]-=10;
	}
//	cout<<a<<endl;
	else if(a[0]=='0')a.erase(0,1);
	cout<<a;
	return 0;
}
