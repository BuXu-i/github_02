#include<iostream>
using namespace std;
#include<sstream>
#include<algorithm>
int main() {
	//ʹ��C++��stringstream��ͣ�string��reverse����
	string s="ab cd ef dg";
	stringstream ss;
	ss << s;
	string p,str;
	while(ss >> p) {
		reverse(p.begin(), p.end()); //string ���Ե���reverse����,string�ı�����һ��vecor<char>
		str = str + p + '=';
	}
    string ans(str.begin(), str.begin()+str.size()-1);//�������һ���ո�; 
	cout<<str<<endl;
	cout<<ans<<endl; 
}
