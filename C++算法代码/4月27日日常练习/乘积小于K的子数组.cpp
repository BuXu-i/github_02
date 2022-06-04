#include<iostream>
using namespace std;
#include<vector>
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if(k<2)return 0;
	int s = 0;
	int num = 1;
	int a = 0;
	for (int i = 0; i < (int)nums.size(); i++) {
		while (nums[i]*num >= k) {
            if(a==i){
                a++;
                break;
            }
			num = num / nums[a];
			a++;
		}
        if(a<=i){
            num = num * nums[i];
		    s += i-a+1;
        }
	}
	return s;
}

int main () {
	freopen("1.txt", "r", stdin);
	int n;
	vector<int>nums(n);
	cin >> n;
	int k;
	cin >> k;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
//	cout << k << " " << n << " " << nums[2];
	cout << n << " " << nums.size()<<endl;;
	cout <<	numSubarrayProductLessThanK(nums, k);
}
