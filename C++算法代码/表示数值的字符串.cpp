#include<iostream>
using namespace std;
int main() {
	// write code here
	bool suu=false;//��
	bool tenn=false;//��
	bool fugou=false;//����
	bool Ee=false;//Ee
	bool siro=false;//�ո�
	string str="123";
	for(int i=0; i<str.size(); i++) {
		if(str[i]==' ') {//�ո���
			if(!siro) {
				siro=true;
				while(++i<str.size()) {
					if(str[i]!=' ') {
						--i;
						break;
					}
				}
				continue;
			}
			while(++i<str.size()) {//cout<<"�ǿո����Ƴ�����"<<":"<<str[i]<<":"<<endl;
				if(str[i]!=' ')
					return false;
			}
			break;
		} else if(str[i]>='0'&&str[i]<='9')
			suu=true;
		else if(str[i]=='-'||str[i]=='+') {
			if(suu||fugou) return false;//�Ѿ������ֻ���� ֱ�ӽ���
			fugou=true;
		} else if(str[i]=='.') {
			if(tenn) return false;//�Ѿ��С� ����
			tenn=true;
		} else if(str[i]=='e'||str[i]=='E') {
			if(!suu) return false;
			if(Ee) return false;
			Ee=true;
			tenn=true;
			fugou=false;
			suu=false;
		} else return false;
	}
	if(Ee)
		if(!suu)
			return false;
	if(suu)
		return true;
	else
		return false;
}

