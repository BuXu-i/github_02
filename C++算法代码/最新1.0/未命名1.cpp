#include<iostream>
using namespace std;
#include<string>
#include<utility>
#include<queue>
#include<algorithm>
#include<vector>
struct edge {
	int a;
	int *arr[24];
};
struct npm {
	bool operator()(pair<int, int>a, pair<int, int>b) {
		return a.first > b.second;

	}
};
static bool npm2(int a, int b) {
	return a > b;
}
void Éµ±Æ(int a, int b) {
	cout << a << " " << b << endl;

}
int main() {
	freopen("1.txt", "r", stdin);
	string  n = to_string(123);
	cout << n << endl;
	int op = stoi(n);
	cout << op << endl;
	priority_queue<pair<int, int>, vector<pair<int, int>>, npm>prique;
	int shuzhu[4] = {3, 5, 4, 7};
	vector<int>ver = {3, 5, 4, 7};
	sort(shuzhu, shuzhu + 4, npm2);
	for (int i = 0; i < (int)(sizeof(shuzhu) / sizeof(shuzhu[0])); i++) {
		//TODO
		cout << shuzhu[i] << " ";
	}
	cout << endl;
	sort(ver.begin(), ver.end(), npm2);
	for (int i = 0; i < (int)ver.size(); i++) {
		cout << ver[i] << " ";
	}
	cout << endl;
	int Ðí = 132;
	cout << Ðí;
	Éµ±Æ(123, 456);
	int qwe;
	cin >> qwe;
	cout<<qwe;
	deque<int>deq;
	string str="abcde";
	cout<<str<<endl;
	reverse(str.begin(),str.end());
	cout<<str<<endl;
}
