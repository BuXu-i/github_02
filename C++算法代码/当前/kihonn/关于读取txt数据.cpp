#include<iostream>
using namespace std;
#include<math.h>
#include<vector>
#include<algorithm>
int fun(int a,int b,int c){
    double q=(a+b+c)/2;
    q=sqrt(q*(q-a)*(q-b)*(q-c));
    return q;
}
int main (){
    int n;
    cin>>n;
    double x;
    double s;
    vector<double>arr;
    vector<double>abc(3);
    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());
    abc[0]=arr[0];
    abc[1]=arr[1];
    abc[2]=arr[2];
    for(int i=3;i<n;i++){
        if(abc[0]+abc[1]>abc[2]){
            s=max(fun(abc[0],abc[1],abc[2]), s);
        }
    }
    return 0;
}











