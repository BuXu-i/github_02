#include<iostream>
using namespace std;
#include<algorithm>
struct student {
	char num[11];
	char name[11];
	int s1,s2,s3;
	int total;
};
int main() {
	int n;
	freopen("1.txt","r",stdin);
	cin>>n;
	student *arr[n];
	for(int i=0; i<n; i++) {
		arr[i]=new student();
		cin>>arr[i]->num>>arr[i]->name>>arr[i]->s1>>arr[i]->s2>>arr[i]->s3;
		arr[i]->total=arr[i]->s1+arr[i]->s2+arr[i]->s3;
	}
	int s=0;
	for(int i=0; i<n; i++) {
		if(arr[i]->total>arr[s]->total) {
			s=i;
		}
	}
	for(int i=0; i<n; i++) {
		
		if(arr[i]->total==arr[s]->total) {
			cout<<arr[i]->num<<" "<<arr[i]->name<<" "<<arr[i]->total;
		}
	}

	return 0;
}
