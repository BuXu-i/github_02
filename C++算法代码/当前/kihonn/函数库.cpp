#include<iostream>
using namespace std;
#include<algorithm>//max sort min ����  reverse(�ף�β) ��ת����  sort:������ 
#include<math.h>//ƽ�������� sqrt(ƽ����)
#include <sstream>// string ת int ���� stringstream stream;    stream<<�ַ���;stream>>n; // 
#include<typeinfo>//�鿴��������  typeid(����).name() 
#include<utility>//pair ʹ�� first second-sekend; 
//#include <bits/stdc++.h> ����ͷ�ļ� 5trfgv bvjkui89o7
#include<list> 
int main() {
	//����*********
//	list<int>lis;
//	lis.push_back(1233);
//	list<int>::iterator i=lis.begin();
//	lis.insert(i,123);
//	cout<<"list:"<<lis.back()<<endl;
//	//����***************
//	cout<<sqrt(8)<<endl;
//	string str="123";
//	int n=1423;
	//str=to_string(n);//C++ת��Ϊ�ַ���**************
	cout<<"**************"<<endl;	stringstream ss2;
//	int d2;   //ʮ�����Ƶ�ת������   hex ���Է�������ط� 
//	string str2("1aF"); //1aFʮ����431
//	ss2  <<hex<<str2; //ѡ��ʮ���������
//	ss2 >>d2;
//	cout<<ss2.str()<<endl;
//	cout<<d2<<endl;
	//�ַ��� ���� ����***************************88
	//string ת ���� 
	stringstream stream;
	stream<<"0.0a9";
	cout<<"�����д��е�ֵ="<<stream.str()<<endl; 
	double n;
	stream>>n;
	cout<<"ȡ��ֵn="<<n<<endl;
	stream.str("");
	//stream.clear();  //�������ͨ��ʹ��ͬһstringstream����ʵ�ֶ������͵�ת������ע����ÿһ��ת��֮�󶼱������clear()��Ա����
	cout<<"clear ��պ������ֵ="<<stream.str()<<endl;
	stream<<"008a866a";
	cout<<"������ֵ��="<<stream.str()<<endl; 
	double ki;
	stream>>ki;
	cout<<"����ȡ��ֵ��="<<ki<<endl;
	cout<<"**************"<<endl;
	//�ַ��� ���� ����***************************
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
	//���� ����ĳ��� sizeof()**************************
	int arr[100];
	cout<<sizeof(arr)/sizeof(arr[0]);
	//
	cout<<"**************"<<endl;
//	string str0="123";
//	int stt=123;
//	str0=(string)123;
//	cout<<(string)stt<endl;
}
