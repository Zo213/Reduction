#include"coor_graphics.h"
#include<conio.h>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<windows.h>
#include<ctime>
#include <iostream>
#include "Eigen/SVD"
using namespace Eigen;
using namespace Eigen::internal;
using namespace Eigen::Architecture;
using namespace std;

#define N 119
#define M 400
#define PI 3.14
#define X 60

int main()
{

	double X_1[X][X]{{ 0 } };     //输入矩阵
	int n = 1;
	double X_X[N]{ 0 };        //初始数组
	double X_Y[N]{ 0 };
	srand((unsigned)time(NULL));
	for (int i = 0; i < N; i++)
	{
		X_Y[i] = sin(15 * PI*(i + 1) / M);//+ sin(40 * PI*(i + 1) / M);     //获取噪声信号
		X_X[i] = X_Y[i] + (0.1)*(rand() % 10 - 0.5);
	}

	for (int i = 0; i < X; i++)
	{
		X_1[0][i] = X_X[i];
	}
	for (int i = 0; i < X; i++)
	{
		X_1[i][X - 1] = X_X[i + X - 1];
	}

	for (int i = 1; i < X; i++)
	{
		for (int j = 0; j < X - 1; j++)
		{
			X_1[i][j] = X_1[i - 1][j + 1];
		}
	}
	MatrixXd A(X, X);  //目标输入数组

	for (int i = 0; i < X; i++)
	{
		for (int j = 0; j < X; j++)
		{
			A(i, j) = X_1[i][j];
		}
		cout << endl;
	}



	//cout << "这是一个矩阵 A:" << endl << A << endl;
	JacobiSVD<MatrixXd> svd(A, ComputeThinU | ComputeThinV);
	cout << "它的奇异值是：" << endl << svd.singularValues() << endl;
	//cout << "左奇异相量:" << endl << svd.matrixU()<< endl;
	//cout << "它的右奇异相量:" << endl << svd.matrixV() << endl;
	Vector3f rhs(1, 0, 0);

	MatrixXd C(X, X);
	MatrixXd D(X, X);
	C = svd.matrixV();
	D = C.transpose();          //转置右奇异相量


								//80%贡献率
	double count[X]{ 0 };    //奇异值的变换量
	for (int i = 0; i < X; i++)
	{
		count[i] = svd.singularValues()[i];
	}

	double sum = 0;
	for (int i = 0; i < X; i++)
	{
		sum += count[i];
	}


	double sum_1 = 0;
	for (int i = 0; i < X; i++)
	{
		sum_1 += count[i];
		if ((sum_1 / sum) >= 0.80)
		{
			count[i] = 0;
		}
	}

	double  X_N[X][X]{{ 0 }};      //奇异值变换量得到矩阵
	for (int i = 0; i < X; i++)
	{
		for (int j = 0; j < X; j++)
		{
			if (i == j)
				X_N[i][j] = count[i];
			else
				X_N[i][j] = 0;
		}
	}


	MatrixXd B(X, X);           //目标奇异值变换量得到的汉克尔矩阵
	for (int i = 0; i < X; i++)
	{
		for (int j = 0; j < X; j++)
		{
			B(i, j) = X_N[i][j];
		}
	}

	B = svd.matrixU()*B;

	B = B*D;


	double X_Z[N]{{ 0 } };        //目标输出数组
	for (int i = 0; i < X; i++)
	{
		X_Z[i] = B(0, i);
	}
	for (int i = 0; i < X; i++)
	{
		X_Z[i + X - 1] = B(i, X - 1);
	}





	//50%贡献率
	double count1[X]{ 0 };    //奇异值的变换量
	for (int i = 0; i < X; i++)
	{
		count1[i] = svd.singularValues()[i];
	}

	double sum1 = 0;
	for (int i = 0; i < X; i++)
	{
		sum1 += count1[i];
	}


	double sum_2 = 0;
	for (int i = 0; i < X; i++)
	{
		sum_2 += count1[i];
		if ((sum_2 / sum1) >= 0.50)
		{
			count1[i] = 0;
		}
	}

	double  X_N1[X][X]{{ 0 } };      //奇异值变换量得到的汉克尔矩阵
	for (int i = 0; i < X; i++)
	{
		for (int j = 0; j < X; j++)
		{
			if (i == j)
				X_N1[i][j] = count1[i];
			else
				X_N1[i][j] = 0;
		}
	}


	MatrixXd B1(X, X);           //目标奇异值变换量得到的汉克尔矩阵
	for (int i = 0; i < X; i++)
	{
		for (int j = 0; j < X; j++)
		{
			B1(i, j) = X_N1[i][j];
		}
	}

	B1 = svd.matrixU()*B1;

	B1 = B1*D;


	double X_Z1[N]{ 0 };        //目标输出数组
	for (int i = 0; i < X; i++)
	{
		X_Z1[i] = B1(0, i);
	}
	for (int i = 0; i < X; i++)
	{
		X_Z1[i + X - 1] = B1(i, X - 1);
	}



	//40%贡献率

	double count2[X]{ 0 };    //奇异值的变换量
	for (int i = 0; i < X; i++)
	{
		count2[i] = svd.singularValues()[i];
	}

	double sum2 = 0;
	for (int i = 0; i < X; i++)
	{
		sum2 += count2[i];
	}


	double sum_3 = 0;
	for (int i = 0; i < X; i++)
	{
		sum_3 += count2[i];
		if ((sum_3 / sum2) >= 0.40)
		{
			count2[i] = 0;
		}
	}

	double  X_N2[X][X]{{ 0 }};      //奇异值变换量得到的汉克尔矩阵
	for (int i = 0; i < X; i++)
	{
		for (int j = 0; j < X; j++)
		{
			if (i == j)
				X_N2[i][j] = count2[i];
			else
				X_N2[i][j] = 0;
		}
	}


	MatrixXd B2(X, X);           //目标奇异值变换量得到的汉克尔矩阵
	for (int i = 0; i < X; i++)
	{
		for (int j = 0; j < X; j++)
		{
			B2(i, j) = X_N2[i][j];
		}
	}

	B2 = svd.matrixU()*B2;

	B2 = B2*D;


	double X_Z2[N]{ 0 };        //目标输出数组
	for (int i = 0; i < X; i++)
	{
		X_Z2[i] = B2(0, i);
	}
	for (int i = 0; i < X; i++)
	{
		X_Z2[i + X - 1] = B2(i, X - 1);
	}




	double max_1 = 0;
	double max_2 = 0;
	double max_3 = 0;
	double max_4 = 0;
	for (int i = 0; i < X; i++)
	{
		max_1 = max_1 > X_X[i] ? max_1 : X_X[i];
		max_2 = max_2 > X_Z[i] ? max_2 : X_Z[i];
		max_3 = max_3> X_Z1[i] ? max_3 : X_Z1[i];
		max_4 = max_4> X_Z2[i] ? max_4 : X_Z2[i];
	}

	system("pause");

	initgraph(1000, 700);

	setbkcolor(WHITE);
	cleardevice();
	COORDINATE_SYS J1(N, max_1, 150, 100);
	COORDINATE_SYS J2(N, max_2, 150, 200);
	COORDINATE_SYS J3(N, max_3, 150, 300);
	COORDINATE_SYS J4(N, max_4, 150, 400);
	J1.show();
	J2.show();
	J3.show();
	J4.show();
	J1.draw(X_X, N);
	J2.draw(X_Z, N);
	J3.draw(X_Z1, N);
	J4.draw(X_Z2, N);



	getchar();
	closegraph();
	system("pause");


	return 0;
}


