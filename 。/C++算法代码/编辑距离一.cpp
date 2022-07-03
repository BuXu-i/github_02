#include<iostream>
using namespace std;
#include<algorithm>//max  min  swap 
#include<vector>
int editDistance(string str1, string str2) {
	// write code here
	cout<<str1<<" "<<str2<<endl;
	int s=0;
	int dp1[str2.size()+1];
	cout<<"dp1="<<endl;
	for(int i=0; i<str2.size()+1; i++) {
		dp1[i]=s++;
		//cout<<dp1[i]<<" ";
	}
//	cout<<endl;
	for(int i=0; i<str1.size(); i++) {
		cout<<str1[i]<<" ";
	}
	cout<<endl;
	cout<<"长度="<<str2.size()+1<<endl;
	s=1;
	int dp2[str2.size()+1];
	int i=0;
	for(; i<str1.size(); i++) { //长度
		dp2[0]=s++;
		for(int j=1; j<str2.size()+1; j++) { //单次的长度
			if(str1[i]==str2[j-1])
				dp2[j]=min(dp2[j-1]+1, min(dp1[j-1],dp1[j]+1));
			else
				dp2[j]=min(dp2[j-1]+1, min(dp1[j-1]+1,dp1[j]+1));
		}
		dp1[0]=s++;
		i++;
		if(i<str1.size()) {
		for(int j=1; j<str2.size()+1; j++) { //单次的长度
			if(str1[i]==str2[j-1])
				dp1[j]=min(dp1[j-1]+1, min(dp2[j-1],dp2[j]+1));
			else
				dp1[j]=min(dp1[j-1]+1, min(dp2[j-1]+1,dp2[j]+1));
			}
		}
		cout<<"s="<<s<<" :";
		for(int p=0; p<=str2.size(); p++) {
			cout<<dp2[p]<<" ";
		}
		cout<<endl;
		cout<<"s="<<s<<" :";
		for(int p=0; p<=str2.size(); p++) {
			cout<<dp1[p]<<" ";
		}
		cout<<endl;
	}
	return str1.size()%2==0?dp1[str2.size()]:dp2[str2.size()];
}
int main() {
	string str1,str2;
	freopen("./数据读取.txt","r",stdin);
	cin>>str1>>str2;
	cout<<"答案="<<editDistance(str1,str2)<<endl;

}
