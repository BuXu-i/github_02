#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
int main() {
	int n;
	//freopen("1.txt","r",stdin);
	string str;
	vector<string>arr;
	while(cin>>str) {
		arr.push_back(str); 
	}
	for(int i=arr.size()-1;i>=0;i--){
		cout<<arr[i];
		if(i!=0){
			cout<<" ";
		}
	}
	return 0;
}
