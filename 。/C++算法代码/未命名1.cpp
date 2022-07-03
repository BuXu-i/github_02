#include<iostream>
using namespace std;

int main (){
	int  a=56454897;
	string str=to_string(a);
	for(int i=0;i<str.size();i++){
		cout<<str[i]<<" ";
	}
}
