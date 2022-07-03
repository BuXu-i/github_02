#include<iostream>
using namespace std;
#include<algorithm>
int main(){
	int n;
	freopen("1.txt","r",stdin); 
	cin>>n;
	int s=n*6;
	for(int i=n;i>=0;i--){
		for(int j=0;j<=n;j++){
			if(s==3*i+7*j&&i+j<=n){
				cout<<"cock="<<n-i-j<<",hen="<<i<<",chicken="<<j<<endl;
			}
		}
	}
	return 0;
}
