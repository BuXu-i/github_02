#include<iostream>
using namespace std;
#include<algorithm>
int main(){
	int n=0,a=1;
	cout<<n<<"   ";
	freopen("1.txt","r",stdin); 
	while(n<=100){
		cout<<n<<"   ";
		n=a+n;
		swap(a,n);
	}
	return 0;
}
