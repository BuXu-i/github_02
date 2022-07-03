#include<iostream>
using namespace std;
#include<math.h>
long long s = 1 ; //×î³¤
string str;
void fun(long long nki, long long i) {
	string sstr;
	long long kp = 1;
	while (1) {
		//TODO
		sstr += to_string(i) + "*";
		i++;
		if (nki % i == 0) {
			nki = nki / i;
			kp++;
		} else break;
	}
	if (kp > s) {
		s = kp;
		str = sstr;
	}
}
int main() {
	//freopen("1.txt", "r", stdin);
	long long n;
	cin >> n;
	//cout<<pow(2,4)<<endl;
	str = to_string(n) + "*";
    long long op=sqrt(n)+1;
	for (long long i = 2; i < op; i++) {
		if (n % i == 0) {
			fun(n, i);
		}
	}
	str[str.size() - 1] = NULL;
	cout << s << endl << str;
}
