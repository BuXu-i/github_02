#include<iostream>
using namespace std;
#include<vector>
vector<int> reOrderArrayTwo(vector<int>& array) {
	// write code here
	// write code here
	int suu=0;
	int kazu=array.size()-1;
	while(suu<kazu) {
		while(suu<kazu&&array[suu]&1) { //Ϊż������
			suu++;
		}
		while(suu<kazu&&!(array[kazu]&1)) {
			kazu--;
		}
		swap(array[suu++],array[kazu--]);
	}
	return array;
}
int main () {
	vector<int>arr;
	cout<<"??"<<endl;
	for(int i=0; i<4; i++) {
		arr.push_back(i+1);
	}
	cout<<"����1="<<arr.size()<<endl;
	for(int i=0; i<arr.size(); i++) {
		cout<<arr[i]<<" ";
	}
	arr=reOrderArrayTwo(arr);
	cout<<"����2="<<arr.size()<<endl;
	for(int i=0; i<arr.size(); i++) {
		cout<<arr[i]<<" ";
	}
	cout<<"����3="<<arr.size()<<endl;
	cout<<"??"<<endl;
	cout<<endl;
	return 0;
}
