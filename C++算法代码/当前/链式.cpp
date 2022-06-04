#include<iostream>
using namespace std;
struct {
	int var;
	int next ;
	int head;
	int arr;
} Eege[100];
int cot=1;//从一开始
void add(int var,int a,int b) {
	Eege[cot].head=b;
	Eege[cot].var=var;//权值
	Eege[cot].next=Eege[a].arr;
	Eege[a].arr=cot;
	cot++;
}
void pop(int a,int b) {//删除节点
	if(Eege[a].arr!=0) {//删除头结点和其他节点不一样  尾节点也不一样
		a=Eege[a].arr;
	} else {
		cout<<"没有该节点！！！"<<endl;
		    return ;
	}
	while(Eege[a].head!=b) {
		a=Eege[a].next;//
	}
	//需要改上一个  //需要保存上一个
}

void back(int a) {//传入 头
	if(Eege[a].arr!=0) {
		cout<<Eege[Eege[a].arr].head<<"   "<<Eege[Eege[a].arr].var<<endl;
		a=Eege[Eege[a].arr].next;
	} else return ;
	while(a!=0) {
		cout<<Eege[a].head<<"   "<<Eege[a].var<<endl;
		a=Eege[a].next;
	}
} 
int main () {
	add(1,1,2);
	add(2,1,4);
	add(4,2,3);
	add(3,4,2);
	for(int i=0; i<10; i++) {
		cout<<"i为: "<<i<<" 指向值: "<<Eege[i].head<<" 其他指向值: "<<Eege[i].next<<" 保存的当前头: "<<Eege[i].arr<<" 权值: "<<Eege[i].var<<endl;
	}
	back(1);
	back(4);
	back(3);
}
