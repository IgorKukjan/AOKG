#include "Header.h"
#define Pi 3.1415926535
//Screen constants
#define SCREEN_WIDTH  800
#define SCREEN_HEIGHT  800

double** SQ_Aff_matrix(int Tx, int Ty, double angle, int sqxcenter, int sqycenter)
{
	double** matr;
	matr = (double**)malloc(3 * sizeof(double*));
	*(matr) = (double*)malloc(3 * sizeof(double));
	*(matr + 1) = (double*)malloc(3 * sizeof(double));
	*(matr + 2) = (double*)malloc(3 * sizeof(double));

	double** matr1;
	matr1 = (double**)malloc(3 * sizeof(double*));
	*(matr1) = (double*)malloc(3 * sizeof(double));
	*(matr1 + 1) = (double*)malloc(3 * sizeof(double));
	*(matr1 + 2) = (double*)malloc(3 * sizeof(double));

	double** minusTrans;
	minusTrans = (double**)malloc(3 * sizeof(double*));
	*(minusTrans) = (double*)malloc(3 * sizeof(double));
	*(minusTrans + 1) = (double*)malloc(3 * sizeof(double));
	*(minusTrans + 2) = (double*)malloc(3 * sizeof(double));

	minusTrans[0][0] = 1;
	minusTrans[0][1] = 0;
	minusTrans[0][2] = -Tx - sqxcenter;
	minusTrans[1][0] = 0;
	minusTrans[1][1] = 1;
	minusTrans[1][2] = -Ty - sqycenter;
	minusTrans[2][0] = 0;
	minusTrans[2][1] = 0;
	minusTrans[2][2] = 1;

	double** Trans;
	Trans = (double**)malloc(3 * sizeof(double*));
	*(Trans) = (double*)malloc(3 * sizeof(double));
	*(Trans + 1) = (double*)malloc(3 * sizeof(double));
	*(Trans + 2) = (double*)malloc(3 * sizeof(double));

	Trans[0][0] = 1;
	Trans[0][1] = 0;
	Trans[0][2] = Tx + sqxcenter;
	Trans[1][0] = 0;
	Trans[1][1] = 1;
	Trans[1][2] = Ty + sqycenter;
	Trans[2][0] = 0;
	Trans[2][1] = 0;
	Trans[2][2] = 1;

	double** Rotate;
	Rotate = (double**)malloc(3 * sizeof(double*));
	*(Rotate) = (double*)malloc(3 * sizeof(double));
	*(Rotate + 1) = (double*)malloc(3 * sizeof(double));
	*(Rotate + 2) = (double*)malloc(3 * sizeof(double));

	Rotate[0][0] = cos(angle);
	Rotate[0][1] = -sin(angle);
	Rotate[0][2] = 0;
	Rotate[1][0] = sin(angle);
	Rotate[1][1] = cos(angle);
	Rotate[1][2] = 0;
	Rotate[2][0] = 0;
	Rotate[2][1] = 0;
	Rotate[2][2] = 1;

	if (Tx != 0 || Ty != 0)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				matr[i][j] = 0;
				for (int k = 0; k < 3; k++)
				{
					matr[i][j] += Trans[k][j] * Rotate[i][k];
				}
			}
		}
		return matr;
	}

	else
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				matr[i][j] = 0;
				for (int k = 0; k < 3; k++)
				{
					matr[i][j] += minusTrans[k][j] * Rotate[i][k];
				}
			}
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				matr1[i][j] = 0;
				for (int k = 0; k < 3; k++)
				{
					matr1[i][j] += matr[k][j] * Trans[i][k];
				}
			}
		}
		return matr1;
	}
}

