#include<iostream>
using namespace std;
#include<algorithm>
int main() {
	int n;
	freopen("1.txt","r",stdin);
	double a,b;
	cin>>a>>b;
	cout<<a<<" + "<<b<<" = "<<a+b<<endl;
	cout<<a<<" - "<<b<<" = "<<a-b<<endl;
	cout<<a<<" * "<<b<<" = "<<a*b<<endl;
	double ki=a/b;
	cout<<a<<" / "<<b<<" = ";
	if(ki!=(int)ki) {
		printf("%.2f",ki);
	} else{
		printf("%.0f",ki);
	}
		
	return 0;
}
