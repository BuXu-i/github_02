#include<iostream>
using namespace std;
#include<math.h>
long long fun(int a,int n) {
	long long  bumder=1;
	while(n) {
		if(n&1) {//���һ����ǰ 
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
		return fun2(a,n-1)*a;//�洢����Ҫ���˵Ĵ��� 
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
			ki*=a;//�洢����Ҫ���˵Ĵ��� 
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
	cout<<"λ����д��     :"<<fun(a,n)<<endl;
	cout<<"�ݹ����д��   :"<<fun2(a,n)<<endl;
	cout<<"��ͨwhileд��  :"<<fun3(a,n)<<endl;
	cout<<"��װ����pow����:"<<(long long)pow(a,n)<<endl;
	return 0;
}
