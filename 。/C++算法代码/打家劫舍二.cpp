#include<iostream>
using namespace std;
#include<algorithm>
#include <vector>
int rob(vector<int>& nums) {
	// write code here
	int A=0,B=0,i=1;
	int suu=0,kazu=0,siz=nums.size();//前面的一个数//无非是选一和不选一的操作
	while(true) {
		for(; i<siz; i++) {
			kazu=max(kazu+nums[i],suu);
			if(++i<siz) {
				suu=max(suu+nums[i], kazu);
			}
		}
		i=2;
		cout<<"第一遍，应该是两遍:"<<endl; 
		A=max(kazu, suu);
		if(siz!=nums.size()) {
			A+=nums[0];
			B=max(A,B);
			return B;
		}
		siz=siz-1;
		B=max(A,B);
		kazu=suu=0;
	}
}
int main () {
	vector<int>arr;
	freopen("./数据读取.txt","r",stdin);
	int x;
	while(cin>>x) {
		arr.push_back(x);
	}
	cout<<" "<<arr.size()<<"     ="<<rob(arr)<<endl;
}
