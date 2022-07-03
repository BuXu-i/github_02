#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
struct edge {
	string name;
	//int id;//对应数组中存储的位置
	int xiao;//小兵
	vector<pair<int,int>>fhead;// 下一个id 和距离
};
void app(string qi,string zhong,int LR,vector<edge*>arr) {
	//cout<<"传入: "<<qi<<" "<<zhong<<endl;
	int a=-1,b=-1;
	for(int i=0; i<arr.size(); i++) {
		if(arr[i]->name==qi) {
			a=i;
		} else if(arr[i]->name==zhong) {
			b=i;
		}
		if(a==0&&b==0) {
			break;
		}
	}
	arr[a]->fhead.push_back({b,LR});
	arr[b]->fhead.push_back({a,LR});
	//cout<<"存 起"<<qi<<" 终"<<zhong<<" 起"<<a<<" 终"<<b<<endl;
}
string Lop;
int LRop=100000;
int Cop;//城市
int Sop;//杀敌
int ssww=0;
void gg(string op,int LR,int sw,int sxiao) {
	Lop=op;
	LRop=LR;
	Cop=sw;
	Sop=sxiao;
}
void dfs(string op,string str,int a,string zhong,vector<edge*>head,int sw,int sxiao,vector<bool>pp,int LR) { //首先找距离最短  其次是城市 再是杀敌
//有输出任务;
	int kp=head[a]->fhead.size();
	op+=str+"->";
	pp[a]=false;
	if(str==zhong) {//退出
		if(LR<LRop) {
		//	cout<<"距离"<<endl;
			ssww=1;
			gg(op,LR,sw,sxiao);
		} else if(LR==LRop) {
			ssww++;
			if(sw>Cop) {
				cout<<"城市"<<endl;
				gg(op,LR,sw,sxiao);
			} else if(Cop==sw) {
				if(sxiao>Sop) {
					cout<<"杀敌"<<endl;
					gg(op,LR,sw,sxiao);
				}
			}
		}
		//cout<<" ?zhong? "<<endl;
		return ;
	}
	for(int i=0; i<kp; i++) {
		if(pp[head[a]->fhead[i].first]) {
			int kip=head[a]->fhead[i].first;
			dfs(op,head[kip]->name,kip,zhong,head,sw+1,sxiao+head[kip]->xiao,pp,LR+head[a]->fhead[i].second);
			//dfs(op,head[head[a]->fhead[i].first].name,head[a]->fhead[i].first,zhong,head,sw+1,sxiao+head[head[a]->fhead[i].first]->xiao,pp,LR+head[a]->fhead[i].second);
		}
	}
}
int main() {
	freopen("1.txt","r",stdin);
	int n,m;
	cin>>n>>m;
	string qi,zhong;
	string str1,str2;
	cin>>qi>>zhong;
	int ki;
	vector<edge*>arr;
	arr.push_back(new edge());
	arr.back()->name=qi;
//	arr.back()->id=0;
	int num=1;
	for(int i=0; i<n-1; i++) {
		cin>>str1>>ki;
		arr.push_back(new edge());
		arr.back()->name=str1;
		arr.back()->xiao=ki;
		//	arr.back()->id=num++;

	}
//	cout<<arr.size()<<"  qwe123qwe"<<endl;
//	for(int i=0; i<n; i++) {
//		cout<<arr[i]->name<<" ";
//	}
//	cout<<endl;
	//路径
	for(int i=0; i<m; i++) {
		cin>>str1>>str2>>ki;//起 终 距离
		//cout<<str1<<" "<<str2<<" "<<ki<<endl;
		app(str1,str2,ki,arr);
	}
//	for(int i=0; i<n; i++) {
//	//	cout<<"第一个城市: "<<arr[i]->name<<" "<<arr[i]->xiao<<"     ";
//		for(int j=0; j<arr[i]->fhead.size(); j++) {
//			cout<<arr[i]->fhead[j].first<<" "<<arr[i]->fhead[j].second<<" ";
//		}
//		cout<<endl;
//	}
	str1="";//str存储路径结果
	vector<bool>pp(n,1);
	dfs("",qi,0,zhong,arr,0,0,pp,0);
	Lop.append(Lop,0,Lop.size()-2);
	cout<<"路: "<<Lop<<"  最短路条数: "<<ssww<<"  距离: "<<LRop<<" 小兵: "<<Sop<<"  城市: "<<Cop;
	//string Lop;
	//int LRop;
	//int Cop;//城市
	//int Sop;//杀敌
	return 0;
}
