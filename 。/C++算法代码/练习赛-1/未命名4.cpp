#include<iostream>
using namespace std;
#include<algorithm> 
int main(){
	//freopen("1.txt","r",stdin);
	int n,keey;
	cin>>keey>>n;
	n=n%7;
	keey=keey%7;
	keey+=n;
	if(keey>0){
		cout<<keey;
	}
	else{
		cout<<7+keey;
	}
	return 0;
} 
