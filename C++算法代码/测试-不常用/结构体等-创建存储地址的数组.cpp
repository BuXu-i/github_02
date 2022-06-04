#include<iostream>
using namespace std;
#include<vector >
struct Ti {
	int var;
	struct Ti *Ri=NULL;
	struct Ti *Li=NULL;
};
int rob(vector<int>& nums) {

}
int main () {
	vector<Ti*>arr;
	Ti *p1=new Ti();
	p1->var=10;
	cout<<"p1的var="<<p1->var<<endl;
	p1->Li=NULL;
	p1->Ri=NULL;
	Ti *p2=new Ti();
	p2->var=888;
	cout<<"p1的var="<<p1->var<<endl;
	p1->Li=p2;
	cout<<"p1的var="<<p1->var<<endl;
	p1=p1->Li;
	arr.push_back(p1);
	arr.push_back(p2);
	cout<<"p1的var="<<p1->var<<endl;
}
