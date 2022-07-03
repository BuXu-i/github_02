#include<iostream>
using namespace std;
//可能写的这个递归操作多谢  有递归未超时 
int s=0;
void narabu(string str,int k) {
	if(k>=str.size()||str[k]=='0') {
		return ;
	}
	int suu=0;
	while(k<str.size()) {
		if(suu)
			suu*=10;
		suu+=str[k++]-'0';
		if(suu>0&&suu<=26) {
		//	cout<<"suu值达到"<<suu<<endl;
			narabu(str,k);
		} else {
		//	cout<<"suu值达到//夭折"<<suu<<endl;
			return;
		}
	}
	s++;
	return ;
}
int main() {
	freopen("./数据读取.txt","r",stdin);
	string str;
	cin>>str;
	narabu(str,0);
	cout<<s<<endl;
	cout<<str<<" "<<str.size()<<endl;
	return 0;
}