double** TR_Aff_matrix(int Tx, int Ty, double angle, int trxcenter, int trycenter)
{
	double** matr;
	matr = (double**)malloc(3 * sizeof(double*));
	*(matr) = (double*)malloc(3 * sizeof(double));
	*(matr + 1) = (double*)malloc(3 * sizeof(double));
	*(matr + 2) = (double*)malloc(3 * sizeof(double));

	double** matr1;
	matr1 = (double**)malloc(3 * sizeof(double*));
	*(matr1) = (double*)malloc(3 * sizeof(double));
	*(matr1 + 1) = (double*)malloc(3 * sizeof(double));
	*(matr1 + 2) = (double*)malloc(3 * sizeof(double));

	double** minusTrans;
	minusTrans = (double**)malloc(3 * sizeof(double*));
	*(minusTrans) = (double*)malloc(3 * sizeof(double));
	*(minusTrans + 1) = (double*)malloc(3 * sizeof(double));
	*(minusTrans + 2) = (double*)malloc(3 * sizeof(double));

	minusTrans[0][0] = 1;
	minusTrans[0][1] = 0;
	minusTrans[0][2] = -Tx - trxcenter;
	minusTrans[1][0] = 0;
	minusTrans[1][1] = 1;
	minusTrans[1][2] = -Ty - trycenter;
	minusTrans[2][0] = 0;
	minusTrans[2][1] = 0;
	minusTrans[2][2] = 1;

	double** Trans;
	Trans = (double**)malloc(3 * sizeof(double*));
	*(Trans) = (double*)malloc(3 * sizeof(double));
	*(Trans + 1) = (double*)malloc(3 * sizeof(double));
	*(Trans + 2) = (double*)malloc(3 * sizeof(double));

	Trans[0][0] = 1;
	Trans[0][1] = 0;
	Trans[0][2] = Tx + trxcenter;
	Trans[1][0] = 0;
	Trans[1][1] = 1;
	Trans[1][2] = Ty + trycenter;
	Trans[2][0] = 0;
	Trans[2][1] = 0;
	Trans[2][2] = 1;

	double** Rotate;
	Rotate = (double**)malloc(3 * sizeof(double*));
	*(Rotate) = (double*)malloc(3 * sizeof(double));
	*(Rotate + 1) = (double*)malloc(3 * sizeof(double));
	*(Rotate + 2) = (double*)malloc(3 * sizeof(double));

	Rotate[0][0] = cos(angle);
	Rotate[0][1] = -sin(angle);
	Rotate[0][2] = 0;
	Rotate[1][0] = sin(angle);
	Rotate[1][1] = cos(angle);
	Rotate[1][2] = 0;
	Rotate[2][0] = 0;
	Rotate[2][1] = 0;
	Rotate[2][2] = 1;

	if (Tx != 0 || Ty != 0)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				matr[i][j] = 0;
				for (int k = 0; k < 3; k++)
				{
					matr[i][j] += Trans[k][j] * Rotate[i][k];
				}
			}
		}
		return matr;
	}

	else
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				matr[i][j] = 0;
				for (int k = 0; k < 3; k++)
				{
					matr[i][j] += minusTrans[k][j] * Rotate[i][k];
				}
			}
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				matr1[i][j] = 0;
				for (int k = 0; k < 3; k++)
				{
					matr1[i][j] += matr[k][j] * Trans[i][k];
				}
			}
		}
		return matr1;
	}
}

void Result_SQ(int m, SQUARE** sq, int Tx, int Ty, double angle, int sqxcenter, int sqycenter)
{
	double** matr;
	matr = (double**)malloc(3 * sizeof(double*));
	*(matr) = (double*)malloc(1 * sizeof(double));
	*(matr + 1) = (double*)malloc(1 * sizeof(double));
	*(matr + 2) = (double*)malloc(1 * sizeof(double));
	**(matr) = (*sq)->x[m];
	**(matr + 1) = (*sq)->y[m];
	**(matr + 2) = 1;

	double** aff = SQ_Aff_matrix(Tx, Ty, angle, sqxcenter, sqycenter);
	//aff[2][0] = (sqxcenter * (cos(angle) - 1)) - (sqycenter * sin(angle));
	//aff[2][1] = (sqycenter * (cos(angle) - 1)) + (sqxcenter * sin(angle));

	double** matr1;
	matr1 = (double**)malloc(3 * sizeof(double*));
	*(matr1) = (double*)malloc(1 * sizeof(double));
	*(matr1 + 1) = (double*)malloc(1 * sizeof(double));
	*(matr1 + 2) = (double*)malloc(1 * sizeof(double));

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			matr1[i][j] = 0;
			for (int k = 0; k < 3; k++)
			{
				matr1[i][j] += aff[i][k] * matr[k][j];
			}
		}
	}

	(*sq)->x[m] = matr1[0][0];
	(*sq)->y[m] = matr1[1][0];
}

