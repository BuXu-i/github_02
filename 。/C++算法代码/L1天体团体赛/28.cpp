#include<iostream>
using namespace std;

int main(){
    int n;
    int ki;
    cin>>n;
    ki=n*n-n+1;
    cout<<n<<"*"<<n<<"*"<<n<<"="<<n*n*n<<"=";
    while(n--){
        cout<<ki;
        ki++;
        if(n!=0)cout<<"+";
    }
    return 0;
}
