#include<iostream>
using namespace std;
#include<algorithm> 
int s=0;
int  fun(int n){
	if(n==1||n==0){
		return 1;
	}
	return fun(n-1)+fun(n-2);
	
}
int main(){
	//freopen("1.txt","r",stdin);
	cout<<fun(3);
	return 0;
} 
