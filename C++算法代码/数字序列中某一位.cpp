#include<iostream>
using namespace std;
#include<math.h>
int findNthDigit(int n) {
	// write code here
	long suu=9;//9-0+1
	int k=2,ju=10;
	while(n>suu) {
		suu+=(9*ju*k);
		cout<<"kλ��:"<<k<<" 0��suuλ���ͣ�"<<suu<<endl;
		ju*=10;
		k++;
	}
	k--;
	ju=ju-1;
	cout<<ju<<endl;
	cout<<suu<<endl;
	cout<<"��ǰ�����м�λ��"<<k<<endl; //����λ������
	for(int i=ju; true; i--,suu-=k) { //ju=9  suu=10  //ju=0 suu=1 n=1
		if(n>=suu) { //i�ǵ�ǰ������
			cout<<"n "<<n<<" suu "<<suu<<endl;
			if(n==suu) {
				return i%10;
			}
			cout<<"i "<<i<<endl;
			if(0) {  //n=0  i=0 suu=0
				suu+=k;
				i++;
				cout<<"��������"<<endl;
			}
			cout<<"n "<<n<<" suu "<<suu<<endl;
			cout<<"i "<<i<<endl;
			ju=n-suu;//�ڼ�λ
			cout<<"i�ĵڼ�λ"<<ju<<"  iֵ "<<i+1<<endl;
			i++;
			//��i�е�juλ�ó������ؼ���  ���������� ��λ��һ
			cout<<"��ǰ�����м�λ��"<<k<<endl; //����λ������
			k=pow(10,k-ju+1);
			cout<<"k="<<k<<"  i="<<i<<endl;//1234/100
			i%=k;
			i/=k/10;
			cout<<"���"<<endl;
			cout<<"i jieguo "<<i<<endl;
			return i;
		}
	}
}
int main () {
	cout<<findNthDigit(1000000000);//1000000000 5/7 Ԥ���������1
	return 0;
}
