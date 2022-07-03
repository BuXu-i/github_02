#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
bool npm(int a, int b) {
	if (!(a & 1) && (b & 1)) { //×óÅ¼ÓÒÆæ
		return true;
	}
	return false;
}
int main() {
	vector<int>arr = {2, 3, 1, 2, 4};
	sort(arr.begin(), arr.end(), npm);
	for (int i = 0; i < (int)arr.size(); i++) {
		cout << arr[i] << " ";
	}
}
