#include"tou.h"
void ShuRuGengXin() {
	int t = 2;
	if ((GetAsyncKeyState(0x41) & 0x8000)) {//a  ����
		Z_nei_x -= t;
		if (k >= 4) {
			Z_y = 720;

		}
		else {
			Z_y = 144;
		}
	}
	if (GetAsyncKeyState(0x44) & 0x8000) {  //d
		Z_nei_x += t;
		if (k >= 4) {
			Z_y = 864;
		}
		else {
			Z_y = 288;
		}
	}
	if (GetAsyncKeyState(0x57) & 0x8000) {//w
		Z_nei_y -= t;
		if (k >= 4) {
			Z_y = 1008;
		}
		else {
			Z_y = 432;
		}
	}
	if (GetAsyncKeyState(0x53) & 0x8000) {//s
		Z_nei_y += t;
		if (k >= 4) {
			Z_y = 576;
		}
		else {
			Z_y = 0;
		}
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000) {//�����
		Y_nei_x -= t;
		if (k_ >= 4) {
			Y_y = 720;
		}
		else {
			Y_y = 144;
		}

	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {//�ҷ����
		Y_nei_x += t;
		if (k_ >= 4) {
			Y_y = 864;
		}
		else {
			Y_y = 288;
		}
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000) {//�Ϸ����
		Y_nei_y -= t;
		if (k_ >= 4) {
			Y_y = 1008;
		}
		else {
			Y_y = 432;
		}
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000) {//�·����
		Y_nei_y += t;
		if (k_ >= 4) {
			Y_y = 576;
		}
		else {
			Y_y = 0;
		}
	}

	//��ͣ��
	if (GetAsyncKeyState(0x50) & 0x8000) {   //p

	}
	//if (GetAsyncKeyState(0x49) & 0x8000) {   //i

	//}
	//����Ƹ�������

	if (GetAsyncKeyState(0x55) & 0x8000) {   //u 
		if (k_s == 4) {   //�����ٶ�
			if (k == 7) { //8��ѡ���������
				k = 0;
				Z_x = 0;
				/* ��������� �������� y��  */
				Z_y = 0;
			}
			else {    //ѡ��δ��8��
				k++;
				if (k == 4) {   //��������ѡ��
					Z_x = 0;
					/* ��������� �������� y��  */
					Z_y = 576;

				}
				else
					Z_x += 432;    // ��ǰ������ѡ��
			}
			k_s = 0;   //�����ٶȼ�ʱ��
		}
		else
			k_s++;     //�ٶȼ�ʱ��
	}
	//�ҿ��ƻ�����
	if (GetAsyncKeyState(0x49) & 0x8000) {   //   i
		if (k_s == 3) {   //�����ٶ�
			if (k_ == 7) {
				k_ = 0;
				Y_x = 0;
				/* ��������� �������� y��  */
				Y_y = 0;
			}
			else {
				k_++;
				if (k_ == 4) {
					Y_x = 0;
					/* ��������� �������� y��  */
					Y_y = 576;
				}
				else
					Y_x += 432;
			}
			k_s = 0;
		}
		else
			k_s++;
	}
}