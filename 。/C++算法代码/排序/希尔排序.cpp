#include<iostream>
using namespace std;
//ϣ������  ����˵�ǲ��������������
//1.��������ʱЧ�ʸ�
// ----ԭ�� ----
//�����������
// �ȷ��� ��ÿ����в�������
//������ѡ��  ���и��� / 3 + 1 ;
//ÿһ�ν��в�������
int main() {
	int increasement = 10;
	int i, j, k;
	int arr[10] = { 5,9,6,3,77,8,94,5,1,6 };
	do {
		increasement = increasement / 3 + 1;    //ȷ���������� ��С
		for (i = 0; i < increasement; i++) {    //ȷ�����������Ԫ��,increasement����򼸸�Ϊһ��
			for (j = i + increasement; j < 10; j += increasement) {   //j=i+increasement j��ʾ����ĵڶ���
				if (arr[j] < arr[j - increasement]) {    //�ڶ����͵�һ���Ƚ�
					int temp = arr[j];   //��С���ó����������Ǵ��
					for (k = j - increasement; k >= 0 && temp < arr[k]; k -= increasement) {
						arr[k + increasement] = arr[k];
					}
					arr[k + increasement] = temp;     //�����arr����Ϊarr��k��;
				}
			}
		}
	} while (increasement > 1);
	for (i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}
