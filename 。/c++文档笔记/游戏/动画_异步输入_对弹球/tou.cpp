#include<graphics.h>
#include<conio.h>     //�����س���ֱ���������ݽ�����
#pragma comment(lib,"Winmm.lib")
#include"tou.h"
#include<Windows.h>
// ����ѡ��
int Z_x = 0, Z_y = 0, Y_x = 0, Y_y = 0,k=0,k_=0; 
//�������ƶ� 
 int Z_nei_y=0 , Z_nei_x=250;     //�����ƶ�  x����  250 1000 250   y���� 700
// �������ƶ�
 int Y_nei_y=0, Y_nei_x=1106;
 //������֡
 int YiDongFangXiang=0;
 int i = 0;  //����֡��ѡ��
 int Z_x_ = 0;// ������ѡ������֡x���
 int Y_x_ = 0;// ������x���
 int k_s = 0;  //ѡ�����ٶ�����
 int k_s_ = 0;  //���ﶯ������
//��ʼ��
void ChuShiHua() {
	initgraph(width + width_ren, high);   //��ʼ��1500*700�Ļ��� 
	setbkcolor(WHITE);    //���ñ�����ɫ
	cleardevice();    // �ñ���ɫ�����Ļ
	setlinestyle(PS_SOLID, 2);//���
	setcolor(RED);     //����ǰ����ɫ//��
	line(width_ren / 2, 0, width_ren / 2, high);
	line(width_ren / 2 + width, 0, width_ren / 2 + width, high);
	line(0, 150, width_ren / 2, 150);
	line(0, 550, width_ren / 2, 550);
	line(width + width_ren / 2, 150, width+width_ren, 150);
	line(width + width_ren / 2, 550, width+width_ren, 550);
    //��������
	mciSendString(L"open ./yinyue/ge.mp3 alias xunhuan", NULL, 0, NULL);//open ���豸
	mciSendString(L"play xunhuan repeat", NULL, 0, NULL);// play ��ʼ����
	mciSendString(L"open ./yinyue/ge2.mp3 alias a", NULL, 0, NULL);//open ���豸
	mciSendString(L"play a repeat", NULL, 0, NULL);// play ��ʼ����
	//����
	IMAGE img_bk;
	loadimage(&img_bk, _T("./tupian/����.jpg"),width,high);//ʵ���˼��ء�IMAGE�� img ���� ����50��50�Ƕ���ͼƬ���Ŵ�С,��ʡ��
	putimage(width_ren / 2, 0,& img_bk);//���꣨300��150������ʾIMAGE����
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