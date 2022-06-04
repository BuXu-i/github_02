#include<iostream>
using namespace std;

int main(){
	int n;
	freopen("1.txt","r",stdin); 
	cin>>n;
	int ki=n%5;
	if(ki>3||ki==0){
		cout<<"Drying in day "<<n;
	}
	else cout<<"Fishing in day "<<n;
	return 0;
}
