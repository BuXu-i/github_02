#include<iostream>
using namespace std;
#include<algorithm> 
int main(){
	freopen("1.txt","r",stdin);
	int n;
	cin>>n;
	int a=0,b=10000000,as=0,bs=0;
	int x;
	while(n--){
		cin>>x;
		if(x>a){
			a=x;
			as=1;
		}
		if(x==a){
			as++;
		} 
		if(x<b){
			b=x;
			bs=1;
		}
		if(x==b){
			bs++;
		}
	}
	cout<<b<<" "<<bs-1<<endl<<a<<" "<<as-1;
	return 0;
} 
