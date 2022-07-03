
#include<iostream>
using namespace std;
#include<algorithm>
int main() {
	int n;
	freopen("1.txt","r",stdin);
	string str;
	cin>>str;
	if(str[0]>='0'&&str[0]<='9'||str[0]=='_') {
		cout<<0;
	} else {
		cout<<1;
	}
	while (cin>>str) {
		cout<<endl;
		if(str[0]>='0'&&str[0]<='9'||str[0]=='_') {
			cout<<0;
		} else {
			cout<<1;
		}
	}
	return 0;
}
