#include<iostream>
using namespace std;
#include<vector>

void fun(vector<int>arr,int len){
	if(len==arr.size()-1){
		for(int i=0;i<arr.size();i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
		return ;
	}
	for(int i=len;i<arr.size();i++){
		swap(arr[i],arr[len]);
		fun(arr,len+1);
	}
}
int main (){
	vector<int>arr;
	int n;
	cin>>n;
	int x;
	for(int i=0;i<n;i++){
		cin>>x;
		arr.push_back(x);
	}
	fun(arr,0);
	return 0;
}
 
