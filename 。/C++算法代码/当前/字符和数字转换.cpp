#include<iostream>
using namespace std;

int main(){
	string str;
	cin>>str;
	//cout<<"1 :"<<str<<endl;
	int n;
	//只能一个一个字符的转换
	cin>>n;
	//int 不能转换string 可以转换为 char 再拼接 
	n=to_int(str); 
	cout<<str; 
	return 0;
} 
