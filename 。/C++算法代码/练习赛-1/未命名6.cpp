#include<iostream>
using namespace std;
#include<algorithm>
int main() {
	freopen("1.txt","r",stdin);
	int n;
	cin>>n;
	string str1,str2,ki;
	string op;//´æ
	for(int i=0; i<n; i++) {
		cin>>ki;
		cin>>str1>>str2;
		if(ki=="add"){
			op=op+str1+str2+"-";
		}
		if(ki=="find"){
			if(op.find(str1+str2)!=-1){
				cout<<"yes"<<endl;
			}
			else{
				cout<<"no"<<endl;
			}
		}
	}

}

