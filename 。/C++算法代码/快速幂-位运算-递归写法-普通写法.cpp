#include<iostream>
using namespace std;
#include<math.h>
long long fun(int a,int n) {
	long long  bumder=1;
	while(n) {
		if(n&1) {//真就一往无前 
			bumder=bumder*a;
		}
		n>>=1;
		a*=a;
	}
	return bumder;
}
long long fun2(long long a,int n) {
	if(n==0) {
		return 1;
	} else if(n%2==1) {
		return fun2(a,n-1)*a;//存储了需要单乘的次数 
	} else {
		a=fun(a,n/2);
		a*=a;
	}
	return a;
}
long long fun3(int a,int n) {
	int sun=a;
	int ki=1;
	long long s=1;
	while(n>1) {
		if(n%2==1) {
			n--;
			ki*=a;//存储了需要单乘的次数 
		}
		n=n/2;
		a*=a;
	}
	s*=a;
	if(ki!=1)
		s*=ki;
	return s;
}
int man() {
	int a=4;
	int n=15;
	cout<<"位运算写法     :"<<fun(a,n)<<endl;
	cout<<"递归调用写法   :"<<fun2(a,n)<<endl;
	cout<<"普通while写法  :"<<fun3(a,n)<<endl;
	cout<<"封装函数pow调用:"<<(long long)pow(a,n)<<endl;
	return 0;
}
