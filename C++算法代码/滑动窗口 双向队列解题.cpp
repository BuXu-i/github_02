//��������
//1. ��û�� ԭ��д��  ��������  Ҫ�������ȥ ���±���size����  ��Ȼ�и��������� ;
//2. ˫ָ�� 2 �ĸ��·��� ��˫ָ��ȷ�����ڴ洢��size����  �Ͳ���Ҫ���´����������洢
#include<iostream>
using namespace std;
#include <vector>
#include<deque>
vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
	deque<int>arrt;//������еĽⷨ  //�洢���������±�
	vector<int>ret;//���ص�����
	if(num.size()<size||size==0) {
		return ret;
	}
	cout<<"���?"<<endl;
	for(int i=0; i<num.size(); i++) {
		cout<<"���?"<<endl;
		while(true) {
			if(arrt.empty()) {
				arrt.push_back(i);//���
				break;
			}
			if(num[arrt.back()]<=num[i]) {
				arrt.pop_back();//��β����
			} else {
				arrt.push_back(i);//���
				break;
			}
		}
		if((i-arrt.front())>=size) { //ͷ��������
			arrt.pop_front();//ͷ����
		}
		if(i>=size-1) {
			ret.push_back(num[arrt.front()]);//���� Ԫ�����
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
