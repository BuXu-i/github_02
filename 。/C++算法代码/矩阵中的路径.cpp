#include<iostream>
using namespace std;
#include<vector>
bool dfst(vector<vector<char> >&matrix,vector<vector<bool> > dfs,string word,int x,int y,int k) {
	dfs[x][y]=1;          //可以将k++ 消除 在调用函数时加1 
	k++;                  //可以将选择过后的路径上的字母赋值不可能值 如数字  这样可以不需要重新创建数组 
	if(k==word.size()) {  //在if进行四个选择时  可以使用一个if 并且使用 || 符号将四种情况包含在一起 只是为了缩减代码量 
		return true;
	}
	if(x-1>=0&&matrix[x-1][y] == word[k]&&!dfs[x-1][y]) {
		if(dfst(matrix,dfs,word,x-1,y,k))
			return true;//向上
	}
	if(y+1<dfs[x].size()&&matrix[x][y+1] == word[k]&&!dfs[x][y+1]) {
		if(	dfst(matrix,dfs,word,x,y+1,k))//向右
			return true;
	}
	if(x+1<dfs.size()&&matrix[x+1][y] == word[k]&&!dfs[x+1][y]) {
		if(dfst(matrix,dfs,word,x+1,y,k))
			return true;//向下
	}
	if(y-1>=0&&matrix[x][y-1] == word[k]&&!dfs[x][y-1]) {
		if(dfst(matrix,dfs,word,x,y-1,k))
			return true;//向左
	}
	cout<<"k="<<k<<endl;
	for(int i=0; i<matrix.size(); i++) {
		for(int j=0; j<matrix[i].size(); j++) {
			cout<<dfs[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	return false;
}
bool hasPath(vector<vector<char> >& matrix, string word) {
	// write code here
	vector<vector<bool> >dfs(matrix.size(),vector<bool>(matrix[0].size())) ;//初始化矩阵
	for(int i=0; i<matrix.size(); i++) {
		for(int j=0; j<matrix[0].size(); j++) {
			if(word[0]==matrix[i][j]) {
				if(dfst(matrix,dfs,word,i,j,0)) {
					return true;
				}
			}
		}
	}
	return false;
}
int main() {
	char x;
	vector<vector<char> >matrix(3);
	for(int i=0; i<matrix.size(); i++) {
		for(int j=0; j<4; j++) {
			cin>>x;
			matrix[i].push_back(x);
		}
	}
	for(int i=0; i<matrix.size(); i++) {
		for(int j=0; j<matrix[i].size(); j++) {
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"读取完成"<<endl;
	cout<<"结果："<<hasPath(matrix,"abcced")<<endl;
	return 0;
}
