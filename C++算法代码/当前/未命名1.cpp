#include<iostream>
using namespace std;
#include<queue>
#include<vector>
#include<utility>
struct cpm {
	bool operator()(pair<int, int>T1,pair<int, int>T2) {
		return T1.second>T2.second?1:0;
	}
};
int main() {
	priority_queue<pair<int,int>,vector<pair<int,int> >,cpm>nm;
	return 0;
}
