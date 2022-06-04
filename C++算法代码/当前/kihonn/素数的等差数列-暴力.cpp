#include <iostream>
using namespace std;

bool  fun(long long a) {
	if(a==2)return 1;
	for(int i=2; i<a; i++) {
		if(a%i==0) {
			return 0;
		}
	}
	return 1;
}
int main() {
	int k=12;
	// 请在此输入您的代码
	long long  s,ki;
	for(int i=2; i<10000; i++) {
		if(fun(i)==1) {
			for(int j=1; j<10000; j++) {
				s=k;
				ki=i+j;
				while(--s) {
					if(fun(ki)==1) {
						ki+=j;
					} else {
						s=9;
						break;
					}
				}
				if(s==0) {
					while(s!=k){
						ki-=j;
						s++;
						cout<<ki<<" ";
					} 
					return 0;
				}
			}
		}
	}
	cout<<"a"<<endl;
	return 0;
}
