#include<iostream>
using namespace std;
#include<vector>
#include<utility>
int s=0,ski=0;
void dfs(vector<int>&abc,vector<bool>&arr,vector<vector<int> >&ver) {
	while(abc.size()!=0) {
		arr[abc.back()]=false;
		int ki=abc.back();
		abc.pop_back();
		for(int i=0; i<ver[ki].size(); i++) {
			if(arr[ver[ki][i]]==true) {
				abc.push_back(ver[ki][i]);
			}
		}
	}
	for(int i=0; i<arr.size(); i++) {
		if(arr[i]==true) {
			return ;
		}
	}
	cout<<endl<<"liang";
	s++;
}
void funa(vector<vector<int> >&ver,vector<bool>arr) {
	vector<int>abc;
	for(int i=0; i<arr.size(); i++) {
		if(arr[i]==true) {//首先得找到一个亮的。
			arr[i]=false;
			for(int j=0; j<ver[i].size(); j++) {
				if(arr[ver[i][j]]==true)
					abc.push_back(ver[i][j]);
			}
			dfs(abc,arr,ver);//arr 要变
			return;
		}
	}
}
void fun(vector<vector<int> >ver,vector<bool>arr) {
	int a=2,b=2,c=2,d=2,e=2,f=2,g=2;
	for(a=2; a>0; a--) {
		arr['a'-'a']=(a==2?true:false);
		for(b=2; b>0; b--) {
			arr['b'-'a']=(b==2?true:false);
			for(c=2; c>0; c--) {
				arr['c'-'a']=(c==2?true:false);
				for(d=2; d>0; d--) {
					arr['d'-'a']=(d==2?true:false);
					for(e=2; e>0; e--) {
						arr['e'-'a']=(e==2?true:false);
						for(f=2; f>0; f--) {
							arr['f'-'a']=(f==2?true:false);
							for(g=2; g>0; g--) {
								arr['g'-'a']=(g==2?true:false);
								cout<<"第= "<<++ski<<" ::";
								for(int i=0; i<arr.size(); i++) {
									cout<<arr[i]<<" ";
								}
								cout<<endl;
								funa(ver,arr);
							}
						}
					}
				}
			}
		}
	}

}
int main() {
	vector<vector<int> >ver(7);
	ver[0].push_back(1);
	ver[0].push_back(5);
	ver[1].push_back(0);
	ver[1].push_back(6);
	ver[1].push_back(2);
	ver[2].push_back(1);
	ver[2].push_back(6);
	ver[2].push_back(3);
	ver[3].push_back(2);
	ver[3].push_back(4);
	ver[4].push_back(3);
	ver[4].push_back(6);
	ver[4].push_back(5);
	ver[5].push_back(4);
	ver[5].push_back(6);
	ver[5].push_back(0);
	ver[6].push_back(5);
	ver[6].push_back(4);
	ver[6].push_back(1);
	ver[6].push_back(2);
	vector<bool>arr(7);
	fun(ver,arr);
	cout<<endl<<s;
	return 0;
}
