#include<iostream>
using namespace std;
#include<algorithm>
int main() {
	int n;
	freopen("1.txt","r",stdin);
	cin>>n;
	for(int i=2; i<n/i; i++) {
		if(n%i==0) {
			cout<<n<<" is not prime number.";
			return 0;
		}
	}
	cout<<n<<" is prime number.";
	return 0;
}
