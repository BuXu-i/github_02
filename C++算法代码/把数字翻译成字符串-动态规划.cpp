#include<iostream>
using namespace std;
//�ظ��жϹ��� ������������Ч�ʻ������Ż� 
int main() {
	freopen("./���ݶ�ȡ.txt","r",stdin);
	string nums;
	int p1,p2;
	cin>>nums;
	if(nums[0]=='0' {
	cout<<"��ʼ0��ֹ����"<<endl;
	return 0;
}
if(nums[1]!='0') {
	p2=1;
	p1=1;
}
if((nums[1]-'0'+(nums[0]-'0')*10)<=26) {
	p1=2;
}
for(int i=2; i<nums.size(); i++) {
	if(nums[i]=='0'&&nums[i-1]=='0') {
			cout<<"��ʼ0��ֹ����"<<endl;
			return 0;
		} else if(nums[i]=='0'&&(nums[i-1]-'0')<=2||nums[i-1]=='0') {
			p2=p1;
			cout<<p2<<" "<<p1<<endl;
		} else if(nums[i]!='0'&&nums[i]<='9') {
			if((nums[i]-'0'+(nums[i-1]-'0')*10)<=26) {
//				p1=p1^p2;
//				p2=p1^p2;
//				p1=p1^p2;
//				p1+=p2;
				p1=p1+p2;
				p2=p1-p2;
			} else p2=p1;
			cout<<p2<<" "<<p1<<endl;
		} else return 0;
	}
	cout<<p1<<endl;
}
