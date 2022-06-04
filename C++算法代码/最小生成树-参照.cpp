#include<iostream>
using namespace std;
#include<vector>
#include<utility>
#include<algorithm>//max  min  swap sort
#include<queue>
static bool cmp(vector<int>& x, vector<int>& y) { //���رȽϣ����ձ�Ȩ����
	return x[2] < y[2];
}

int find(vector<int>& parent, int x) { //�����ҵ���ߵĸ���
	if(parent[x] != x)
		parent[x] = find(parent, parent[x]);
	return parent[x];
}
int miniSpanningTree(int n, int m, vector<vector<int> >& cost) {
	int ki=0;
	vector<int> parent(n + 1);
	for(int i = 0; i <= n; i++) //��ʼ��������Ϊ�Լ�
		parent[i] = i;
	sort(cost.begin(), cost.end(), cmp); //��Ȩ��������
	int res = 0;
	for(int i = 0; i < cost.size(); i++) { //�������еıߣ�����ͨ�ķ���ͬһ�����鼯
		int x = cost[i][0];
		int y = cost[i][1];
		int z = cost[i][2];
		int px = find(parent, x); //����x�����ϱ߸���
		int py = find(parent, y); // ����y�����ϱ߸���
		if(px != py) { //������߲���ͬһ������
			res += z; //�߼���
			cout<<++ki<<"="<<res<<" "; 
			parent[px] = py; //���ö�����ͬһ������
		}
	}
	return res;
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
	int s=miniSpanningTree(n,m,arr);
	cout<<"���="<<s<<endl;
}
