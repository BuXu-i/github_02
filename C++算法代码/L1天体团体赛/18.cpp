#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
int s=1,sw=0;
void fun(vector<int>arr,int ki) {
	if(ki==arr.size()-1) {
		for(const auto &i:arr) {
			cout<<i;
		}
		sw++;
		if(sw!=s)
			cout<<endl;
			//cout<<"A"<<s<<" "<<sw;
		return ;
	}
	for(int i=ki; i<arr.size(); i++) {
		swap(arr[i],arr[ki]);
		fun(arr,ki+1);
	}
}
int main() {
	int n;
	//freopen("1.txt","r",stdin);
	vector<int>arr;
	cin>>n;
	for(int i=1; i<=n; i++) {
		arr.push_back(i);
		s=i*s;
	}
	fun(arr,0);
	return 0;
}
