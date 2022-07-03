#include<iostream>
using namespace std;
#include<vector>
int main() {
	//一维数组
	vector<int>arr(6);
	for(int i=0; i<arr.size(); i++) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	//二维数组创建
	vector<vector<int> >arrt(3,vector<int>(2));
	for(int i=0; i<arrt.size(); i++) {
		for(int j=0; j<arrt[0].size(); j++) {
			cout<<arrt[i][j]<<" ";
		}
		cout<<endl;
	}
		/*
	char arrt[4]= {'a','b','c','e'};
	//matrix[0].push_back(arrt,arrt+4);
	matrix[0].insert(matrix[0].begin(),arrt,arrt+4);
	char arr1[4] {'s','f','c','s'};
	arrt=arr1;
	matrix[1].insert(matrix[1].begin(),arrt,arrt+4);
	char arr2[4] {'a','d','e','e'};
	arrt=arr2;
	matrix[2].insert(matrix[2].begin(),arrt,arrt+4);
	char arr3[4] {'s','f','c,','s'};
	arrt=arr3;*/
	//matrix[3].insert(matrix[3].begin(),arrt,arrt+4);
	//vector<int >arint(1,2,3,4,5);
	//matrix.push_back(arrt);
	return 0;
}
