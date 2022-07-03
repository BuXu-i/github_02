#include<iostream>
using namespace std;
#include<vector>
struct edge {
	int jiu;
	int LR;
	vector<int>cs;
};
//edge *op=new edge();
int tiao;
int yjiu;
string str;
void fun(int qi, int sLR, int sjiu, string str, edge *arr[],vector<bool>pp) {
	sjiu+=arr[qi]->jiu;
	sLR+=arr[qi]->LR;
	for (int i = 0; i<arr[qi]->cs.size(); i++) {
		
	}
}
int main() {
	freopen("1.txt", "r", stdin);
	int n, m, s, d;
	cin >> n >> m >> s >> d;
	edge *arr[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new edge();
		cin >> arr[i]->jiu;
	}
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		arr[a]->cs.push_back(b);
		arr[a]->LR = c;
	}
	vector<bool>pp;
	fun(s,0,0,"",arr,pp);
}
