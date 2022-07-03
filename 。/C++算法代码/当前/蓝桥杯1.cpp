#include<iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	if(n==0) {
		cout<<0<<"%"<<endl<<0<<"%";
		return 0;
	}
	int arr;
	int jige=0,youxiu=0;
	for(int i=0;i<n; i++) {
		cin>>arr;
		if(arr>=60) {
			jige++;
			if(arr>=85) {
				youxiu++;
			}
		}
	}
	cout<<jige<<" "<<youxiu<<" "<<n<<endl;
	//42 99 100 95 70 63 98 98 46 92 97 85 92 67 93 49 98 82 83 44 62 100 74 69 93 77 65 94 92 54 38 44 95 76 63 28 76 77 82 40 98 59 44
	jige=jige*1000/n;
	youxiu=youxiu*1000/n;
	cout<<jige<<" "<<youxiu<<endl;
	if(jige%10>=5) jige+=5;
	if(youxiu%10>=5)youxiu+=5;
	cout<<jige/10<<"%"<<endl<<youxiu/10<<"%";
	return 0;
}
