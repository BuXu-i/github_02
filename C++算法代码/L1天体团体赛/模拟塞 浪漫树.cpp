#include<iostream>
using namespace std;
#include<queue>
void fun2(int &a,int ap1[],int ap2[],int ap3[],int s,int ens,int enr) ;
//遍历     *       *       *  写入坐标     起始点  左区间  右区间
void fun1(int &a,int ap1[],int ap2[],int ap3[],int s,int ens,int enr) {
	//向右找 上一次的终点
	for(int i=ens; i<=enr; i++) {
		//	cout<<ap1[i]<<" 左右两侧对比 "<<ap2[a]<<endl;
		if(ap1[i]==ap2[a]) {
			ap3[s*2+2]=ap2[a];
		//	cout<<"z找到了  匹配点a:"<<a<<" 其值:"<<ap2[a]<<" 找到点i:"<<i<<" 区间 ens:"<<ens<<" enr:"<<enr<<" 值给了:"<<s*2+2<<endl;
			a--;
			fun1(a,ap1,ap2,ap3,s*2+2,i+1,enr);
			fun2(a,ap1,ap2,ap3,s*2+2,ens,i-1);
			break;
		}
	}
}
void fun2(int &a,int ap1[],int ap2[],int ap3[],int s,int ens,int enr) {
	//向右找 上一次的终点
	for(int i=ens; i<=enr; i++) {//向左找时只能到上次根节点之前
		if(ap1[i]==ap2[a]) {
			ap3[s*2+1]=ap2[a];
		//	cout<<"y找到了  匹配点a:"<<a<<" 其值:"<<ap2[a]<<" 找到点i:"<<i<<" 区间 ens:"<<ens<<" enr:"<<enr<<" 值给了:"<<s*2+1<<endl;
			a--;
			fun1(a,ap1,ap2,ap3,s*2+1,i+1,enr);
			fun2(a,ap1,ap2,ap3,s*2+1,ens,i-1);
			break;
		}
	}
}
//遍历此层 存入队列
void  ffun(int ap3[],deque<int>&deq) {
	int ki=deq.size();
	//cout<<"此次个数:"<<ki<<endl;
//	for(int i=0; i<ki; i++) {
		//cout<<"坐标:"<<deq[i]<<"  其值"<<ap3[deq[i]]<<" ";
//	}
//	cout<<endl;

	for(int i=0; i<ki; i++) {
		if(ap3[deq[0]*2+1]!=-1) {
			//cout<<"deq[0]:"<<deq[0]<<"  存入deq[0]*2+1:"<<deq[0]*2+1<<"   "<<ap3[deq[0]*2+1]<<endl;
			deq.push_back(deq[0]*2+1);
		}
		if(ap3[deq[0]*2+2]!=-1) {
			//cout<<"deq[0]:"<<deq[i]<<"  存入deq[0]*2+2:"<<deq[0]*2+2<<"   "<<ap3[deq[0]*2+2]<<endl;
			deq.push_back(deq[0]*2+2);
		}
		deq.pop_front();
	}

}
//队列中存下表
void fun(int &a,int &b,int ap1[],int ap2[],int ap3[],deque<int>&deq) {
	//左
	//cout<<"?";
	if(deq.size()==0) {
		return ;
	}
	for(int i=0; i<deq.size(); i++) {
		if(ap3[deq[i]*2+1]!=-1) {
			ap1[a]=ap3[deq[i]*2+1];
			a++;
			break;
		} else if(ap3[deq[i]*2+2]!=-1) {
			ap1[a]=ap3[deq[i]*2+2];
			a++;
			break;
		}
	}
	//右
	for(int i=deq.size()-1; i>=0; i--) {
		if(ap3[deq[i]*2+2]!=-1) {
			ap2[b]=ap3[deq[i]*2+2];
			b++;
			break;
		} else if(ap3[deq[i]*2+1]!=-1) {
			ap2[b]=ap3[deq[i]*2+1];
			b++;
			break;
		}
	}
	//cout<<a<<" "<<b<<endl;
	ffun(ap3,deq);
	fun(a,b,ap1,ap2,ap3,deq);
}
int main () {
	freopen("1.txt","r",stdin);
	int n;
	cin>>n;
	int ap1[n],ap2[n],ap3[10000];
	for(int i=0; i<10000; i++) {
		ap3[i]=-1;
	}
	for(int i=0; i<n; i++) {
		cin>>ap1[i];
	}
	for(int i=0; i<n; i++) {
		cin>>ap2[i];
	}
	int ki;
	for(int i=0; i<n; i++) {
		if(ap1[i]==ap2[n-1]) {
			ap3[0]=ap1[i];
			ki=i;
			break;
		}
	}
	int a=n-2;
	fun1(a,ap1,ap2,ap3,0,ki+1,n-1);
	fun2(a,ap1,ap2,ap3,0,0,ki-1);
	//cout<<ap2[-1]<<endl;
//	for(int i=0; i<22; i++) {
//		if(ap3[i]!=-1)
//			cout<<ap3[i]<<" ";
//	}
	//层序遍历 得出结果
	deque<int>deq;
	int b=1;
	a=1;
	ap1[0]=ap2[0]=ap3[0];
	deq.push_back(0);
	fun(a,b,ap1,ap2,ap3,deq);	
    cout<<"R: ";
    for(int i=0; i<b; i++) {
		cout<<ap2[i];
        if(i!=b-1)cout<<" ";
	}cout<<endl;
    cout<<"L: ";
	for(int i=0; i<a; i++) {
		cout<<ap1[i];
        if(i!=a-1)cout<<" ";
	}
	

}
