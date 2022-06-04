#include<iostream>
using namespace std;
int add(int num1,int num2){
        int yihuo;
        while(num2){
            yihuo=num1^num2;
            num2=(num1&num2)<<1;
            num1=yihuo;
        }
        return num1;
} 
int main(){
	int num1=3;
	int num2=5;
	cout<<add(num1,num2)<<endl;
}
