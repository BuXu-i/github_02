#include<iostream>
using namespace std;
#include<algorithm>
#include <vector>
int rob(vector<int>& nums) {
	// write code here
	int A=0,B=0,i=1;
	int suu=0,kazu=0,siz=nums.size();//ǰ���һ����//�޷���ѡһ�Ͳ�ѡһ�Ĳ���
	while(true) {
		for(; i<siz; i++) {
			kazu=max(kazu+nums[i],suu);
			if(++i<siz) {
				suu=max(suu+nums[i], kazu);
			}
		}
		i=2;
		cout<<"��һ�飬Ӧ��������:"<<endl; 
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
	freopen("./���ݶ�ȡ.txt","r",stdin);
	int x;
	while(cin>>x) {
		arr.push_back(x);
	}
	cout<<" "<<arr.size()<<"     ="<<rob(arr)<<endl;
}
