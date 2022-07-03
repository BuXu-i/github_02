//滑动窗口
//1. 还没有 原先写的  保存数组  要是最大死去 重新遍历size数组  不然有更大更新最大 ;
//2. 双指针 2 的更新方法 用双指针确定正在存储的size数组  就不需要重新创建数组来存储
#include<iostream>
using namespace std;
#include <vector>
#include<deque>
vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
	deque<int>arrt;//单向队列的解法  //存储遍历过的下标
	vector<int>ret;//返回的数组
	if(num.size()<size||size==0) {
		return ret;
	}
	cout<<"溢出?"<<endl;
	for(int i=0; i<num.size(); i++) {
		cout<<"溢出?"<<endl;
		while(true) {
			if(arrt.empty()) {
				arrt.push_back(i);//入队
				break;
			}
			if(num[arrt.back()]<=num[i]) {
				arrt.pop_back();//队尾出队
			} else {
				arrt.push_back(i);//入队
				break;
			}
		}
		if((i-arrt.front())>=size) { //头生命结束
			arrt.pop_front();//头出队
		}
		if(i>=size-1) {
			ret.push_back(num[arrt.front()]);//队首 元素入队
		}
	}
	for(int i=0; i<num.size(); i++) {
		cout<<num[i]<<" ";
	}
	cout<<endl;
	for(int i=0; i<ret.size(); i++) {
		cout<<ret[i]<<" ";
	}
	cout<<endl;
	return ret;
}
int main() {
	vector<int>num;
	int x;
	for(int i=0; i<7; i++) {
		cin>>x;
		num.push_back(x);
	}
	num=maxInWindows(num,3);
	for(int i=0; i<num.size(); i++) {
		cout<<num[i]<<" ";
	}
	cout<<endl;
}
