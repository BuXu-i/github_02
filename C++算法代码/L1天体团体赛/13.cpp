#include<iostream>
using namespace std;
#include<algorithm>

#include<math.h>
int main() {
	int n;
	freopen("1.txt","r",stdin);
	int x,y;
	cin>>n;
	int ki=sqrt(n)+1;
	//cout<<ki<<endl;
	int suu=ki;
	bool pp=false;
	for(int i=1; i<ki; i++) {
		//cout<<i<<"об "<<sqrt(n-i*i)<<" "<<(int)sqrt(n-i*i)<<endl;
		if(sqrt(n-i*i)==(int)sqrt(n-i*i)) {
			if(pp)
				cout<<endl;
			ki=sqrt(n-i*i);
			cout<<i<<" "<<ki;
			pp=true;

		}
	}
	if(!pp) cout<<"No Solution";
	return 0;
}
