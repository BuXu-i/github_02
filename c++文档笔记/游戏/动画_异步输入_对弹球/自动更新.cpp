#include"tou.h"
void ZiDongGengXin() {
	if (k_s_ == 8) {    //�ٶȼ�ʱ��
		if (i == 3) {  // ������һ֡
			i = 0;
		}
		Z_x_ = Z_x + 144 * i;
		Y_x_ = Y_x + 144 * i;
		k_s_ = 0;
		i++;	    // ��һ֡
	}
	else {
		k_s_++;
	}
}
