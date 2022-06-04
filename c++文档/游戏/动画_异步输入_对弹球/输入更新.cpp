#include"tou.h"
void ShuRuGengXin() {
	int t = 2;
	if ((GetAsyncKeyState(0x41) & 0x8000)) {//a  向左
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
	if (GetAsyncKeyState(VK_LEFT) & 0x8000) {//左方向键
		Y_nei_x -= t;
		if (k_ >= 4) {
			Y_y = 720;
		}
		else {
			Y_y = 144;
		}

	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {//右方向键
		Y_nei_x += t;
		if (k_ >= 4) {
			Y_y = 864;
		}
		else {
			Y_y = 288;
		}
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000) {//上方向键
		Y_nei_y -= t;
		if (k_ >= 4) {
			Y_y = 1008;
		}
		else {
			Y_y = 432;
		}
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000) {//下方向键
		Y_nei_y += t;
		if (k_ >= 4) {
			Y_y = 576;
		}
		else {
			Y_y = 0;
		}
	}

	//暂停键
	if (GetAsyncKeyState(0x50) & 0x8000) {   //p

	}
	//if (GetAsyncKeyState(0x49) & 0x8000) {   //i

	//}
	//左控制更换人物

	if (GetAsyncKeyState(0x55) & 0x8000) {   //u 
		if (k_s == 4) {   //控制速度
			if (k == 7) { //8号选择完后运行
				k = 0;
				Z_x = 0;
				/* 换排人物后 立即更新 y轴  */
				Z_y = 0;
			}
			else {    //选择还未到8号
				k++;
				if (k == 4) {   //另排人物选择
					Z_x = 0;
					/* 换排人物后 立即更新 y轴  */
					Z_y = 576;

				}
				else
					Z_x += 432;    // 当前排人物选择
			}
			k_s = 0;   //重置速度计时器
		}
		else
			k_s++;     //速度计时器
	}
	//右控制换人物
	if (GetAsyncKeyState(0x49) & 0x8000) {   //   i
		if (k_s == 3) {   //控制速度
			if (k_ == 7) {
				k_ = 0;
				Y_x = 0;
				/* 换排人物后 立即更新 y轴  */
				Y_y = 0;
			}
			else {
				k_++;
				if (k_ == 4) {
					Y_x = 0;
					/* 换排人物后 立即更新 y轴  */
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