#include<iostream>
using namespace std;
#include<sstream>
int main() {
	int n;
	freopen("1.txt","r",stdin);
	cin>>n;
	string str;
	str=to_string(n);
	cout<<str.size()<<" ";
	n=0;
	for(int i=0;i<str.size();i++){
		n+=str[i]-'0';
	}
	cout<<n;
	return 0;
}