void Result_TR(int m, TRIANGLE** tr, int Tx, int Ty, double angle, int trxcenter, int trycenter)
{
	double** matr;
	matr = (double**)malloc(3 * sizeof(double*));
	*(matr) = (double*)malloc(1 * sizeof(double));
	*(matr + 1) = (double*)malloc(1 * sizeof(double));
	*(matr + 2) = (double*)malloc(1 * sizeof(double));
	**(matr) = (*tr)->x[m];
	**(matr + 1) = (*tr)->y[m];
	**(matr + 2) = 1;

	double** aff = TR_Aff_matrix(Tx, Ty, angle, trxcenter, trycenter);
	//aff[2][0] = (trxcenter * (cos(angle)-1)) - (trycenter * sin(angle));
	//aff[2][1] = (trycenter * (cos(angle)-1)) + (trxcenter * sin(angle));

	double** matr1;
	matr1 = (double**)malloc(3 * sizeof(double*));
	*(matr1) = (double*)malloc(1 * sizeof(double));
	*(matr1 + 1) = (double*)malloc(1 * sizeof(double));
	*(matr1 + 2) = (double*)malloc(1 * sizeof(double));

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			matr1[i][j] = 0;
			for (int k = 0; k < 3; k++)
			{
				matr1[i][j] += aff[i][k] * matr[k][j];
			}
		}
	}

	(*tr)->x[m] = matr1[0][0];
	(*tr)->y[m] = matr1[1][0];
}

void Draw_SQUARE(SDL_Renderer* renderer, SQUARE* sq, int Tx, int Ty, double angle, int sqxcenter, int sqycenter)
{

	for (int m = 0; m < 4; m++)
		Result_SQ(m, &sq, Tx, Ty, angle, sqxcenter, sqycenter);

	SDL_RenderDrawLine(renderer, sq->x[0], sq->y[0], sq->x[1], sq->y[1]);
	SDL_RenderDrawLine(renderer, sq->x[1], sq->y[1], sq->x[2], sq->y[2]);
	SDL_RenderDrawLine(renderer, sq->x[2], sq->y[2], sq->x[3], sq->y[3]);
	SDL_RenderDrawLine(renderer, sq->x[3], sq->y[3], sq->x[0], sq->y[0]);
}

void Draw_TRIANGLE(SDL_Renderer* renderer, TRIANGLE* tr, int Tx, int Ty, double angle, int trxcenter, int trycenter)
{

	for (int m = 0; m < 3; m++)
		Result_TR(m, &tr, Tx, Ty, angle, trxcenter, trycenter);

	SDL_RenderDrawLine(renderer, tr->x[0], tr->y[0], tr->x[1], tr->y[1]);
	SDL_RenderDrawLine(renderer, tr->x[1], tr->y[1], tr->x[2], tr->y[2]);
	SDL_RenderDrawLine(renderer, tr->x[2], tr->y[2], tr->x[0], tr->y[0]);

}

int crossing_01(SQUARE *sq, TRIANGLE *tr)
{
	bool fl = 0;
	for (int i = 0; i < 2; i++)
	{
		if (CrossLine(tr->x[0], tr->y[0], tr->x[1], tr->y[1], sq->x[i], sq->y[i], sq->x[i + 1], sq->y[i + 1]))
		{
			fl = 1;
			if (i == 0)
				return 1;
			if (i == 1)
				return 12;
			if (i == 2)
				return 23;
		}
	}
	if (CrossLine(tr->x[0], tr->y[0], tr->x[1], tr->y[1], sq->x[3], sq->y[3], sq->x[0], sq->y[0]))
	{
		return 30;
	}
	if (fl == 1)
		return -1;
}




