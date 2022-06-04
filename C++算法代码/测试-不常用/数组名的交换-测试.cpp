#include<iostream>
using  namespace std;

int main() {
	int dp1[5];
	int dp2[3];
	for(int i=0; i<5; i++) {
		cin>>dp1[i];
	}
	for(int i=0; i<3; i++) {
		cin>>dp2[i];
	}
	/**********交换数组名*********/
	int *a=dp1;
	int *b=dp2;
	dp1=b;
	dp2=a;
	/*********************/
	for(int i=0; i<5; i++) {
		cout<<dp1[i]<<" ";
	}
	cout<<endl;
	for(int i=0; i<3; i++) {
		cout<<dp1[i]<<" ";
	}
	cout<<endl;
	return 0;
}
