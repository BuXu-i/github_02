#include<iostream>
using namespace std;
struct {
	int var;
	int next ;
	int head;
	int arr;
} Eege[100];
int cot=1;//��һ��ʼ
void add(int var,int a,int b) {
	Eege[cot].head=b;
	Eege[cot].var=var;//Ȩֵ
	Eege[cot].next=Eege[a].arr;
	Eege[a].arr=cot;
	cot++;
}
void pop(int a,int b) {//ɾ���ڵ�
	if(Eege[a].arr!=0) {//ɾ��ͷ���������ڵ㲻һ��  β�ڵ�Ҳ��һ��
		a=Eege[a].arr;
	} else {
		cout<<"û�иýڵ㣡����"<<endl;
		    return ;
	}
	while(Eege[a].head!=b) {
		a=Eege[a].next;//
	}
	//��Ҫ����һ��  //��Ҫ������һ��
}

void back(int a) {//���� ͷ
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
		cout<<"iΪ: "<<i<<" ָ��ֵ: "<<Eege[i].head<<" ����ָ��ֵ: "<<Eege[i].next<<" ����ĵ�ǰͷ: "<<Eege[i].arr<<" Ȩֵ: "<<Eege[i].var<<endl;
	}
	back(1);
	back(4);
	back(3);
}
