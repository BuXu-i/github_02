#include<iostream>
using namespace std;

int main () {
	int fah,lis;
	cin>>fah>>lis;
	if(lis>=fah)
		cout<<"fahr celsius";
	else cout<<"Invalid.";
	double dou;
	while(lis>=fah) {
		printf("\n");
		printf("%d",fah);
		if(fah<10) {
			printf("    ");
		}
		else if(fah==100){
			printf("  ");
		}
		else{
			printf("   ");
		}
		dou=5*(fah-32)/9.0;
		if((int)(dou*100.0)%10>=5){
			dou+=0.05;
		}
		printf("%.1f",dou);
		fah+=2;
	}
	return 0;
}

