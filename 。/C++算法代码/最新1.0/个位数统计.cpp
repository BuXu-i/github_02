#include<iostream>
using namespace std;
int main() {
	freopen("1.txt", "r", stdin);
	string str;
	int arr[10]={0};
	cin>>str;
	for (int i = 0; i < str.size(); i++) {
		arr[str[i] - '0']++;
	//	cout<<arr[str[i] - '0']<<endl;
	}
	int i = 0;
	for (; i < 10; i++) {
		if (arr[i] != 0) {
			cout << i << ":" << arr[i];
			break;
		}
	}
	for (i++; i < 10; i++) {
		if (arr[i] != 0) {
			cout<<endl;
			cout << i << ":" << arr[i];
		}
	}
}
