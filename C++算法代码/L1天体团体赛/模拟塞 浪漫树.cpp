#include<iostream>
using namespace std;
#include<queue>
void fun2(int &a,int ap1[],int ap2[],int ap3[],int s,int ens,int enr) ;
//����     *       *       *  д������     ��ʼ��  ������  ������
void fun1(int &a,int ap1[],int ap2[],int ap3[],int s,int ens,int enr) {
	//������ ��һ�ε��յ�
	for(int i=ens; i<=enr; i++) {
		//	cout<<ap1[i]<<" ��������Ա� "<<ap2[a]<<endl;
		if(ap1[i]==ap2[a]) {
			ap3[s*2+2]=ap2[a];
		//	cout<<"z�ҵ���  ƥ���a:"<<a<<" ��ֵ:"<<ap2[a]<<" �ҵ���i:"<<i<<" ���� ens:"<<ens<<" enr:"<<enr<<" ֵ����:"<<s*2+2<<endl;
			a--;
			fun1(a,ap1,ap2,ap3,s*2+2,i+1,enr);
			fun2(a,ap1,ap2,ap3,s*2+2,ens,i-1);
			break;
		}
	}
}
void fun2(int &a,int ap1[],int ap2[],int ap3[],int s,int ens,int enr) {
	//������ ��һ�ε��յ�
	for(int i=ens; i<=enr; i++) {//������ʱֻ�ܵ��ϴθ��ڵ�֮ǰ
		if(ap1[i]==ap2[a]) {
			ap3[s*2+1]=ap2[a];
		//	cout<<"y�ҵ���  ƥ���a:"<<a<<" ��ֵ:"<<ap2[a]<<" �ҵ���i:"<<i<<" ���� ens:"<<ens<<" enr:"<<enr<<" ֵ����:"<<s*2+1<<endl;
			a--;
			fun1(a,ap1,ap2,ap3,s*2+1,i+1,enr);
			fun2(a,ap1,ap2,ap3,s*2+1,ens,i-1);
			break;
		}
	}
}
//�����˲� �������
void  ffun(int ap3[],deque<int>&deq) {
	int ki=deq.size();
	//cout<<"�˴θ���:"<<ki<<endl;
//	for(int i=0; i<ki; i++) {
		//cout<<"����:"<<deq[i]<<"  ��ֵ"<<ap3[deq[i]]<<" ";
//	}
//	cout<<endl;

	for(int i=0; i<ki; i++) {
		if(ap3[deq[0]*2+1]!=-1) {
			//cout<<"deq[0]:"<<deq[0]<<"  ����deq[0]*2+1:"<<deq[0]*2+1<<"   "<<ap3[deq[0]*2+1]<<endl;
			deq.push_back(deq[0]*2+1);
		}
		if(ap3[deq[0]*2+2]!=-1) {
			//cout<<"deq[0]:"<<deq[i]<<"  ����deq[0]*2+2:"<<deq[0]*2+2<<"   "<<ap3[deq[0]*2+2]<<endl;
			deq.push_back(deq[0]*2+2);
		}
		deq.pop_front();
	}

}
//�����д��±�
void fun(int &a,int &b,int ap1[],int ap2[],int ap3[],deque<int>&deq) {
	//��
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
	//��
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
	//������� �ó����
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
