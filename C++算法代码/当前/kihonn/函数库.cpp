#include<iostream>
using namespace std;
#include<algorithm>//max sort min 函数  reverse(首，尾) 反转函数  sort:排序函数 
#include<math.h>//平方根函数 sqrt(平方数)
#include <sstream>// string 转 int 类型 stringstream stream;    stream<<字符串;stream>>n; // 
#include<typeinfo>//查看变量类型  typeid(数据).name() 
#include<utility>//pair 使用 first second-sekend; 
//#include <bits/stdc++.h> 万能头文件 5trfgv bvjkui89o7
#include<list> 
int main() {
	//链表*********
//	list<int>lis;
//	lis.push_back(1233);
//	list<int>::iterator i=lis.begin();
//	lis.insert(i,123);
//	cout<<"list:"<<lis.back()<<endl;
//	//根号***************
//	cout<<sqrt(8)<<endl;
//	string str="123";
//	int n=1423;
	//str=to_string(n);//C++转化为字符串**************
	cout<<"**************"<<endl;	stringstream ss2;
//	int d2;   //十六进制的转换问题   hex 可以放在任意地方 
//	string str2("1aF"); //1aF十进制431
//	ss2  <<hex<<str2; //选用十六进制输出
//	ss2 >>d2;
//	cout<<ss2.str()<<endl;
//	cout<<d2<<endl;
	//字符串 互相 整形***************************88
	//string 转 整形 
	stringstream stream;
	stream<<"0.0a9";
	cout<<"对象中存有的值="<<stream.str()<<endl; 
	double n;
	stream>>n;
	cout<<"取出值n="<<n<<endl;
	stream.str("");
	//stream.clear();  //如果你想通过使用同一stringstream对象实现多种类型的转换，请注意在每一次转换之后都必须调用clear()成员函数
	cout<<"clear 清空后里存有值="<<stream.str()<<endl;
	stream<<"008a866a";
	cout<<"存入新值后="<<stream.str()<<endl; 
	double ki;
	stream>>ki;
	cout<<"重新取出值后="<<ki<<endl;
	cout<<"**************"<<endl;
	//字符串 互相 整形***************************
	cout<<"************************"<<endl;
	stringstream strp;
	strp<<"string";
	strp<<" wewewe";
	string stpp,stpp2;
	cout<<"1 "<<strp.str()<<endl;
	strp>>stpp;
	cout<<"2 "<<strp.str()<<endl;
	strp>>stpp2;
	cout<<"3 "<<strp.str()<<endl;
	cout<<"1:"<<stpp<<" 2:"<<stpp2<<endl; 
	//计算 数组的长度 sizeof()**************************
	int arr[100];
	cout<<sizeof(arr)/sizeof(arr[0]);
	//
	cout<<"**************"<<endl;
//	string str0="123";
//	int stt=123;
//	str0=(string)123;
//	cout<<(string)stt<endl;
}
