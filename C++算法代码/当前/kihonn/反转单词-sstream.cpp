#include<iostream>
using namespace std;
#include<sstream>
#include<algorithm>
int main() {
	//使用C++的stringstream类和，string的reverse函数
	string s="ab cd ef dg";
	stringstream ss;
	ss << s;
	string p,str;
	while(ss >> p) {
		reverse(p.begin(), p.end()); //string 可以调用reverse函数,string的表现像一个vecor<char>
		str = str + p + '=';
	}
    string ans(str.begin(), str.begin()+str.size()-1);//消除最后一个空格; 
	cout<<str<<endl;
	cout<<ans<<endl; 
}
