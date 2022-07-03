#include<iostream>
using namespace std;

bool match(string str, string pattern) {
	// write code here
	int k=0;//匹配字符串已到达下标
	int suu=0;//计数使用
	char suuji;
	if(str.size()==0&&pattern.size()==0) return true;
	if(pattern.size()==0) return false;
	for(int i=0; i<pattern.size(); i++) {
		if(pattern[i]!='.') { //星号前肯定有字母
			if(i+1<pattern.size()&&pattern[i+1]=='*'&&pattern[i]!='*') {//后面为星号
				//开始计算str的
				while(k<str.size()&&str[k]==pattern[i]) {
					k++;
					suu++;//用来 后续还有相同字母
				}
				suuji=pattern[i];//记录的应该是 正则表达式的字母
				i++;//涉及到了后续一个 星号
			} else if(k<str.size()&&str[k]==pattern[i]) { //该字母为单独 //while 找完了所有相邻相同的字母
				k++;//向前走一位
				suu=0;//计数归零
				suuji=' ';//字母清空
			} else if(k==str.size()&&str[k-1]==suuji&&suu>0) {
				suu--;//计数可以少一位  好像不需要计数
			} else if(pattern[i]=='*')
				continue;
			else {
				cout<<k<<" "<<i<<endl;
				return false;
			}
		} else if((i+1)<pattern.size()&&pattern[i+1]=='*') {
			return 1;
		} else { //点号的匹配  if(pattern[i]=='.')
			if(k<str.size()&&suu!=0&&str[k]!=str[k-1]) {
				k++;
				suu=0;//计数归零
				suuji=' ';//字母清空
			} else if(k<str.size()&&suu!=0&&str[k]==str[k-1]) {
				suu--;
				k++;
			} else if(k<str.size()) {
				k++;
			} else {
				return false;
				cout<<"点号问题 "<<k<<" "<<i<<endl;
			}

		}
	}
	return true; //kannbi完備的走过了全程
}
int main() {
	string str,patt;
	freopen("./数据读取.txt","r",stdin);
	cin>>str>>patt;
	cout<<match(str,patt)<<endl;;
}
