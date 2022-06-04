#include<graphics.h>
#include<conio.h>     //不按回车即直接输入数据进程序
#pragma comment(lib,"Winmm.lib")
#include"tou.h"
#include<Windows.h>
// 人物选择
int Z_x = 0, Z_y = 0, Y_x = 0, Y_y = 0,k=0,k_=0; 
//左人物移动 
 int Z_nei_y=0 , Z_nei_x=250;     //人物移动  x轴上  250 1000 250   y轴上 700
// 右人物移动
 int Y_nei_y=0, Y_nei_x=1106;
 //动画跳帧
 int YiDongFangXiang=0;
 int i = 0;  //人物帧的选择
 int Z_x_ = 0;// 真正的选择人物帧x输出
 int Y_x_ = 0;// 真正的x输出
 int k_s = 0;  //选人物速度慢点
 int k_s_ = 0;  //人物动画慢点
//初始化
void ChuShiHua() {
	initgraph(width + width_ren, high);   //初始化1500*700的画布 
	setbkcolor(WHITE);    //设置背景颜色
	cleardevice();    // 用背景色清空屏幕
	setlinestyle(PS_SOLID, 2);//宽度
	setcolor(RED);     //设置前景颜色//红
	line(width_ren / 2, 0, width_ren / 2, high);
	line(width_ren / 2 + width, 0, width_ren / 2 + width, high);
	line(0, 150, width_ren / 2, 150);
	line(0, 550, width_ren / 2, 550);
	line(width + width_ren / 2, 150, width+width_ren, 150);
	line(width + width_ren / 2, 550, width+width_ren, 550);
    //背景音乐
	mciSendString(L"open ./yinyue/ge.mp3 alias xunhuan", NULL, 0, NULL);//open 打开设备
	mciSendString(L"play xunhuan repeat", NULL, 0, NULL);// play 开始播放
	mciSendString(L"open ./yinyue/ge2.mp3 alias a", NULL, 0, NULL);//open 打开设备
	mciSendString(L"play a repeat", NULL, 0, NULL);// play 开始播放
	//背景
	IMAGE img_bk;
	loadimage(&img_bk, _T("./tupian/背景.jpg"),width,high);//实现了加载“IMAGE” img 对象 后面50，50是定义图片缩放大小,可省略
	putimage(width_ren / 2, 0,& img_bk);//坐标（300，150）处显示IMAGE对象
	BeginBatchDraw();
}
void test01() {
	ChuShiHua();

	while (1) {
		ShuRuGengXin();

		ZiDongGengXin();

		 HuaMianGengXin();
	}
	EndBatchDraw();
}
int  main() {
	
	test01();
	system("pause");
	return 0;
}