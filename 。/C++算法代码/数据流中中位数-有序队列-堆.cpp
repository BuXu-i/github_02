#include<iostream>
using namespace std;
//#include<deque>
#include<queue>
priority_queue<int, vector<int>,less<int> > q;
priority_queue<int, vector<int>, greater<int> > p;
void Insert(int num) {
	if(q.size()==0) {
		q.push(num);
	} else if(p.size()==0&&q.top()<=num) {
		p.push(num);
	} else if(q.top()>=num||(q.top()<num&&p.top()>num)) {
		q.push(num);
		if(q.size()-p.size()==2) {
			p.push(q.top());
			q.pop();
		}
	} else  {   //if(q.top()<num&&p.top()<=num)  //剩下的情况不需要判断了 
		p.push(num);
		if(q.size()<p.size()) {
			q.push(p.top());
			p.pop();
		}
	}
}
double GetMedian() {
//	if(p.size()==0) {  //防止未出入任何数据被调用 
//		return  q.top();
//	}
	if(p.size()==q.size()) {
		return (p.top()+q.top()+0.0)/2;
	}
	return q.top();
}
int main () {
	freopen("./数据读取.txt","r",stdin);
	int x;
	for(int i=0;i<10; i++) {
		cin>>x;
		Insert(x);
		cout<<GetMedian()<<endl;
	}
	return 0;
}
