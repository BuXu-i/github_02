#include<iostream>
using namespace std;
#include<algorithm>
#include <vector>
int rob(vector<int>& nums) {
	// write code here
	int suu=nums[0];
	int kazu=nums[1];
	kazu=max(suu,kazu);//最初的判断没有 所以会出错 
	int k=1;
	for(int i=2; i<nums.size();) {
		cout<<k++<<"次： "<<"suu="<<suu<<" "<<"前kazu="<<kazu<<endl;
		suu=max(suu+nums[i++], kazu);
		if(i<nums.size()) {
			cout<<k++<<"次： "<<"suu="<<suu<<" "<<"kazu="<<kazu<<endl;
			kazu=max(kazu+nums[i++],suu );
		}
	}
	return max(suu, kazu);
}
int rob1(vector<int>& nums) {
	// write code here
	int k=1; 
	int pre = 0, cur = nums[0];
	for(int i = 1 ; i < nums.size(); i ++) {
		cout<<k++<<"次： "<<"pre="<<pre<<" "<<"前cur="<<cur<<endl;
		int tmp = max(cur,pre+nums[i]);
		pre = cur;
		cur = tmp;
	}
	return cur;
}
int main () {
	vector<int>arr;
	freopen("./数据读取.txt","r",stdin);
	int x;
	int ki=450;
	while(cin>>x) {
		arr.push_back(x);
		if(x==ki) {
			cout<<arr.size()-1<<" ";
		}
	}
	cout<<endl<<arr.size()<<endl;;
	cout<<"错误的= "<<rob(arr)<<endl;
	cout<<"正确的= "<<rob1(arr)<<endl;
//	cout<<"= "<<rob1(arr)-rob(arr)<<endl;
}
