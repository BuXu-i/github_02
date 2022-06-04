#include<iostream>
using namespace std;

int main () {
	int fah,lis;
	freopen("1.txt","r",stdin);
	cin>>fah>>lis;
	if(lis>=fah)
		cout<<"fahr celsius";
	else cout<<"Invalid.";
	double dou;
	while(lis>=fah) {
		printf("\n");
		printf("%d",fah);
		dou=5*(fah-32)/9.0;

		printf("%6.1f",dou);
		fah+=2;
	}
	return 0;
}

