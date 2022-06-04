#include<iostream>
using namespace std;


int main(){
	int n;
	freopen("1.txt","r",stdin); 
	int m;
	cin>>n>>m;
	int ki=0;
	int s=0;
	int i=0;
	while(n!=m+1){
		if(n==-100)ki=4;
		else if(n<-9)ki=3;
		else if(n<0)ki=2;
		else if(n<10)ki=1;
		else if(n<100)ki=2;
		else if(n==100)ki=3;
		for(int j=ki;j<5;j++){
			cout<<" ";
		}
		cout<<n;
		i++;
		if(i==5&&n!=m){
			cout<<endl;
			i=0;
		}
		s+=n;
		n++;
	}
	cout<<endl<<"Sum = "<<s;
	return 0;
}
