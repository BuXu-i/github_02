#include<iostream>
using namespace std;
//����д������ݹ������л  �еݹ�δ��ʱ 
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
		//	cout<<"suuֵ�ﵽ"<<suu<<endl;
			narabu(str,k);
		} else {
		//	cout<<"suuֵ�ﵽ//ز��"<<suu<<endl;
			return;
		}
	}
	s++;
	return ;
}
int main() {
	freopen("./���ݶ�ȡ.txt","r",stdin);
	string str;
	cin>>str;
	narabu(str,0);
	cout<<s<<endl;
	cout<<str<<" "<<str.size()<<endl;
	return 0;
}
