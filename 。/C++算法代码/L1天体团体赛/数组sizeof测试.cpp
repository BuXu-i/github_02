#include<iostream>
using namespace std;
void fun(int *arr){
	cout<<sizeof(arr)/sizeof(arr[0])<<endl;
	for(int i=0;i<6;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
} 
int main (){
	
	int arr[5]={1,2,3,4,5};
	cout<<sizeof(arr)/sizeof(arr[0])<<endl;
	fun(arr);
	return 0;
}
