#include<iostream>
using namespace std;
#include<algorithm>
#include <vector>
int rob(vector<int>& nums) {
	// write code here
	int suu=nums[0];
	int kazu=nums[1];
	kazu=max(suu,kazu);//������ж�û�� ���Ի���� 
	int k=1;
	for(int i=2; i<nums.size();) {
		cout<<k++<<"�Σ� "<<"suu="<<suu<<" "<<"ǰkazu="<<kazu<<endl;
		suu=max(suu+nums[i++], kazu);
		if(i<nums.size()) {
			cout<<k++<<"�Σ� "<<"suu="<<suu<<" "<<"kazu="<<kazu<<endl;
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
		cout<<k++<<"�Σ� "<<"pre="<<pre<<" "<<"ǰcur="<<cur<<endl;
		int tmp = max(cur,pre+nums[i]);
		pre = cur;
		cur = tmp;
	}
	return cur;
}
int main () {
	vector<int>arr;
	freopen("./���ݶ�ȡ.txt","r",stdin);
	int x;
	int ki=450;
	while(cin>>x) {
		arr.push_back(x);
		if(x==ki) {
			cout<<arr.size()-1<<" ";
		}
	}
	cout<<endl<<arr.size()<<endl;;
	cout<<"�����= "<<rob(arr)<<endl;
	cout<<"��ȷ��= "<<rob1(arr)<<endl;
//	cout<<"= "<<rob1(arr)-rob(arr)<<endl;
}
