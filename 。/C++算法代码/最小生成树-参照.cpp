#include<iostream>
using namespace std;
#include<vector>
#include<utility>
#include<algorithm>//max  min  swap sort
#include<queue>
static bool cmp(vector<int>& x, vector<int>& y) { //重载比较，按照边权递增
	return x[2] < y[2];
}

int find(vector<int>& parent, int x) { //向上找到最高的父亲
	if(parent[x] != x)
		parent[x] = find(parent, parent[x]);
	return parent[x];
}
int miniSpanningTree(int n, int m, vector<vector<int> >& cost) {
	int ki=0;
	vector<int> parent(n + 1);
	for(int i = 0; i <= n; i++) //初始父亲设置为自己
		parent[i] = i;
	sort(cost.begin(), cost.end(), cmp); //边权递增排序
	int res = 0;
	for(int i = 0; i < cost.size(); i++) { //遍历所有的边，将连通的放入同一个并查集
		int x = cost[i][0];
		int y = cost[i][1];
		int z = cost[i][2];
		int px = find(parent, x); //查找x的最上边父亲
		int py = find(parent, y); // 查找y的最上边父亲
		if(px != py) { //如果二者不在同一个集合
			res += z; //边加入
			cout<<++ki<<"="<<res<<" "; 
			parent[px] = py; //设置二者在同一个集合
		}
	}
	return res;
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
	int s=miniSpanningTree(n,m,arr);
	cout<<"结果="<<s<<endl;
}
