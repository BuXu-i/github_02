#include<iostream>
using namespace std;
#include<algorithm>
int main() {
	string str;
	string strop;
	int ki=-1;
	while(true) {
		cin>>str;
		freopen("1.txt","r",stdin);
		//cout<<"!= ="<<str<<endl;
		if(str.find('.')!=-1) {//ÊÕµÃµ½
			if(str.find('a')&&str.size()-1>ki) {
				cout<<strop;
			}
			if(strop.size()==0) {
				cout<<"No";
			} else {
				cout<<strop;
			}
			return 0;
		}
		cout<<str.find('a')<<" "<<str.size()<<" "<<ki<<endl;
		if(str.find('a')!=-1&&str.size()>ki) {
			strop=str;
			ki=str.size();
			cout<<strop<<endl;
		}
	}
}


