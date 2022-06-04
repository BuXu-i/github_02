#include<iostream>
using namespace std;
//#include<deque>
#include<queue>

int main () {
	queue<int>arr;
	freopen("./Êý¾Ý¶ÁÈ¡.txt","r",stdin);
	int x;
	for(int i=0; i<9; i++) {
		cin>>x;
		arr.push(x);
	}
	priority_queue<int, vector<int>,less<int> > p;
	priority_queue<int, vector<int>, greater<int> > q;
	for(int i=0; i<11; i++) {
		cout<<arr.front()<<" ";
		p.push(arr.front());
		cout<<p.top();
		arr.pop();
	}
	return 0;
}
