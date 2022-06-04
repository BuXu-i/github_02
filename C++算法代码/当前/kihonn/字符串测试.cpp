#include<iostream>
using namespace std;
int main () {
	string str="123ab";
	cout<<str<<endl;
	str.insert(1,"opi");
	cout<<str<<endl;
	str.erase(1,3);

	cout<<str;
}

