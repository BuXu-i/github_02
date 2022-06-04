#include<iostream>
using namespace std;
#include<utility>
#include<vector>
#include<queue>
#include<algorithm>
#include<sstream>
struct npm {
	bool operator()(pair<int,int>a,pair<int,int>b) {
		return  a.first>b.first;
	}
};
static bool fnmp(pair<int,int>a,pair<int,int>b) {
	return a.first>b.first;
}
int main() {
	freopen("1.txt","r",stdin);
	pair<int,int>pp;
	vector<pair<int,int> >ver;
	for(int i=0; i<5; i++) {
		ver.push_back({i,9});
	}
	sort(ver.begin(),ver.begin()+3,fnmp);
	reverse(ver.begin(),ver.begin()+3) ;
	for(int i=0; i<5; i++) {
		cout<<ver[i].first<<" "<<endl;
	}
	pp.first=999;
	pp.second=666;
	cout<<pp.second<<" "<<pp.first<<endl;
//	int ki,fki;
//	string str;
//	stringstream stream;
//	stream<<str;
//	stream>>ki;
//	stream.str("");
//	stream.clear();
//	cout<<ki;
}
