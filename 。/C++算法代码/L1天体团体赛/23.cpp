#include<iostream>
using namespace std;
#include<algorithm>

int main () {
	string str;
	cin>>str;
	int a=str.rfind('-');
	string op;
	op.append(str,a+1,str.length()-a);
	op+='-';
	op.append(str,0,a);
	cout<<op;
	return 0;
}
