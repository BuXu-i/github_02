#include<iostream>
using namespace std;
#include"vector"
int s;
void dfs(vector<vector<int> >&edge,int boo[],int head,int pp) {
	if(boo[pp]>boo[head]&&boo[head]>=2) {
		s=s+boo[head]-1;//减去本身的点
		cout<<"B"<<" ";
	} else if(boo[pp]<boo[head]&&edge.size()-boo[pp]>=3) {
		s=s+edge.size()-boo[pp]-2;
		cout<<"A"<<" "; 
	}
}
int dfsf(vector<vector<int> >&edge,int boo[],int ki,int pp) {
	for(int i=0; i<edge[ki].size(); i++) {
		if(edge[ki][i]!=pp)
		    boo[ki]=boo[ki]+dfsf(edge,boo,edge[ki][i],ki);
	}
	return boo[ki];
	
}
int main() {
	int t,n;
	cin>>t;
    vector<int>tt(t);
	while(t--) {
		scanf("%d",&n);
		int x,y; 
        vector<vector<int> >edge(n+1);
		for(int i=0; i<n-1; i++) {
			scanf("%d %d",&x,&y);
			edge[x].push_back(y);
			edge[y].push_back(x);
		}
		int boo[edge.size()];
		for(int i=0; i<edge.size(); i++) 
			boo[i]=1;
		dfsf(edge,boo,1,0);
		s=0;
		for(int i=1; i<=n; i++) {
			if(edge[i].size()>=3)
			for(int j=0; j<edge[i].size(); j++) {
				dfs(edge,boo,edge[i][j],i);
			}
		}
		tt[t]=s;
	}
    for(int i=tt.size()-1;i>=0;i--){
        printf("%d\n",tt[i]);
    }
	return 0;
}
