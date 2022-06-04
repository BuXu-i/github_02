#include<iostream>
using namespace std;
int s=0;
int fun(int m,int n){
	if(m==0){
		return n+1;
	}
	else if(m>0&&n==0){
		fun(m-1,1);
	}
	else if(m>0&&n>0){
		fun(m-1,fun(m,n-1));
	}
}
int main(){
	int n,m;
	//freopen("1.txt","r",stdin);
	cin>>m>>n;
	cout<<fun(m,n);
	return 0;
}
