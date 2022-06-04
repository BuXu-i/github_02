#include<iostream>
using namespace std;
#include<vector>
struct {
	int to;
	int next;
	int w;
} edge[1005];
int head[105]= {0},cnt=1; 

//若有重复边  自行判断是否需要加入 若不判断  重复边也会加入 对整体没有影响。
void add(int u,int to,int w) {//一个起始边和终边 以及权值//
	edge[cnt].to=to;//终边 告诉 //按顺序来
	edge[cnt].next=head[u];//head 若head[u]没有更新过 则其给edge赋值 该数组初始化值   一般为负数
	edge[cnt].w=w;
	head[u]=cnt++; //head记录 应该i边 应该去找谁 要终点  //永远指向头
}
void pop() {

}
void fora(int a) {
	int k=1;
	for(int i=head[a]; i; i=edge[i].next) {
		//cout<<k++<<"次=";
		cout<<edge[i].to<<" ";
	}
}
int main() {
	freopen("./kihonn/数据读取.txt","r",stdin);
	int x,y,z;
	for(int i=0; i<1000; i++) {
		cin>>x>>y>>z;
		add(x,y,z);
	}
	cout<<cnt<<endl;
	//输出每一个点链接的所有终点 
	for(int i=0;i<105;i++){
		fora(i);
		cout<<endl;
	}
	cout<<"fenjie"<<endl;
	return 0;
}
