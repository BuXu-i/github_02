#include<iostream>
using namespace std;
#include<vector>
    vector<int> FindGreatestSumOfSubArray(vector<int>& array) {
        // write code here
        int mx = 0x80000000;
        int suu,s=0;
        for(int i = 0; i < array.size(); ++i){
            s = max(s + array[i], array[i]);
            if(s>=mx){
                suu=i;
                mx=s;
            }
        }
        s=array[suu];
        vector<int>arr;//�����������Ƿ��к�Ϊ����� ������������ĳ���
        for(int i=suu-1;true;i--){
            if(mx!=s){
                s+=array[i];
            }
            else {
                //�������� //ֻ��ȷ���Ƿ�Ҫ����
                int Li=i++;
                int Ri=1+suu;
                int  ki=0;
                while(Li>=0){
                    ki+=array[Li--];
                    if(ki==0){
                        i=Li+1;
                    }
                }
                ki=0;
                //��������
                while(Ri<array.size()){
                    ki+=array[Ri++];
                    if(ki==0){
                        suu=Ri-1;
                    }
                }
                while(i!=suu+1){
                    arr.push_back(array[i++]);
                }
                return arr;
            }
        }
    }//1 -2 3 10 -4 7 2 -5
int main() {
	vector<int>arr;
	int x;
	for(int i=0;i<11;i++){
		cin>>x;
		arr.push_back(x);
	}
	arr=FindGreatestSumOfSubArray(arr);
	for(int i=0;i<arr.size();i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
