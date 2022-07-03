#include<iostream>
using namespace std;
#include<vector>
vector<int> FindNumsAppearOnce(vector<int>& array) {
	// write code here
	int ab=0;
	for(int i=0; i<array.size(); i++) {
		ab^=array[i];

	}
	cout<<"ab="<<ab<<endl;
	int k=1;
	bool ki=1;
	while(!(k&ab)) {
		k=k<<1;
	}
	cout<<"k="<<k<<endl;
	int a=0,b=0;
	for(int i=0; i<array.size(); i++) {
		if(k&array[i]) {
			a^=array[i];
		} else {
			b^=array[i];
		}
	}
	cout<<"a="<<a<<" b="<<b<<endl;
	array.clear();
	if(a>=b) {
		array.push_back(b);
		array.push_back(a);
	} else {
		array.push_back(a);
		array.push_back(b);
	}
	return array;
}
int main() {
	int arrt[4]= {1,4,1,6};
	vector<int>arr(arrt,arrt+4);
	FindNumsAppearOnce(arr);
	cout<<arr[0]<<" "<<arr[1]<<endl;
	return 0;
}

