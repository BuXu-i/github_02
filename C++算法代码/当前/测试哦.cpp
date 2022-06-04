#include<iostream>
using namespace std;
#include<math.h>
#include<vector>
int main() {
	vector<int>arr(2,3);
	arr.push_back(4);
	arr.push_back(5);
	for(int i=0; i<arr.size(); i++) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	swap(arr[1],arr[2]);
	for(int i=0; i<arr.size(); i++) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
