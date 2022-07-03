#include<iostream>
using namespace std;
int main() {
	// write code here
	bool suu=false;//数
	bool tenn=false;//点
	bool fugou=false;//符号
	bool Ee=false;//Ee
	bool siro=false;//空格
	string str="123";
	for(int i=0; i<str.size(); i++) {
		if(str[i]==' ') {//空格处理
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
			while(++i<str.size()) {//cout<<"非空格导致推出！！"<<":"<<str[i]<<":"<<endl;
				if(str[i]!=' ')
					return false;
			}
			break;
		} else if(str[i]>='0'&&str[i]<='9')
			suu=true;
		else if(str[i]=='-'||str[i]=='+') {
			if(suu||fugou) return false;//已经有数字或符号 直接结束
			fugou=true;
		} else if(str[i]=='.') {
			if(tenn) return false;//已经有· 结束
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

