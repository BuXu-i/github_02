#include<iostream>
using namespace std;

int main(){
	string str;
	cin>>str;
	//cout<<"1 :"<<str<<endl;
	int n;
	//ֻ��һ��һ���ַ���ת��
	cin>>n;
	//int ����ת��string ����ת��Ϊ char ��ƴ�� 
	n=to_int(str); 
	cout<<str; 
	return 0;
} 
