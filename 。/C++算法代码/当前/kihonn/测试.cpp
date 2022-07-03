#include<iostream>
using namespace std;
#include<deque>
#include<queue>
#include<stack>
//#include<unordered_map>
void duru() {
	freopen("1.txt","r",stdin);
}
int fun(int a,int b) {
	return a+b;
}
int main() {
	duru();
	int a,b;
	string str;
	cin>>a>>b;
	cout<<fun(a,b)<<endl;
	cin>>str;
	cout<<a<<" "<<b<<" "<<str<<endl;
	stack<int>arqwe;
	deque<int>arr;
	arr.push_back(123);
	arr.push_front(123);
	arr.push_front(12312);
	cout<<arr.size();
	queue<int>asd;
}

