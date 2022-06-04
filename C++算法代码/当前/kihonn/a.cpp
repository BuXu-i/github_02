#include<iostream>
using namespace std;

int main() {
	int rq[13]= {0,31,29,31,30,31,30,31,31,30,31,30,31};
//int tuki[13]= {0,31,29,31,30,31,30,31,31,30,31,30,31};
	int nian=2000,yue=1,re=0,keey=4;//ÍùºóÒ»Ìì
	int s=0;
	while(true){
		for(int i=re;i<rq[yue];i++){
			re++;
			keey=(keey+1)%7;
			if(keey==0||re==1){
				s+=2;
			}else s++;
			if(nian==2020&&yue==10&&re==1){
				cout<<s;
				return 0;
			}
		}

		re=0;
		yue++;
		if(yue==13) {
			yue=1;
			nian++;
			if((nian%100!=0&&nian%4==0)||nian%400==0) {
				rq[2]=29;
			} else rq[2]=28;
		}
	} 
}
