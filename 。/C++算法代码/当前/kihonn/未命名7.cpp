#include<iostream>
using namespace std;
#include<algorithm>
struct edge {
	int *arr[42];
	bool pp;
};
edge *pp=new edge();
edge *op;
void add(string str) {
	op=pp;
	for(int i=0; i<str.size; i++) {
		if(op->arr[str[i]-'81']==NULL) {
			op->arr[str[i]-'81']=new edge();
		}
		op=op->arr[str[i]-'81'];
	}
	op->pp=true;
}
bool find() {

}
int main() {
	freopen("1.txt","r",stdin);
	int n;
	cin>>n;
	string str,ki,dp;
	string op;//´æ
	for(int i=0; i<n; i++) {

	}

}

