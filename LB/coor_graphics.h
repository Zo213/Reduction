#ifndef COOR_GRAPGICS_H
#define COOR_GRAPHICS_H

#include<graphics.h>


#define UNIT_X 2    //X�ᵥλ���� 
#define UNIT_Y 20     //Y�ᵥλ���� 
#define FREE_SPACE 20     //����ϵ�Ͽ���ռ� 
#define SIGN 5          //X���ǵ�߶� 


class COORDINATE_SYS {               //��������ϵ����
private:
	int Ori_x;                                   // ����ϵԭ��ĺ�����
	int Ori_y;                                   //����ϵԭ���������
	int Len_x;                                  //����ϵ������߼�����
	int Len_y;                                  //������������߼�����

public:


	COORDINATE_SYS(double L_X, double L_Y, int O_X, int O_Y)        // ���캯��
	{
		Ori_x = O_X;
		Ori_y = O_Y;
		Len_x = L_X;
		Len_y = L_Y;
	}

	void show()                                       //��������ϵ
	{
		setlinecolor(BLACK);                       //���û�����ɫ
		moveto(Ori_x, Ori_y);                    //��������ϵԭ��Ϊ��ǰ��
		lineto(Ori_x + Len_x*UNIT_X + FREE_SPACE * 2, Ori_y);   //����ʵ�ʳ��ȵ�������

																//**********************************************************************
		lineto(Ori_x + Len_x*UNIT_X + FREE_SPACE * 2 - 5, Ori_y + 5);                              //*
		moveto(Ori_x + Len_x*UNIT_X + FREE_SPACE * 2, Ori_y);              //���ƺ����ͷ       *
		lineto(Ori_x + Len_x*UNIT_X + FREE_SPACE * 2 - 5, Ori_y - 5);                               //*

																									//**********************************************************************

		moveto(Ori_x, Ori_y);                          //��������ϵԭ��Ϊ��ǰ��
		lineto(Ori_x, Ori_y - Len_y*UNIT_Y - FREE_SPACE * 2);    //����ʵ�ʳ��ȵ�����
																 //**********************************************************************
		lineto(Ori_x + 5, Ori_y - Len_y*UNIT_Y - FREE_SPACE * 2 + 5);                                //*
		moveto(Ori_x, Ori_y - Len_y*UNIT_Y - FREE_SPACE * 2);             //���������ͷ         //*
		lineto(Ori_x - 5, Ori_y - Len_y*UNIT_Y - FREE_SPACE * 2 + 5);                                 //*
																									  //**********************************************************************


																									  //**********************************************************************************
		int j = 0;
		for (int i = Ori_x; i <= Ori_x + Len_x*UNIT_X; i += UNIT_X * 50)
		{
			moveto(i, Ori_y);
			TCHAR c[5];
			_stprintf_s(c, _T("%d"), j);  //��intת��Ϊc[]                                                     //���ƺ����ϵĵ�λ
			settextcolor(BLACK);
			outtextxy(i - textwidth(c[0]) / 2, Ori_y + textheight(c[0]) / 4, c);//���ʺϵ�λ�û��Ƶ�λ����
			lineto(i, Ori_y - SIGN);//���Ƶ�λ��ʶ
			j += 50;
		}
		//**********************************************************************************

	}

	void draw(double A[], double n)                          //������ϵ�ϻ��Ʋ���
	{
		setlinecolor(RGB(57, 111, 231));              //���û�����ɫ
		setfillcolor(RGB(57, 111, 231));               //���������ɫ
		moveto(Ori_x, Ori_y - A[0] * UNIT_Y);
		for (int i = 0; i <n; i++)
		{
			//moveto(Ori_x + i*UNIT_X, Ori_y+A[i]*UNIT_Y);
			lineto(Ori_x + i*UNIT_X, Ori_y - A[i] * UNIT_Y);
			//fillcircle(Ori_x + i*UNIT_X, Ori_y - A_.line[i] * UNIT_Y, 2);
			//TCHAR c[5];
			//_stprintf_s(c, _T("%d"), A_.line[i]);
			//settextcolor(BLACK);
			//outtextxy(Ori_x + i*UNIT_X - textwidth(c[0]), Ori_y - A_.line[i] * UNIT_Y - textheight(c[0]), c);
		}
	}
};

#endif
