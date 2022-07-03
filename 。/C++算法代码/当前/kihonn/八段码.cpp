#include<iostream>
using namespace std;
#include<utility>
#include<algorithm>
#include<vector>
bool num(int a,int b) {
	return a>b?1:0;
}
struct cmp {
	bool operator()(const pair<int, int>T1,const pair<int, int>T2) {
		return T1.first>T2.first?1:0;
	}
};
int main () {
	int arr[5]= {1,2,3,4,5};
	reverse(arr,arr+4);
	string str="123456";
	for(int i=0; i<5; i++)
		cout<<arr[i]<<" ";
	reverse(str.begin(), str.begin()+2);
	cout<<"str="<<str<<endl;
	vector<int>ver;
	for(int i=0; i<5; i++) {
		ver.push_back(i);
	}
	reverse(ver.begin(),ver.begin()+2);
	sort(ver.begin(),ver.begin()+2,num);
	cout<<"ver-sort= ";
	for(int i=0; i<ver.size(); i++) {
		cout<<ver[i]<<" ";
	}

	//pair<int,int>pp;
	cout<<endl;
	pair<int,string>pp;
	pp.first=123;
	pp.second="nvpenyou";
	cout<<pp.first<<endl;
	cout<<pp.second;
	return 0;
}

