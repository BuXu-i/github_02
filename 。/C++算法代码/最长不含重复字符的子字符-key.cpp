#include<iostream>
using namespace std;
#include<vector>
#include <algorithm>
//ʹ�������� ���洢 key ֵ ��Ĭ������Ϊ��ĸ ���ִ�Сд���洢 �� ������δ�Ľ����� 
int main() {
	freopen("./���ݶ�ȡ.txt","r",stdin);
	string s;
	cin>>s;
	vector<int>arr;
	bool p=false;
	int suu=0;
	int mae=0;//��ʼֵ
	for(int i=0; i<57; i++) {
		arr.push_back(-1);
		cout<<" "<<arr[i]<<" ";
	}
	cout<<endl;
	for(int i=0; i<s.size(); i++) { //��Ҫ������ ˼������
		if(arr[(s[i]-'A')]==-1) {
			arr[s[i]-'A']=i;//��¼��������
		} else {
			if(p) {
				suu=max(suu,i-mae-1);
				mae=arr[s[i]-'A'];//Ӧ���Ǹ���������� max
				arr[s[i]-'A']=i;
			} else { //��һ�γ���  ��� ����
				suu=i;//����
				mae=arr[s[i]-'A'];//֮ǰ������  ��һλ
				arr[s[i]-'A']=i;//�������³�������
				p=true;
			}
			cout<<"suu="<<suu<<endl;
		}
	}
	int i=s.size();
	cout<<"suu="<<suu<<endl;
	if(!p) cout<<"ȫ��δ�ظ�"<<i<<endl;;
	suu=max(suu,i-mae-1);
	cout<<"suu="<<suu<<endl;
	return 0;
}
