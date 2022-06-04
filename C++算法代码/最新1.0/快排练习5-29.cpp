#include<iostream>
using namespace std;
#include<vector>
void ap(vector<int>arr){
	for(int i=0;i<(int)arr.size();i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
void fun(vector<int>&arr,int L,int R){
	if(L>=R)return ;
	int l=L,r=R;
	int x=arr[l];
	while(l<r){
		while(l<r){
			if(x>arr[r]){
				arr[l]=arr[r];
				l++;
				break;
			}
			r--;
		}
		while(l<r){
			if(x<arr[l]){
				arr[r]=arr[l];
				r--;
				break;
			}
			l++;
		}
	ap(arr);
	}
	arr[l]=x;
	fun(arr,L,l-1);
	fun(arr,l+1,R);
}

int main() {
	vector<int>arr;
	int x, n;
	freopen("1.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		arr.push_back(x);
	}
	ap(arr);
	fun(arr,0,n-1);
	ap(arr);
	cout<<"end";
	return 0;
}