int crossing_12(SQUARE *sq, TRIANGLE *tr)
{
	bool fl = 0;
	for (int i = 0; i < 3; i++)
	{
		if (CrossLine(tr->x[1], tr->y[1], tr->x[2], tr->y[2], sq->x[i], sq->y[i], sq->x[i + 1], sq->y[i + 1]))
		{
			fl = 1;
			if (i == 0)
				return 1;
			if (i == 1)
				return 12;
			if (i == 2)
				return 23;
		}
	}
	if (CrossLine(tr->x[1], tr->y[1], tr->x[2], tr->y[2], sq->x[3], sq->y[3], sq->x[0], sq->y[0]))
	{
		return 30;
	}
	if (fl == 1)
		return -1;
}
int crossing_20(SQUARE *sq, TRIANGLE *tr)
{
	bool fl = 0;
	for (int i = 0; i < 3; i++)
	{
		if (CrossLine(tr->x[2], tr->y[2], tr->x[0], tr->y[0], sq->x[i], sq->y[i], sq->x[i + 1], sq->y[i + 1]))
		{
			fl = 1;
			if (i == 0)
				return 1;
			if (i == 1)
				return 12;
			if (i == 2)
				return 23;
		}
	}
	if (CrossLine(tr->x[2], tr->y[2], tr->x[0], tr->y[0], sq->x[3], sq->y[3], sq->x[0], sq->y[0]))
	{
		return 30;
	}
	if (fl == 1)
		return -1;
}

bool transection(double ax1, double ay1, double ax2, double ay2, double bx1, double by1, double bx2, double by2)
{
	double v1 = (bx2 - bx1)*(ay1 - by1) - (by2 - by1)*(ax1 - bx1);
	double v2 = (bx2 - bx1)*(ay2 - by1) - (by2 - by1)*(ax2 - bx1);
	double v3 = (ax2 - ax1)*(by1 - ay1) - (ay2 - ay1)*(bx1 - ax1);
	double v4 = (ax2 - ax1)*(by2 - ay1) - (ay2 - ay1)*(bx2 - ax1);
	return ((v1*v2 <= 0) && (v3*v4 <= 0));
}

bool p_belong(int npol, SQUARE *sq, TRIANGLE *tr, float x, float y)
{
	bool c = false;
	for (int i = 0, j = npol - 1; i < npol; j = i++)
	{
		if (((((sq->y[i]) <= y) && (y<(sq->y[j]))) || (((sq->y[j]) <= y) && (y<(sq->y[i])))) &&
			((sq->y[j]) - (sq->y[i]) != 0 && x >((sq->x[j]) - (sq->x[i])) * (y - (sq->y[i])) / ((sq->y[j]) - (sq->y[i])) + (sq->x[i])))
			c = !c;
	}
	return c;
}

bool p_belongtr(int npol, SQUARE *sq, TRIANGLE *tr, float x, float y)
{
	bool c = false;
	for (int i = 0, j = npol - 1; i < npol; j = i++)
	{
		if (((((tr->y[i]) <= y) && (y<(tr->y[j]))) || (((tr->y[j]) <= y) && (y<(tr->y[i])))) &&
			((tr->y[j]) - (tr->y[i]) != 0 && x >((tr->x[j]) - (tr->x[i])) * (y - (tr->y[i])) / ((tr->y[j]) - (tr->y[i])) + (tr->x[i])))
			c = !c;
	}
	return c;
}

bool IsPointInsidePolygon(double Number, SQUARE *sq, double x, double y)
{
	int i1, i2, n;
	double N, S, S1, S2, S3;
	bool flag;
	N = Number;
	for (n = 0; n<N; n++)
	{
		flag = 0;
		i1 = n < N - 1 ? n + 1 : 0;
		while (!flag)
		{
			i2 = i1 + 1;
			if (i2 >= N)
				i2 = 0;
			if (i2 == (n < N - 1 ? n + 1 : 0))
				break;
			S = abs(sq->x[i1] * (sq->y[i2] - sq->y[n]) +
				sq->x[i2] * (sq->y[n] - sq->y[i1]) +
				sq->x[n] * (sq->y[i1] - sq->y[i2]));
			S1 = abs(sq->x[i1] * (sq->y[i2] - y) +
				sq->x[i2] * (y - sq->y[i1]) +
				x       * (sq->y[i1] - sq->y[i2]));
			S2 = abs(sq->x[n] * (sq->y[i2] - y) +
				sq->x[i2] * (y - sq->y[n]) +
				x       * (sq->y[n] - sq->y[i2]));
			S3 = abs(sq->x[i1] * (sq->y[n] - y) +
				sq->x[n] * (y - sq->y[i1]) +
				x       * (sq->y[i1] - sq->y[n]));
			if (S == S1 + S2 + S3)
			{
				flag = 1;
				break;
			}
			i1 = i1 + 1;
			if (i1 >= N)
				i1 = 0;
		}
		if (!flag)
			break;
	}
	return flag;
}

