#include<iostream>
using namespace std;
#include <vector>
#include<algorithm>
int app=0;

void fun(vector<vector<int> >array,int head,int j,int ki,int &s) {
	array[0][j]=-1;
	if(head==array.size()-1) {
		s=min(s,ki);
		return;
	}
	for(int i=1; i<array[head].size(); i++) {
		if(array[0][i]==0x7fffffff&&array[head][i]!=0x7fffffff) {
			fun(array,i,head,ki+array[head][i],s);
		}
	}
}
int findShortestPath(int n, int m, vector<vector<int> >& graph) {
	// write code here
	vector<vector<int> >array(n+1,vector<int>(n+1,0x7fffffff));
	int s=0x7fffffff;
	for(int i=0; i<graph.size(); i++) {
		array[graph[i][0]][graph[i][1]]=min(graph[i][2],array[graph[i][0]][graph[i][1]]);
	 	//array[graph[i][1]][graph[i][0]]=array[graph[i][0]][graph[i][1]]; //注释掉 即为有向图 
	}
	fun(array,1,1,0,s);
	if(s==0x7fffffff) return -1;
	cout<<"结果="<<s<<endl;
	return s;
}
int main () {
	freopen("./数据读取.txt","r",stdin);
	int n,m;
	cin>>n>>m;
	int a,b,c;
	vector<vector<int> >arr;
	vector<int>pp;
	for(int i=0; i<m; i++) {
		cin>>a>>b>>c;
		pp.push_back(a);
		pp.push_back(b);
		pp.push_back(c);
		arr.push_back(pp);
		pp.clear();
	}
	cout<<"结果="<<findShortestPath(n,m,arr);
}
