#include <iostream>
using namespace std;
int arr[102][102];
int main()
{
  // 请在此输入您的代码
  int n;
  cin>>n;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=i;j++){
      cin>>arr[i][j];
    }
  }
  for(int i=n-1;i>=1;i--){
    for(int j=1;j<=i;j++){
      arr[i][j]+=max(arr[i+1][j],arr[i+1][j+1]);
    }
  }
  cout<<arr[1][1];
  return 0;
}
