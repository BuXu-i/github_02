#include<iostream>
using namespace std;
#include<algorithm>
int main(){
    int n;
    cin>>n;
    int a,b,c;
    int ki=0,ski=-10000,op;
    while(n--){
        cin>>op>>a>>b>>c;
        a=a*3+b-c;
        if(a>ski){
            ski=a;
            ki=op;
        }
      //  cout<<"·ÖÊý= "<<a<<" ±àºÅ="<<op<<endl; 
    }
    cout<<ki;
    return 0;
}
