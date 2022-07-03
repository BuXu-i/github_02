#include<iostream>
using namespace std;
#include<vector>
int sw=0;
void dfs(vector<int>&arr,int le ,int ri){
    int ki,ks=10000;
    for(int i=le;i<ri;i++){
        if(ks>arr[i]){
            ks=arr[i];
            ki=i;
        }
    }
    sw+=ks;
    for(int i=le;i<ri;i++){
        arr[i]-=ks;
    }
    if(ki-1>=le)
        dfs(arr,le,ki-1);
    if(ri>=ki+1)
        dfs(arr, ki+1,ri);
}
int main (){
    int n,x;
    cin>>n;
    vector<int>arr(n);
    int a=0,amin;
    for(int i=0;i<n;i++){
        cin>>x;
        arr[i]=x;
    }
    dfs(arr, 0, n);
    cout<<sw;
}
