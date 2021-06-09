#include <SDL.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <iostream>
#include <vector>

struct SQUARE
{
	double x[4];
	double y[4];
};

struct TRIANGLE
{
	double x[3];
	double y[3];
};

struct CLIPPING
{
	double x[4];
	double y[4];
};

void Draw_TRIANGLE(SDL_Renderer* renderer, TRIANGLE* tr, int Tx, int Ty, double angle, int trxcenter, int trycenter);
void Draw_SQUARE(SDL_Renderer* renderer, SQUARE* sq, int Tx, int Ty, double angle, int sqxcenter, int sqycenter);
double** SQ_Aff_matrix(int Tx, int Ty, double angle, int sqxcenter, int sqycenter);
double** TR_Aff_matrix(int Tx, int Ty, double angle, int trxcenter, int trycenter);
void Result_SQ(int m, SQUARE** sq, int Tx, int Ty, double angle, int sqxcenter, int sqycenter);
void Result_TR(int m, TRIANGLE** tr, int Tx, int Ty, double angle, int trxcenter, int trycenter);
bool p_belong(int npol, SQUARE *sq, TRIANGLE *tr, float x, float y);
bool p_belongtr(int npol, SQUARE *sq, TRIANGLE *tr, float x, float y);
double *Point_Crossing(double x1, double x2, double x3, double x4, double y1, double y2, double y3, double y4);
bool IsPointInsidePolygon(double Number, SQUARE *sq, double x, double y);
bool transection(double ax1, double ay1, double ax2, double ay2, double bx1, double by1, double bx2, double by2);
void DottedLine(SDL_Renderer *renderer, double x1, double y1, double x2, double y2);
int crossing_01(SQUARE *sq, TRIANGLE *tr);
int crossing_12(SQUARE *sq, TRIANGLE *tr);
int crossing_20(SQUARE *sq, TRIANGLE *tr);
double *CRS_PT(double x1, double x2, double x3, double x4, double y1, double y2, double y3, double y4);
void DrawClippingWindow(SDL_Renderer *renderer, CLIPPING *w);
bool p_belong_clipping_window(int npol, CLIPPING *w, float x, float y);
bool PointChecker(double x1, double y1, double x2, double y2, double x, double y);
bool Check(double x1, double y1, double x2, double y2, double x, double y);
bool CrossLine(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
double *intersect(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
void LOOK_AT_THIS_FUNC(SQUARE *sq, TRIANGLE *tr, double &Minx, double &Miny, double &Maxx, double &Maxy);
