//二叉树的模板
#include<iostream>
using namespace std;
#include<queue>
struct Treenode {
	Treenode *left;
	Treenode *right;
	string op;
}*head;
string str;
void add(queue<Treenode*>&que, int n) {
	while (--n != 0) {
		que.front()->left = new Treenode();
		que.push(que.front()->left);
		cin >> str;
		que.back()->op = str;
		cout << str<<" ";
		if (--n == 0) return;
		que.front()->right = new Treenode();
		que.push(que.front()->right);
		cin >> str;
		que.back()->op = str;
		cout << str<<" ";
		que.pop();
	}
}
bool pp = false;
string ki="-1";
void conslen(Treenode *root, string p) {
	if (root->left != NULL) {
		conslen(root->left, p);
	}
	if(pp==true){
		ki=root->op;
		pp=false;
//		return ;
	}
	if (root->op == p) {
		pp = true;
		cout<<" "<<"*"<<" ";
	}
	cout<<root->op<<" ";
	if (root->right != NULL) {
		conslen(root->right, p);
	}
}
int main() {
	freopen("1.txt", "r", stdin);
	int n;
	cin >> n;
	string sx;
	cin >> sx;
	head = new Treenode();
	head->op = sx;
	queue<Treenode*>que;
	que.push(head);
	add(que, n);
	cout<<endl;
	conslen(head, "4");
	
	cout<<endl<<"ki:="<<ki;
//	**********初始化完成**************
}
