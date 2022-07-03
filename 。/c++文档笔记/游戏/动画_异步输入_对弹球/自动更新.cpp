#include"tou.h"
void ZiDongGengXin() {
	if (k_s_ == 8) {    //速度计时器
		if (i == 3) {  // 换到第一帧
			i = 0;
		}
		Z_x_ = Z_x + 144 * i;
		Y_x_ = Y_x + 144 * i;
		k_s_ = 0;
		i++;	    // 下一帧
	}
	else {
		k_s_++;
	}
}
