#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
#include<string>
int main() {
	int n;
	freopen("1.txt","r",stdin);
	cin>>n;
	vector<int>arr;
	while(n!=1) {
		for(int i=2; i<=n; i++) {
			if(n%i==0) {
				arr.push_back(i);
				n=n/i;
				break;
			}
		}
	}
	int x=-1;
	int ki=0;
	string str;
	for(int i=0; i<arr.size(); i++) {
	//	cout<<arr[i]<<" ";
		if(x==-1) {
			x=arr[i];
			ki=1;
		} else if(x==arr[i]) {
			ki++;
		} else {
			//cout<<"     xzhi="<<x<<" ";
			if(ki==1) {
				str+=to_string(x)+"*";
			} else {
				str+=to_string(x)+"^"+to_string(ki)+"*";
			}
			x=arr[i];
			ki=1;
		}
	}
	//cout<<"*****"<<x<<"  "<<ki<<endl;
	if(ki==1) {
		str+=to_string(x)+"*";
	} else if(ki>1) {
		str+=to_string(x)+"^"+to_string(ki)+"*";
	}
	str[str.size()-1]=NULL;
	cout<<str;
	return 0;
}
