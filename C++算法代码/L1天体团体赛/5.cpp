#include<iostream>
using namespace std;
int s=0;


void fun2(int x,int a,int b) {
	s++;
	if(a!=0&&b!=0&&x!=0)
		cout<<"fen5:"<<a<<", fen2:"<<b<<", fen1:"<<x<<", total:"<<a+b+x<<endl;
}

void fun1(int x,int a,int b) {
	int n=x/2;
	while(n--) {
		fun2(x-n*2-2,a,n+1);
	}
}
void fun(int x,int a,int b) {
	int n=x/5;
	while(n--) {
		fun1(x-n*5-5,n+1,b);
	}
}
int main() {
	int n;
	//freopen("1.txt","r",stdin);
	cin>>n;
	fun(n,0,0);
	cout<<"count = "<<s;
	return 0;
}
