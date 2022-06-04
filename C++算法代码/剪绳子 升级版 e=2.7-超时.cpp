#include<iostream>
using namespace std;
//使用的是普通的乘法  时间超时 
long long fun(int k,long long number) {
	cout<<"k="<<k<<" "<<"number="<<number<<endl;
	long long s=number;
	while(--k>0) {
		number+=s;
			cout<<"number:"<<number<<endl;
		if(number>=998244353) {
				cout<<"减"<<"number:"<<number<<endl;
			number%=998244353;
		}
	}
	cout<<"number:"<<number<<endl;
	return number;
}
long long cutRope(long long number) {
	// write code here
	if(number==2) return 1;
	if(number==3) return 2;
	long long kazu=number%3;
	long long suu=number/3;
	if(kazu==1) kazu=4;
	else if(kazu==2) kazu=6;
	else kazu=3;
	suu--;
	number=1;
	cout<<"kazu="<<kazu<<" "<<"suu="<<suu<<endl;
	for(int i=1; i<=suu; i++) {
		number*=3;
		cout<<"number:"<<number<<endl;
		if(number>998244353) {
			//cout<<"实行求余"<<endl;
			if(i+1>suu) {
				cout<<"????"<<endl;
				return fun(kazu, number);
			}
			i++;
			cout<<"实行求余 变化前"<<number<<endl;
			number=fun(3,number);
			cout<<"实行求余 变化后"<<number<<endl;
		}
	}
	cout<<"????11"<<endl;
	return fun(kazu, number);
}
int main() {
	long long a=874520;
	cout<<cutRope(a)<<endl;;
}
