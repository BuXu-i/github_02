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
	vector<vector<int> >vear(n,vector<int>(n));//Ĭ��ֵ��0
	vector<bool>arr(n,false);//0��δѡ��  1��
	for(int i=0; i<cost.size(); i++) {
		if(vear[cost[i][0]-1][cost[i][1]-1]==0)
			vear[cost[i][0]-1][cost[i][1]-1]=vear[cost[i][1]-1][cost[i][0]-1]=cost[i][2];
		else {
			vear[cost[i][0]-1][cost[i][1]-1]=vear[cost[i][1]-1][cost[i][0]-1]=min(cost[i][2],vear[cost[i][1]-1][cost[i][0]-1]);
		}
	}
	int s=0,ki=1;//suu��һ�б���//ki����  ��ׯ����
	arr[suu]=true;//�ӵ�һ���㿪ʼ
	while(true) {
		for(int i=0; i<vear[suu].size(); i++)
			if(!arr[i]&&vear[suu][i]!=0) {
				pair<int,int>pp;
				pp.first=vear[suu][i];
				pp.second=i;
				que.push(pp); //ǰ���Ǿ��� ���������ӵ�
			}
		while(arr[que.top().second]) {
			que.pop();
		}
		s+=que.top().first;
		//cout<<ki<<" ="<<"Ȩֵ="<<que.top().first<<" "<<s<<" ";
		//cout<<ki<<"��   "<<suu<<"-"<<que.top().second<<" ����Ȩֵ��="<<s<<" Ȩֵ"<<que.top().first<<" "<<endl;
		//att[ki+1]=que.top().second;//�� �����  ���鿴
		if(++ki==n)return s;
		arr[que.top().second]=true;//��ѡ��
		suu=que.top().second;//�´����и��н���
		que.pop();//����
	}
}
int main() {
	freopen("./���ݶ�ȡ.txt","r",stdin);
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
	cout<<"���="<<s<<" ";
	cout<<endl;
}
