#include<iostream>
using namespace std;
#include<vector>
#include<utility>
#include<queue>
struct cmp {
	bool operator()(const pair<int, int>T1,const pair<int, int>T2) {
		return T1.first>T2.first?1:0;
	}
};
int att[100];
int miniSpanningTree(int n, int m, vector<vector<int> >& cost,int suu) {
	// write code here
	priority_queue<pair<int, int>,vector<pair<int,int> >,cmp>que;
	vector<vector<int> >vear(n,vector<int>(n));//默认值是0
	vector<bool>arr(n,false);//0是未选择  1是
	for(int i=0; i<cost.size(); i++) {
		if(vear[cost[i][0]-1][cost[i][1]-1]==0)
			vear[cost[i][0]-1][cost[i][1]-1]=vear[cost[i][1]-1][cost[i][0]-1]=cost[i][2];
		else {
			vear[cost[i][0]-1][cost[i][1]-1]=vear[cost[i][1]-1][cost[i][0]-1]=min(cost[i][2],vear[cost[i][1]-1][cost[i][0]-1]);
		}
	}
	int s=0,ki=1;//suu第一行遍历//ki计数  村庄总数
	arr[suu]=true;//从第一个点开始
	while(true) {
		for(int i=0; i<vear[suu].size(); i++)
			if(!arr[i]&&vear[suu][i]!=0) {
				pair<int,int>pp;
				pp.first=vear[suu][i];
				pp.second=i;
				que.push(pp); //前面是距离 后面是连接点
			}
		while(arr[que.top().second]) {
			que.pop();
		}
		s+=que.top().first;
		//cout<<ki<<" ="<<"权值="<<que.top().first<<" "<<s<<" ";
		//cout<<ki<<"次   "<<suu<<"-"<<que.top().second<<" 加上权值后="<<s<<" 权值"<<que.top().first<<" "<<endl;
		//att[ki+1]=que.top().second;//点 的输出  “查看
		if(++ki==n)return s;
		arr[que.top().second]=true;//已选择
		suu=que.top().second;//下次所有改行进队
		que.pop();//出队
	}
}
int main() {
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
	int s;
	s=miniSpanningTree(n,m,arr,0);
	cout<<"结果="<<s<<" ";
	cout<<endl;
}
