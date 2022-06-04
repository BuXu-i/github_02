#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ki=1;
    int s=0;
    int i=1;
    while(n>=i){
        ki=i*ki;
        s+=ki;
        cout<<ki<<" ";
        i++;
    }
    cout<<ki;
}
