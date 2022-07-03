#include <iostream>
using namespace std;
int mian (){
    int t,n;
    cin>>n>>t;
    int x=1,y=1;
    for(int i=0;i<t;i++){
        y++;
        if(y==n){
            y=1;
            x++;
        }
        if(x==n){
            x=1;
        }
    }
    cout<<x<<" "<<y;
    return 0;
}
