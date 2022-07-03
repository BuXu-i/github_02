#include<iostream>
using namespace std;
#include<string>
#include<vector>
int main() {
	freopen("1.txt", "r", stdin);
	string s;
	cin >> s;
	vector<int>arr(127, -1);
	int sw = 0;
	int ki = 0;
	//优化空间很大  思路也很随便  
	for (int i = 0; i < (int)s.length(); i++) {
		if (arr[(int)s[i]] == -1) {
			arr[(int)s[i]] = i;
			ki++;
		} else {
			cout << "i:" << i << " sw:" << sw << " ki:" << ki << endl;
			sw = max(sw, ki);
			ki = i - arr[(int)s[i]];
			cout << "ki:" << ki << endl;
			for(int j=0;j<127;j++){
				if(arr[j]!=-1){
					arr[j]=-1;
				}
			}
			int op = ki;
			int j = i ;
			while (op--) {
				arr[s[j]] = j;
				j--;
				cout<<"*"<<" ";
			}
			cout<<endl;
		}
	}
	sw = max(sw, ki);
	cout << sw;
}