void DottedLine(SDL_Renderer *renderer, double x1, double y1, double x2, double y2)
{
	int iter = 0;
	double dx, dy;
	double x, y;
	dx = x2 - x1;
	dy = y2 - y1;
	x = x1 + (dx / 10);
	y = y1 + (dy / 10);
	while (x<x2)
	{
		if (iter % 2 != 0)
		{
			x1 = x1 + (dx / 10);
			y1 = y1 + (dy / 10);
			x = x1 + (dx / 10);
			y = y1 + (dy / 10);
			SDL_RenderDrawLine(renderer, x1, y1, x, y);
			iter++;
		}
		else
		{
			x1 = x1 + (dx / 10);
			y1 = y1 + (dy / 10);
			x = x1 + 2 * (dx / 10);
			y = y1 + 2 * (dy / 10);
			iter++;
		}
	}
}

double *Point_Crossing(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
	double *xy;
	xy = (double*)malloc(2 * sizeof(double));
	double det = ((x2 - x1)*(y3 - y4) - (x3 - x4)*(y2 - y1));
	if (det != 0)
	{
		double mu;
		double nu;
		mu = ((x3 - x1)*(y3 - y4) - (x3 - x4)*(y3 - y1)) / det;
		nu = ((x2 - x1)*(y3 - y1) - (x3 - x1)*(y2 - y1)) / det;
		if ((mu >= 0 && mu <= 1) && (nu >= 0 && nu <= 1))
		{
			xy[0] = (1 - mu)*x1 + mu*x2;
			xy[1] = (1 - mu)*y1 + mu*y2;
			return xy;
		}
		else
			printf("LOL\n");
	}
	else
		printf("LOL\n");
}

void DrawClippingWindow(SDL_Renderer *renderer, CLIPPING *w)
{
	double x1, x2, x3, x4;
	double y1, y2, y3, y4;

	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderDrawLine(renderer, w->x[0], w->y[0], w->x[1], w->y[1]);
	SDL_RenderDrawLine(renderer, w->x[1], w->y[1], w->x[2], w->y[2]);
	SDL_RenderDrawLine(renderer, w->x[2], w->y[2], w->x[3], w->y[3]);
	SDL_RenderDrawLine(renderer, w->x[3], w->y[3], w->x[0], w->y[0]);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}

bool p_belong_clipping_window(int npol, CLIPPING *w, float x, float y)
{
	bool c = false;
	for (int i = 0, j = npol - 1; i < npol; j = i++)
	{
		if (((((w->y[i]) <= y) && (y<(w->y[j]))) || (((w->y[j]) <= y) && (y<(w->y[i])))) &&
			((w->y[j]) - (w->y[i]) != 0 && x >((w->x[j]) - (w->x[i])) * (y - (w->y[i])) / ((w->y[j]) - (w->y[i])) + (w->x[i])))
			c = !c;
		if (Check(w->x[0], w->y[0], w->x[3], w->y[3], x, y) || Check(w->x[2], w->y[2], w->x[3], w->y[3], x, y))
		{
			c = true;
		}
	}
	return c;
}

