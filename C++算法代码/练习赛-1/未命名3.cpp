#include<iostream>
using namespace std;
#include<algorithm> 
int main(){
	freopen("1.txt","r",stdin);
	double ki=0;
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		ki+=arr[i];
	}
	ki=ki/n;
	int s=0;
	for(int i=0;i<n;i++){
		if(arr[i]>ki){
			s++;
		}
	}
	printf("%.2f",ki);
	cout<<endl<<s;
	return 0;
} 
