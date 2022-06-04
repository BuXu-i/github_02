#include<iostream>
using namespace std;
#include<algorithm>
int main(){
	int n;
	freopen("1.txt","r",stdin); 
	string str;
	string op;
	while(cin>>op){
		str+=op;
	}
	cout<<str;
	return 0;
}