bool PointChecker(double x1, double y1, double x2, double y2, double x, double y)// Вводим координаты начальной точки и конечной точки отрезка, а затем вводим координаты точки на отрезке.
{
	double c1 = (x2 - x1);
	double c2 = (y2 - y1);

	if ((c1 && c2) != 0)
	{
		double a = (x - x1) / c1;
		double b = (y - y1) / c2;
		if (a == b)
		{

			double NU;
			NU = sqrt(((x - x1)*(x - x1) + (y - y1)*(y - y1)) / ((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1)));
			if (NU >= 0 && NU <= 1)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
	{
		if (x1 == x2 == x)
		{
			if (y > y1 && y < y2)
			{
				return true;
			}
		}
		if (y1 == y2 == y)
		{
			if (x > x1 && x < x2)
			{
				return true;
			}
		}
	}
}

bool Check(double x1, double y1, double x2, double y2, double x, double y)
{
	double VXx1x2, VYx1x2, VXx1x, VYx1x, VXxx1, VYxx1, VXxx2, VYxx2;
	VXx1x2 = x2 - x1;
	VYx1x2 = y2 - y1;
	VXx1x = x - x1;
	VYx1x = y - y1;
	VXxx1 = x1 - x;
	VYxx1 = y1 - y;
	VXxx2 = x2 - x;
	VYxx2 = y2 - y;
	double COS_Vxx1_Vxx2 = ((VXxx1*VXxx2) + (VYxx1*VYxx2)) / (sqrt((VXxx1*VXxx1) + (VYxx1*VYxx1)) * sqrt((VXxx2*VXxx2) + (VYxx2*VYxx2)));
	double COS_Vx1x2_Vx1x = (((VXx1x2*VXx1x) + (VYx1x2*VYx1x)) / (sqrt((VXx1x2*VXx1x2) + (VYx1x2*VYx1x2)) * sqrt((VXx1x*VXx1x) + (VYx1x*VYx1x))));
	double SIN_Vx1x2_Vx1x = sqrt(1 - (COS_Vx1x2_Vx1x*COS_Vx1x2_Vx1x));

	double VectMultiply_Vx1x2_Vx1x = (sqrt((VXx1x2*VXx1x2) + (VYx1x2*VYx1x2))) * (sqrt((VXx1x*VXx1x) + (VYx1x*VYx1x))) * SIN_Vx1x2_Vx1x;
	double SkalMultiply_Vxx1_Vxx2 = sqrt((VXxx1*VXxx1) + (VYxx1*VYxx1)) * sqrt((VXxx2*VXxx2) + (VYxx2*VYxx2)) * COS_Vxx1_Vxx2;

	if (((VectMultiply_Vx1x2_Vx1x < 500) && (VectMultiply_Vx1x2_Vx1x >= 0)) && (SkalMultiply_Vxx1_Vxx2 <= 0))
		return true;
	else
		return false;
}

bool CrossLine(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
	double	dx1 = x2 - x1;
	double	dy1 = y2 - y1;
	double	dx2 = x4 - x3;
	double	dy2 = y4 - y3;
	double x = dy1 * dx2 - dy2 * dx1;
	if (!x || !dx2)
		return false;
	double y = x3 * y4 - y3 * x4;
	x = ((x1 * y2 - y1 * x2) * dx2 - y * dx1) / x;
	y = (dy2 * x - y) / dx2;
	return
		((x1 <= x && x2 >= x) || (x2 <= x && x1 >= x)) && ((x3 <= x && x4 >= x) || (x4 <= x && x3 >= x));
}

double *intersect(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{

	double a1 = y1 - y2;
	double b1 = x2 - x1;
	double c1 = x1 * y2 - x2 * y1;
	double a2 = y3 - y4;
	double b2 = x4 - x3;
	double c2 = x3 * y4 - x4 * y3;

	double *xy;
	xy = (double*)malloc(2 * sizeof(double));
	double det = a1 * b2 - a2 * b1;
	xy[0] = (b1 * c2 - b2 * c1) / det;
	xy[1] = (a2 * c1 - a1 * c2) / det;
	return xy;
}

void LOOK_AT_THIS_FUNC(SQUARE *sq, TRIANGLE *tr, double &Minx, double &Miny, double &Maxx, double &Maxy)
{

	double MasX[4], MasY[4];

	for (int i = 0; i < 4; i++)
		MasX[i] = sq->x[i];
	Minx = MasX[0];
	for (int i = 0; i < 4; i++)
	{
		if (Minx > MasX[i])
			Minx = MasX[i];
	}

	for (int i = 0; i < 4; i++)
		MasY[i] = sq->y[i];
	Miny = MasY[0];
	for (int i = 0; i < 4; i++)
	{
		if (Miny > MasY[i])
			Miny = MasY[i];
	}


	for (int i = 0; i < 4; i++)
		MasX[i] = sq->x[i];
	Maxx = MasX[0];
	for (int i = 0; i < 4; i++)
	{
		if (Maxx < MasX[i])
			Maxx = MasX[i];
	}

	for (int i = 0; i < 4; i++)
		MasY[i] = sq->y[i];
	Maxy = MasY[0];
	for (int i = 0; i < 4; i++)
	{
		if (Maxy < MasY[i])
			Maxy = MasY[i];
	}

}