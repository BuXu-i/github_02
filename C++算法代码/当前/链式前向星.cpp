#include<iostream>
using namespace std;
#include<vector>
struct {
	int to;
	int next;
	int w;
} edge[1005];
int head[105]= {0},cnt=1; 

//�����ظ���  �����ж��Ƿ���Ҫ���� �����ж�  �ظ���Ҳ����� ������û��Ӱ�졣
void add(int u,int to,int w) {//һ����ʼ�ߺ��ձ� �Լ�Ȩֵ//
	edge[cnt].to=to;//�ձ� ���� //��˳����
	edge[cnt].next=head[u];//head ��head[u]û�и��¹� �����edge��ֵ �������ʼ��ֵ   һ��Ϊ����
	edge[cnt].w=w;
	head[u]=cnt++; //head��¼ Ӧ��i�� Ӧ��ȥ��˭ Ҫ�յ�  //��Զָ��ͷ
}
void pop() {

}
void fora(int a) {
	int k=1;
	for(int i=head[a]; i; i=edge[i].next) {
		//cout<<k++<<"��=";
		cout<<edge[i].to<<" ";
	}
}
int main() {
	freopen("./kihonn/���ݶ�ȡ.txt","r",stdin);
	int x,y,z;
	for(int i=0; i<1000; i++) {
		cin>>x>>y>>z;
		add(x,y,z);
	}
	cout<<cnt<<endl;
	//���ÿһ�������ӵ������յ� 
	for(int i=0;i<105;i++){
		fora(i);
		cout<<endl;
	}
	cout<<"fenjie"<<endl;
	return 0;
}
