#include<iostream>
using namespace std;
#include<vector>
#include <algorithm>
//使用了数组 来存储 key 值 这默认所有为字母 区分大小写来存储 的 。。。未改进。。 
int main() {
	freopen("./数据读取.txt","r",stdin);
	string s;
	cin>>s;
	vector<int>arr;
	bool p=false;
	int suu=0;
	int mae=0;//初始值
	for(int i=0; i<57; i++) {
		arr.push_back(-1);
		cout<<" "<<arr[i]<<" ";
	}
	cout<<endl;
	for(int i=0; i<s.size(); i++) { //需要再来次 思考看看
		if(arr[(s[i]-'A')]==-1) {
			arr[s[i]-'A']=i;//记录出现坐标
		} else {
			if(p) {
				suu=max(suu,i-mae-1);
				mae=arr[s[i]-'A'];//应该是更新最大坐标 max
				arr[s[i]-'A']=i;
			} else { //第一次出现  左侧 计算
				suu=i;//长度
				mae=arr[s[i]-'A'];//之前的坐标  加一位
				arr[s[i]-'A']=i;//更新最新出现坐标
				p=true;
			}
			cout<<"suu="<<suu<<endl;
		}
	}
	int i=s.size();
	cout<<"suu="<<suu<<endl;
	if(!p) cout<<"全部未重复"<<i<<endl;;
	suu=max(suu,i-mae-1);
	cout<<"suu="<<suu<<endl;
	return 0;
}
