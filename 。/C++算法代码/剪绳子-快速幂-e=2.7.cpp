#include<iostream>
using namespace std;
//#include"������-λ����-�ݹ�д��-��ͨд��.cpp"
#include<math.h>
//�����ӵĿ�����

long long cutRope(long long number) {
	// write code here
	if(number==2) return 1;
	if(number==3) return 2;
	long long kazu=number%3;
	long long suu=number/3-1;
	if(kazu==1) kazu=4;
	else if(kazu==2) kazu=6;
	else kazu=3;
	long long s=1;
	long long a=3;
	while(suu) {
		if(suu&1) 
			s=s%998244353*(a%998244353)%998244353;
		suu>>=1;
		a=a%998244353*(a%998244353)%998244353;
	}
	return s%998244353*(kazu%998244353)%998244353;
}
int main() {
	long long a=874520;//874520
	cout<<cutRope(a)<<endl;
}
