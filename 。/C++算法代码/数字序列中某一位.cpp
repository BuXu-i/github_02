#include<iostream>
using namespace std;
#include<math.h>
int findNthDigit(int n) {
	// write code here
	long suu=9;//9-0+1
	int k=2,ju=10;
	while(n>suu) {
		suu+=(9*ju*k);
		cout<<"k位下:"<<k<<" 0到suu位数和："<<suu<<endl;
		ju*=10;
		k++;
	}
	k--;
	ju=ju-1;
	cout<<ju<<endl;
	cout<<suu<<endl;
	cout<<"当前数字有几位："<<k<<endl; //这里位数出错
	for(int i=ju; true; i--,suu-=k) { //ju=9  suu=10  //ju=0 suu=1 n=1
		if(n>=suu) { //i是当前的数字
			cout<<"n "<<n<<" suu "<<suu<<endl;
			if(n==suu) {
				return i%10;
			}
			cout<<"i "<<i<<endl;
			if(0) {  //n=0  i=0 suu=0
				suu+=k;
				i++;
				cout<<"我增加了"<<endl;
			}
			cout<<"n "<<n<<" suu "<<suu<<endl;
			cout<<"i "<<i<<endl;
			ju=n-suu;//第几位
			cout<<"i的第几位"<<ju<<"  i值 "<<i+1<<endl;
			i++;
			//把i中第ju位拿出来返回即可  从左数到右 高位第一
			cout<<"当前数字有几位："<<k<<endl; //这里位数出错
			k=pow(10,k-ju+1);
			cout<<"k="<<k<<"  i="<<i<<endl;//1234/100
			i%=k;
			i/=k/10;
			cout<<"标记"<<endl;
			cout<<"i jieguo "<<i<<endl;
			return i;
		}
	}
}
int main () {
	cout<<findNthDigit(1000000000);//1000000000 5/7 预期输出都是1
	return 0;
}
