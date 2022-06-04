#include"tou.h"
void HuaMianGengXin() {
	//左人物  //放大4倍  ,1728,1152
	IMAGE beijing;
	IMAGE renwu;
	loadimage(&renwu, _T("./tupian/人物行走.jpg"), 1728, 1152);//实现了加载“IMAGE” img 对象 后面50，50是定义图片缩放大小,可省略	
	loadimage(&beijing, _T("./tupian/背景.jpg"), width, high);//实现了加载“IMAGE” img 对象 后面50，50是定义图片缩放大小,可省略		
	putimage(width_ren / 2, 0, &beijing);//坐标（300，150）处显示IMAGE对象														//画面更新  左
	putimage(50, 260, 144, 144, &renwu, Z_x_, Z_y);//坐标（300，150）处显示IMAGE对象
	putimage(Z_nei_x, Z_nei_y, 144, 144, &renwu, Z_x_, Z_y);//坐标（300，150）处显示IMAGE对象
	//画面更新  右
	putimage(width + width_ren / 2 + 50, 260, 144, 144, &renwu, Y_x_, Y_y);//坐标（300，150）处显示IMAGE对象
	putimage(Y_nei_x, Y_nei_y, 144, 144, &renwu, Y_x_, Y_y);//坐标（300，150）处显示IMAGE对象
		//背景
	FlushBatchDraw();
}