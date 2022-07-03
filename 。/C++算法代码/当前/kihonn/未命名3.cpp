#include <iostream>
using namespace std;

int main() {
	int s=0;
	int nian=2000,yue=1,re=0,week=4;
	int tuki[13]= {0,31,29,31,30,31,30,31,31,30,31,30,31};
	while(true) {
		for(int i=re; i<tuki[yue]; i++) {
			week=(week+1)%7;//星期
			re++;
			if(re==1||week==0) {
				s+=2;
			} else s++;
//			if(nian==2000&&yue==1){
//				cout<<"月 "<<yue<<" 日"<<re<<" 星期"<<week+1<<" s="<<s<<endl;
//			}
//			if(nian==2020&&yue==10&&re==1) {
//				cout<<s;
//				return 0;
//			}
		}
		re=0;//日期重置
		yue++; 
		if(yue==13) {
			yue=1;
			nian++;
			if((nian%100!=0&&nian%4==0)||nian%400==0) {
				tuki[2]=29;
			} else tuki[2]=28;
		}
	}
}
