#include"tou.h"
void HuaMianGengXin() {
	//������  //�Ŵ�4��  ,1728,1152
	IMAGE beijing;
	IMAGE renwu;
	loadimage(&renwu, _T("./tupian/��������.jpg"), 1728, 1152);//ʵ���˼��ء�IMAGE�� img ���� ����50��50�Ƕ���ͼƬ���Ŵ�С,��ʡ��	
	loadimage(&beijing, _T("./tupian/����.jpg"), width, high);//ʵ���˼��ء�IMAGE�� img ���� ����50��50�Ƕ���ͼƬ���Ŵ�С,��ʡ��		
	putimage(width_ren / 2, 0, &beijing);//���꣨300��150������ʾIMAGE����														//�������  ��
	putimage(50, 260, 144, 144, &renwu, Z_x_, Z_y);//���꣨300��150������ʾIMAGE����
	putimage(Z_nei_x, Z_nei_y, 144, 144, &renwu, Z_x_, Z_y);//���꣨300��150������ʾIMAGE����
	//�������  ��
	putimage(width + width_ren / 2 + 50, 260, 144, 144, &renwu, Y_x_, Y_y);//���꣨300��150������ʾIMAGE����
	putimage(Y_nei_x, Y_nei_y, 144, 144, &renwu, Y_x_, Y_y);//���꣨300��150������ʾIMAGE����
		//����
	FlushBatchDraw();
}