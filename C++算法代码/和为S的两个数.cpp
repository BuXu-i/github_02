#include<iostream>
using namespace std;
#include<vector>
vector<int> FindNumbersWithSum(vector<int> array,int sum) {
	vector<int>arr;
	int mae=0;
	int suu=array.size()-1;
	int s;
	while(mae<suu) {
		s=array[mae]+array[suu];
		if(s>sum) {
			suu--;
		} else if(s<sum) {
			mae++;
		} else {
			arr.push_back(array[mae]);
			arr.push_back(array[suu]);
			return arr;
		}
	}
	cout<<"长度"<<arr.size()<<endl;
	return arr;
}
int main() {
	vector<int>arr;
	int x;
	freopen("./数据读取.txt","r",stdin);
	for(int i=0; i<6; i++) {
		cin>>x;
		arr.push_back(x);
	}
	for(int i=0; i<arr.size(); i++) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	arr=FindNumbersWithSum(arr,15);
	cout<<"长度"<<arr.size()<<endl;
	for(int i=0; i<arr.size(); i++) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
