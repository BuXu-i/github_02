#include<iostream>
using namespace std;
#include"algorithm"
#include<stack>
#include<vector>
int longestValidParentheses(string s) {
	// write code here
	int arr[s.size()];
	int w = 0;
	for (int i = 0; i < s.size(); i++) {
		arr[i] = 0;
		if (s[i] == ')') {
			if (s[i - 1] == '(') {
				if ((i - 2) >= 0) {
					arr[i] = 2 + arr[i - 2];
				} else {
					arr[i] = 2;
				}
			} else if (arr[i - 1]>0&&(i - arr[i - 1] - 1)>=0) {
				if (s[i - arr[i - 1]-1] == '('&& (i - arr[i - 1] - 2)>=0) {
					arr[i] = arr[i - arr[i - 1] - 2] + arr[i - 1]+2;//跳转位置的左侧一个和本位置的左侧之和
				} else if (s[i - arr[i - 1]-1] == '(') {
					arr[i] = arr[i - 1]+2;
				}
			}
			w = max(w, arr[i]);
		}
	}
	for(int i=0; i<s.size(); i++) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return w;
}
int main () {
	string s;
	freopen("./数据读取.txt","r",stdin);
	cin>>s;
	cout<<longestValidParentheses(s)<<endl;
}
