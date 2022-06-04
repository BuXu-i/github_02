#include<iostream>
using namespace std;
#include<algorithm>
#include<sstream>
int main() {
	int n;
	freopen("1.txt","r",stdin);
	string str;
	int a,b,c;
	scanf("%d/%d/%d",&a,&b,&c);
	//cout<<a<<" "<<b<<" "<<c<<endl;
	int yue[13]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
	if((a%100!=0&&a%4==0)||a%400==0){
		yue[2]=29;
	}
	c++;
	if(yue[b]>=c){
			cout<<a<<"/"<<b<<"/"<<c;
	}
	else{
		c=1;
		b++;
		if(b<=12){
			cout<<a<<"/"<<b<<"/"<<c;
		}
		else {
			b=1;
			cout<<a+1<<"/"<<b<<"/"<<c;
		}
	}

}
