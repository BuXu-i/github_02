#include<iostream>
using namespace std;
#include<utility>
#include<vector>
#include<queue>
#include<algorithm>
#include<sstream>
struct npm {
	bool operator()(pair<int,int>a,pair<int,int>b) {
		return  a.first>b.first;
	}
};
static bool fnmp(pair<int,int>a,pair<int,int>b) {
	return a.first>b.first;
}

int main() {
	int s=0;
	int jk=2;//五天后
	int nian=2022,yue=4,re=7,week=4;
	int tuki[13]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
	while(true) {
		for(int i=re; i<tuki[yue]; i++) {
			week=(week+1)%7;//星期
			re++;
			if(re==1||week==0) {
				s+=2;
			} else s++;
			if(nian==2022&&yue==5&&re==1) {
				cout<<s;
				return 0;
			}
		}
		re=0;//日期重置
		if(yue<13)yue++;
		else {
			yue=1;
			nian++;
			if((nian%100!=0&&nian%4==0)||nian%400==0) {
				tuki[2]=29;
			} else tuki[2]=28;
		}

	}

}
