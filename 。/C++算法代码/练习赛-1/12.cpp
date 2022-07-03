#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
int main() {
	freopen("1.txt","r",stdin);
	int n,m;
	cin>>n>>m;
	vector<vector<int>>arr(n+1);
	int x;
	string str;
	for(int i=1; i<=n; i++) {
		str="";
		while(true) {
			char cha=cin.get();
			if(cha=='\n') {
				if(str=="")continue;
				x=stoi(str,0);
				arr[i].push_back(x);
				break;
			} else if(cha==' ') {
				x=stoi(str,0);
				arr[i].push_back(x);
				str="";
			} else str+=cha;
		}
	}
	int a,b;
	x=1;
	int op[m];
	for(int i=0; i<m; i++) {
		cin>>a>>b;
		if(a==1){
			op[b]=x;
			cout<<x<<endl;
		}
		else if(a==0){
			x=arr[x][b];
		}
		else{
			x=op[b];
		}
	}
	printf("%d",x);
	return 0;
}
