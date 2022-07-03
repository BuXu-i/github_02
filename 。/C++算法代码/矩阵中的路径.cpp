#include<iostream>
using namespace std;
#include<vector>
bool dfst(vector<vector<char> >&matrix,vector<vector<bool> > dfs,string word,int x,int y,int k) {
	dfs[x][y]=1;          //���Խ�k++ ���� �ڵ��ú���ʱ��1 
	k++;                  //���Խ�ѡ������·���ϵ���ĸ��ֵ������ֵ ������  �������Բ���Ҫ���´������� 
	if(k==word.size()) {  //��if�����ĸ�ѡ��ʱ  ����ʹ��һ��if ����ʹ�� || ���Ž��������������һ�� ֻ��Ϊ������������ 
		return true;
	}
	if(x-1>=0&&matrix[x-1][y] == word[k]&&!dfs[x-1][y]) {
		if(dfst(matrix,dfs,word,x-1,y,k))
			return true;//����
	}
	if(y+1<dfs[x].size()&&matrix[x][y+1] == word[k]&&!dfs[x][y+1]) {
		if(	dfst(matrix,dfs,word,x,y+1,k))//����
			return true;
	}
	if(x+1<dfs.size()&&matrix[x+1][y] == word[k]&&!dfs[x+1][y]) {
		if(dfst(matrix,dfs,word,x+1,y,k))
			return true;//����
	}
	if(y-1>=0&&matrix[x][y-1] == word[k]&&!dfs[x][y-1]) {
		if(dfst(matrix,dfs,word,x,y-1,k))
			return true;//����
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
	vector<vector<bool> >dfs(matrix.size(),vector<bool>(matrix[0].size())) ;//��ʼ������
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
	cout<<"��ȡ���"<<endl;
	cout<<"�����"<<hasPath(matrix,"abcced")<<endl;
	return 0;
}
