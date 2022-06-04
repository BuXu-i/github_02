#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
int main() {
	int n;
	freopen("1.txt","r",stdin);
	string str;
	int 	ki=0;
	vector<string>arr;
	while(cin>>str) {
		arr.push_back(str);
	}
	arr.back().erase(arr.back().size()-1,1);
	str="";
	for(int i=0; i<arr.size(); i++) {
		if(arr[i].find('a')!=-1&&arr[i].size()>ki) {
			str=arr[i];
			ki=arr[i].size();
		}
	}
	if(str.size()==0)cout<<"NO";
	else cout<<str;
	return 0;
}
