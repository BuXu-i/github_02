#include<iostream>
using namespace std;
#include<map>

int main(){
	map<int,string>maps;
	maps[12]="123";
	maps[12]="qwe";
	maps[11]="qwe7";
	cout<<maps.count(12)<<endl;
	cout<<maps.erase(11)<<endl;
	cout<<maps[11]<<endl;
	cout<<maps.size()<<" "<<endl;
	return 0;
}
