#ifndef COOR_GRAPGICS_H
#define COOR_GRAPHICS_H

#include<graphics.h>


#define UNIT_X 2    //X轴单位长度 
#define UNIT_Y 20     //Y轴单位长度 
#define FREE_SPACE 20     //坐标系上空余空间 
#define SIGN 5          //X轴标记点高度 


class COORDINATE_SYS {               //建立坐标系的类
private:
	int Ori_x;                                   // 坐标系原点的横坐标
	int Ori_y;                                   //坐标系原点的纵坐标
	int Len_x;                                  //坐标系横轴的逻辑长度
	int Len_y;                                  //坐标轴纵轴的逻辑长度

public:


	COORDINATE_SYS(double L_X, double L_Y, int O_X, int O_Y)        // 构造函数
	{
		Ori_x = O_X;
		Ori_y = O_Y;
		Len_x = L_X;
		Len_y = L_Y;
	}

	void show()                                       //绘制坐标系
	{
		setlinecolor(BLACK);                       //设置绘线颜色
		moveto(Ori_x, Ori_y);                    //设置坐标系原点为当前点
		lineto(Ori_x + Len_x*UNIT_X + FREE_SPACE * 2, Ori_y);   //绘制实际长度的正横轴

																//**********************************************************************
		lineto(Ori_x + Len_x*UNIT_X + FREE_SPACE * 2 - 5, Ori_y + 5);                              //*
		moveto(Ori_x + Len_x*UNIT_X + FREE_SPACE * 2, Ori_y);              //绘制横轴箭头       *
		lineto(Ori_x + Len_x*UNIT_X + FREE_SPACE * 2 - 5, Ori_y - 5);                               //*

																									//**********************************************************************

		moveto(Ori_x, Ori_y);                          //设置坐标系原点为当前点
		lineto(Ori_x, Ori_y - Len_y*UNIT_Y - FREE_SPACE * 2);    //绘制实际长度的纵轴
																 //**********************************************************************
		lineto(Ori_x + 5, Ori_y - Len_y*UNIT_Y - FREE_SPACE * 2 + 5);                                //*
		moveto(Ori_x, Ori_y - Len_y*UNIT_Y - FREE_SPACE * 2);             //绘制纵轴箭头         //*
		lineto(Ori_x - 5, Ori_y - Len_y*UNIT_Y - FREE_SPACE * 2 + 5);                                 //*
																									  //**********************************************************************


																									  //**********************************************************************************
		int j = 0;
		for (int i = Ori_x; i <= Ori_x + Len_x*UNIT_X; i += UNIT_X * 50)
		{
			moveto(i, Ori_y);
			TCHAR c[5];
			_stprintf_s(c, _T("%d"), j);  //将int转换为c[]                                                     //绘制横轴上的单位
			settextcolor(BLACK);
			outtextxy(i - textwidth(c[0]) / 2, Ori_y + textheight(c[0]) / 4, c);//在适合的位置绘制单位数字
			lineto(i, Ori_y - SIGN);//绘制单位标识
			j += 50;
		}
		//**********************************************************************************

	}

	void draw(double A[], double n)                          //在坐标系上绘制波形
	{
		setlinecolor(RGB(57, 111, 231));              //设置绘线颜色
		setfillcolor(RGB(57, 111, 231));               //绘制填充颜色
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
