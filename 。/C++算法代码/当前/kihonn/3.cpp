#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>
int main()
{
  // 请在此输入您的代码
  int s=0;
  string str="abcdefghiklmnoj";
  int ki;
  for(int i=0;i<str.length()-1;i++){
  	for(int j=0;j<str.length()-i;j++){
  		if(str[j+1]>str[j]){
  			swap(str[j+1],str[j]);
  			s++;
		  }
	  }
  }
  cout<<str<<" "<<s;
  return 0;
}
