#include<iostream>
using namespace std;

bool match(string str, string pattern) {
	// write code here
	int k=0;//ƥ���ַ����ѵ����±�
	int suu=0;//����ʹ��
	char suuji;
	if(str.size()==0&&pattern.size()==0) return true;
	if(pattern.size()==0) return false;
	for(int i=0; i<pattern.size(); i++) {
		if(pattern[i]!='.') { //�Ǻ�ǰ�϶�����ĸ
			if(i+1<pattern.size()&&pattern[i+1]=='*'&&pattern[i]!='*') {//����Ϊ�Ǻ�
				//��ʼ����str��
				while(k<str.size()&&str[k]==pattern[i]) {
					k++;
					suu++;//���� ����������ͬ��ĸ
				}
				suuji=pattern[i];//��¼��Ӧ���� ������ʽ����ĸ
				i++;//�漰���˺���һ�� �Ǻ�
			} else if(k<str.size()&&str[k]==pattern[i]) { //����ĸΪ���� //while ����������������ͬ����ĸ
				k++;//��ǰ��һλ
				suu=0;//��������
				suuji=' ';//��ĸ���
			} else if(k==str.size()&&str[k-1]==suuji&&suu>0) {
				suu--;//����������һλ  ������Ҫ����
			} else if(pattern[i]=='*')
				continue;
			else {
				cout<<k<<" "<<i<<endl;
				return false;
			}
		} else if((i+1)<pattern.size()&&pattern[i+1]=='*') {
			return 1;
		} else { //��ŵ�ƥ��  if(pattern[i]=='.')
			if(k<str.size()&&suu!=0&&str[k]!=str[k-1]) {
				k++;
				suu=0;//��������
				suuji=' ';//��ĸ���
			} else if(k<str.size()&&suu!=0&&str[k]==str[k-1]) {
				suu--;
				k++;
			} else if(k<str.size()) {
				k++;
			} else {
				return false;
				cout<<"������� "<<k<<" "<<i<<endl;
			}

		}
	}
	return true; //kannbi�����߹���ȫ��
}
int main() {
	string str,patt;
	freopen("./���ݶ�ȡ.txt","r",stdin);
	cin>>str>>patt;
	cout<<match(str,patt)<<endl;;
}
