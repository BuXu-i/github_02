#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
//https://www.nowcoder.com/practice/11ae12e8c6fe48f883cad618c2e81475?tpId=196&tqId=37176&rp=1&ru=/exam/oj&qru=/exam/oj&sourceUrl=%2Fexam%2Foj%3Ftab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D196%26page%3D1&difficulty=undefined&judgeStatus=undefined&tags=&title=
int main() {
	string s, t, arr3, p;
	bool ki = 0;
	cin >> s>>t;
	if (s.size() < t.size()) {
		arr3 = s;
		s = t;
		t = arr3;
		arr3 = "";
	}
	//cout<<"1asdas"<<endl;
	int k = t.size();//终点是短的 arr2
	int kp=s.size() - k;//多出的长度
	//cout<<s.size()<<" "<<t.size()<<" "<<k<<endl;
	for (int i = k - 1; i >= 0; i--) { //对齐问题   最大位  加一问题 两个等长度  时  没有 可以加选项
		if (s[i+kp] + t[i]-'0' >= '9'+1) {      //判断有问题  未进入 过   ！！！  ok
			ki = 1;
			p = s[i+kp] + t[i] - '9'-1;
			//	cout<<"bu是asdas "<<p<<" "<<i<<endl;
		} else {
			//	cout<<"bu不asdas "<<p<<" "<<i<<endl;
			p = s[i+kp] + t[i]-'0';
		}
		if (ki&&(i-1+kp>=0)) { //判断 前面是不是还可以加  不可以加时  ki为置0  后期面可以处理    ok
			s[i - 1+kp] += 1;//长的数组前先加1 而不是存起来   ok
			ki = 0;
		}
		//	cout<<"p:"<<p<<"ki:"<<ki<<endl;;
		p.append(arr3);
		arr3 = p;
		p = "";
	}
	//9 99999999999999999999999999999999999999999999999999999999999994
	//cout<<"2asdas"<<" "<<arr3<<endl;
	//完成最后的
	if(ki) {
		p='1';
	} else {
		p.append(s, 0,s.size() - k);
		//cout<<"asdas"<<endl;
		//扫一遍？？
	}
	p += arr3;
	for(int i=p.size(); i>=0; i--) {
		if(p[i]>'9'&&i-1>=0) {
			p[i]='0';
			p[i-1]+=1;
		} else if(p[i]>'9'&&i-1<0) {
			p[0]='0';
			p='1'+p;
		}
	}
	cout << p << endl;
	return 0;
}
