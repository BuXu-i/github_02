#include<iostream>
using namespace std;
#include<vector>
void fun(vector<bool>&arr,int a) { //存储
    if(!arr[a]) 
        arr[a]=1;
    return;
}
bool fun2(vector<bool>&arr,int a) { //查
    if(arr[a]) 
        return true;
    return false;
}
    int minNumberDisappeared(vector<int>& nums) {
        // write code here
        vector<bool>arr(nums.size());
        int a=1;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]<=nums.size()&&nums[i]>0) {
                if(a!=nums[i]) 
                    fun(arr, nums[i]);
                else {
                    a++;
                    while(fun2(arr, a)) { //a<arr.size()&&
                        a++;
                    }
                }
            }
        }
    return a;
}
int main () {
	vector<int >arr;
	int x;
	freopen("./数据读取.txt","r",stdin);
	for(int i=0; i<5; i++) {
		cin>>x;
		arr.push_back(x);
	}
	cout<<minNumberDisappeared(arr)<<endl;
	return 0;
}
