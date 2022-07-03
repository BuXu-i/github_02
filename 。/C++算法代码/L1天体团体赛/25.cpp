#include<iostream>
using namespace std;
#include<vector>
struct op {
	string a;
	int b;
	int c;
};
int main() {
	freopen("1.txt","r",stdin);
	int n;
	int a;
	op *kp1;
	vector<op*>arr;
	cin>>n;
	while(n--) {
		kp1=new op();
		cin>>kp1->a>>kp1->b>>kp1->c;
		arr.push_back(kp1);
	}
	//cout<<arr.size()<<endl;
	cin>>n;
	while(n--) {
		cin>>a;
		for(const  auto&i:arr) {
			if(i->b==a) {
				cout<<i->a<<" "<<i->c;
				break;
			}
		}
		if(n!=0)cout<<endl;
	}
	return 0;
}
