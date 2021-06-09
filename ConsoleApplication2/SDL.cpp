#include "Header.h"

//Screen constants
#define SCREEN_WIDTH  800
#define SCREEN_HEIGHT  800
//Pi
#define Pi 3.1415926535

int main(int argc, char* args[])
{
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	SDL_Renderer* renderer = NULL;
	SDL_Event event;
	SDL_MouseWheelEvent();

	SDL_Rect *rect1 = (SDL_Rect*)malloc(sizeof(SDL_Rect));
	(*rect1).x = 0;
	(*rect1).y = 0;
	(*rect1).h = 75;
	(*rect1).w = SCREEN_WIDTH;

	SDL_Rect *rect2 = (SDL_Rect*)malloc(sizeof(SDL_Rect));
	(*rect2).x = 0;
	(*rect2).y = 0;
	(*rect2).h = SCREEN_HEIGHT;
	(*rect2).w = 75;

	SDL_Rect *rect3 = (SDL_Rect*)malloc(sizeof(SDL_Rect));
	(*rect3).x = 0;
	(*rect3).y = 726;
	(*rect3).h = 74;
	(*rect3).w = SCREEN_WIDTH;

	SDL_Rect *rect4 = (SDL_Rect*)malloc(sizeof(SDL_Rect));
	(*rect4).x = 726;
	(*rect4).y = 0;
	(*rect4).h = SCREEN_HEIGHT;
	(*rect4).w = 75;

	double  angle_SQ = 0, angle_TR = 0;
	double  Tx_SQ = 0, Ty_SQ = 0, Tx_TR = 0, Ty_TR = 0;
	double width, height;
	double Minx, Miny, Maxx, Maxy;
	double sqxcenter = 0.0;// = (sq->x[0] + sq->x[1]) / 2;
	double sqycenter = 0.0;// = (sq->y[0] + sq->y[3]) / 2;
	double trxcenter = 0.0;// = (tr->x[1] + tr->x[2]) / 2;
	double trycenter = 0.0;// = tr->y[1] / 4 * 3;

	SQUARE *sq = (SQUARE*)malloc(sizeof(SQUARE));
	sq->x[0] = 10;
	sq->y[0] = 10;
	sq->x[1] = 410;
	sq->y[1] = 10;
	sq->x[2] = 410;
	sq->y[2] = 410;
	sq->x[3] = 10;
	sq->y[3] = 410;

	TRIANGLE *tr = (TRIANGLE*)malloc(sizeof(TRIANGLE));
	tr->x[0] = 300;
	tr->y[0] = 100;
	tr->x[1] = 300;
	tr->y[1] = 400;
	tr->x[2] = 100;
	tr->y[2] = 400;

	CLIPPING *w = (CLIPPING*)malloc(sizeof(CLIPPING));



	//Init
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Window creation
		window = SDL_CreateWindow("DEKART'S LIST", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{

			//printf("Input clipping window size:\n");
			//printf("Input window width:\n");
			//while (!scanf_s("%lf", &width) || width<0 || width > SCREEN_WIDTH)
			//{
			//	rewind(stdin);
			//	printf("Only posisive numbers or u use clipping window\nwith the size more than main window!\n");
			//}
			//printf("Input window height:\n");
			//while(!scanf_s("%lf", &height) || height<0 || height > SCREEN_HEIGHT)
			//{
			//	rewind(stdin);
			//	printf("Only posisive numbers or u use clipping window\nwith the size more than main window!\n");
			//}

			width = 650;
			height = 650;

			w->x[0] = (SCREEN_WIDTH - width) / 2;
			w->x[1] = w->x[0] + width;
			w->x[2] = w->x[1];
			w->x[3] = w->x[0];
			w->y[0] = (SCREEN_HEIGHT - height) / 2;
			w->y[1] = w->y[0];
			w->y[2] = w->y[1] + height;
			w->y[3] = w->y[2];


			double *xy;
			xy = (double*)malloc(2 * sizeof(double));

			screenSurface = SDL_GetWindowSurface(window);
			renderer = SDL_CreateRenderer(window, 0, 0);

			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

			Draw_SQUARE(renderer, sq, Tx_SQ, Ty_SQ, angle_SQ, sqxcenter, sqycenter);
			Draw_TRIANGLE(renderer, tr, Tx_TR, Ty_TR, angle_TR, trxcenter, trycenter);
			DrawClippingWindow(renderer, w);

			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

			SDL_RenderFillRect(renderer, rect1);
			SDL_RenderFillRect(renderer, rect2);
			SDL_RenderFillRect(renderer, rect3);
			SDL_RenderFillRect(renderer, rect4);

			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

			SDL_RenderPresent(renderer);

			while (true)
			{
				SDL_WaitEvent(&event);

				switch (event.type)
				{

				case SDL_QUIT:
					return 0;


				case SDL_KEYDOWN:

					switch (event.key.keysym.sym)
					{

					case SDLK_d:

						Tx_SQ += 10;

						SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
						SDL_RenderClear(renderer);

						SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
						Draw_SQUARE(renderer, sq, Tx_SQ, Ty_SQ, angle_SQ, sqxcenter, sqycenter);
						Draw_TRIANGLE(renderer, tr, Tx_TR, Ty_TR, angle_TR, trxcenter, trycenter);

						LOOK_AT_THIS_FUNC(sq, tr, Minx, Miny, Maxx, Maxy);

						for (double x = Minx; x < Maxx; x += 2)
						{
							for (double y = Miny; y < Maxy; y += 2)
							{
								if (Check(tr->x[0], tr->y[0], tr->x[1], tr->y[1], x, y) && p_belong(4, sq, tr, x, y))
								{
									SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
									SDL_RenderDrawPoint(renderer, x, y);
								}
								if (Check(tr->x[1], tr->y[1], tr->x[2], tr->y[2], x, y) && p_belong(4, sq, tr, x, y))
								{
									SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
									SDL_RenderDrawPoint(renderer, x, y);
								}
								if (Check(tr->x[2], tr->y[2], tr->x[0], tr->y[0], x, y) && p_belong(4, sq, tr, x, y))
								{
									SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
									SDL_RenderDrawPoint(renderer, x, y);
								}

							}
						}
						DrawClippingWindow(renderer, w);

						SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

						SDL_RenderFillRect(renderer, rect1);
						SDL_RenderFillRect(renderer, rect2);
						SDL_RenderFillRect(renderer, rect3);
						SDL_RenderFillRect(renderer, rect4);

						SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

						SDL_RenderPresent(renderer);

						break;

					case SDLK_a:

						Tx_SQ -= 10;
						SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
						SDL_RenderClear(renderer);

						SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
						Draw_SQUARE(renderer, sq, Tx_SQ, Ty_SQ, angle_SQ, sqxcenter, sqycenter);
						Draw_TRIANGLE(renderer, tr, Tx_TR, Ty_TR, angle_TR, trxcenter, trycenter);
						LOOK_AT_THIS_FUNC(sq, tr, Minx, Miny, Maxx, Maxy);

						for (double x = Minx; x < Maxx; x += 2)
						{
							for (double y = Miny; y < Maxy; y += 2)
							{
								if (Check(tr->x[0], tr->y[0], tr->x[1], tr->y[1], x, y) && p_belong(4, sq, tr, x, y))
								{
									SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
									SDL_RenderDrawPoint(renderer, x, y);
								}
								if (Check(tr->x[1], tr->y[1], tr->x[2], tr->y[2], x, y) && p_belong(4, sq, tr, x, y))
								{
									SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
									SDL_RenderDrawPoint(renderer, x, y);
								}
								if (Check(tr->x[2], tr->y[2], tr->x[0], tr->y[0], x, y) && p_belong(4, sq, tr, x, y))
								{
									SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
									SDL_RenderDrawPoint(renderer, x, y);
								}

							}
						}
						DrawClippingWindow(renderer, w);

						SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

						SDL_RenderFillRect(renderer, rect1);
						SDL_RenderFillRect(renderer, rect2);
						SDL_RenderFillRect(renderer, rect3);
						SDL_RenderFillRect(renderer, rect4);

						SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

						SDL_RenderPresent(renderer);

						break;

						break;
					case SDLK_w:

						Ty_SQ -= 10;

						SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
						SDL_RenderClear(renderer);

						SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
						Draw_SQUARE(renderer, sq, Tx_SQ, Ty_SQ, angle_SQ, sqxcenter, sqycenter);
						Draw_TRIANGLE(renderer, tr, Tx_TR, Ty_TR, angle_TR, trxcenter, trycenter);
						LOOK_AT_THIS_FUNC(sq, tr, Minx, Miny, Maxx, Maxy);



						for (double x = Minx; x < Maxx; x += 2)
						{
							for (double y = Miny; y < Maxy; y += 2)
							{
								if (Check(tr->x[0], tr->y[0], tr->x[1], tr->y[1], x, y) && p_belong(4, sq, tr, x, y))
								{
									SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
									SDL_RenderDrawPoint(renderer, x, y);
								}
								if (Check(tr->x[1], tr->y[1], tr->x[2], tr->y[2], x, y) && p_belong(4, sq, tr, x, y))
								{
									SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
									SDL_RenderDrawPoint(renderer, x, y);
								}
								if (Check(tr->x[2], tr->y[2], tr->x[0], tr->y[0], x, y) && p_belong(4, sq, tr, x, y))
								{
									SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
									SDL_RenderDrawPoint(renderer, x, y);
								}

							}
						}
						DrawClippingWindow(renderer, w);

						SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

						SDL_RenderFillRect(renderer, rect1);
						SDL_RenderFillRect(renderer, rect2);
						SDL_RenderFillRect(renderer, rect3);
						SDL_RenderFillRect(renderer, rect4);

						SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

						SDL_RenderPresent(renderer);

						break;

					case SDLK_s:

						Ty_SQ += 10;

						SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
						SDL_RenderClear(renderer);

						SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
						Draw_SQUARE(renderer, sq, Tx_SQ, Ty_SQ, angle_SQ, sqxcenter, sqycenter);
						Draw_TRIANGLE(renderer, tr, Tx_TR, Ty_TR, angle_TR, trxcenter, trycenter);
						LOOK_AT_THIS_FUNC(sq, tr, Minx, Miny, Maxx, Maxy);

						for (double x = Minx; x < Maxx; x += 2)
						{
							for (double y = Miny; y < Maxy; y += 2)
							{
								if (Check(tr->x[0], tr->y[0], tr->x[1], tr->y[1], x, y) && p_belong(4, sq, tr, x, y))
								{
									SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
									SDL_RenderDrawPoint(renderer, x, y);
								}
								if (Check(tr->x[1], tr->y[1], tr->x[2], tr->y[2], x, y) && p_belong(4, sq, tr, x, y))
								{
									SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
									SDL_RenderDrawPoint(renderer, x, y);
								}
								if (Check(tr->x[2], tr->y[2], tr->x[0], tr->y[0], x, y) && p_belong(4, sq, tr, x, y))
								{
									SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
									SDL_RenderDrawPoint(renderer, x, y);
								}

							}
						}
						DrawClippingWindow(renderer, w);

						SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

						SDL_RenderFillRect(renderer, rect1);
						SDL_RenderFillRect(renderer, rect2);
						SDL_RenderFillRect(renderer, rect3);
						SDL_RenderFillRect(renderer, rect4);

						SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

						SDL_RenderPresent(renderer);

						break;
					case SDLK_q:
						xy = intersect(sq->x[0], sq->y[0], sq->x[2], sq->y[2], sq->x[1], sq->y[1], sq->x[3], sq->y[3]);
						sqxcenter = intersect(sq->x[0], sq->y[0], sq->x[2], sq->y[2], sq->x[1], sq->y[1], sq->x[3], sq->y[3])[0];
						sqycenter = intersect(sq->x[0], sq->y[0], sq->x[2], sq->y[2], sq->x[1], sq->y[1], sq->x[3], sq->y[3])[1];
						angle_SQ += Pi / 180;
						SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
						SDL_RenderClear(renderer);

						SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
						Draw_SQUARE(renderer, sq, Tx_SQ, Ty_SQ, angle_SQ, sqxcenter, sqycenter);
						Draw_TRIANGLE(renderer, tr, Tx_TR, Ty_TR, angle_TR, trxcenter, trycenter);
						DrawClippingWindow(renderer, w);
						LOOK_AT_THIS_FUNC(sq, tr, Minx, Miny, Maxx, Maxy);

						for (double x = Minx; x < Maxx; x += 2)
						{
							for (double y = Miny; y < Maxy; y += 2)
							{
								if (Check(tr->x[0], tr->y[0], tr->x[1], tr->y[1], x, y) && p_belong(4, sq, tr, x, y))
								{
									SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
									SDL_RenderDrawPoint(renderer, x, y);
								}
								if (Check(tr->x[1], tr->y[1], tr->x[2], tr->y[2], x, y) && p_belong(4, sq, tr, x, y))
								{
									SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
									SDL_RenderDrawPoint(renderer, x, y);
								}
								if (Check(tr->x[2], tr->y[2], tr->x[0], tr->y[0], x, y) && p_belong(4, sq, tr, x, y))
								{
									SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
									SDL_RenderDrawPoint(renderer, x, y);
								}

							}
						}

						SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

						SDL_RenderFillRect(renderer, rect1);
						SDL_RenderFillRect(renderer, rect2);
						SDL_RenderFillRect(renderer, rect3);
						SDL_RenderFillRect(renderer, rect4);

						SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

						SDL_RenderPresent(renderer);
						angle_SQ = 0;

						break;
					case SDLK_e:
						sqxcenter = intersect(sq->x[0], sq->y[0], sq->x[2], sq->y[2], sq->x[1], sq->y[1], sq->x[3], sq->y[3])[0];
						sqycenter = intersect(sq->x[0], sq->y[0], sq->x[2], sq->y[2], sq->x[1], sq->y[1], sq->x[3], sq->y[3])[1];
						angle_SQ -= Pi / 180;
						SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
						SDL_RenderClear(renderer);

						SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
						Draw_SQUARE(renderer, sq, Tx_SQ, Ty_SQ, angle_SQ, sqxcenter, sqycenter);
						Draw_TRIANGLE(renderer, tr, Tx_TR, Ty_TR, angle_TR, trxcenter, trycenter);
						DrawClippingWindow(renderer, w);
						LOOK_AT_THIS_FUNC(sq, tr, Minx, Miny, Maxx, Maxy);

						for (double x = Minx; x < Maxx; x += 2)
						{
							for (double y = Miny; y < Maxy; y += 2)
							{
								if (Check(tr->x[0], tr->y[0], tr->x[1], tr->y[1], x, y) && p_belong(4, sq, tr, x, y))
								{
									SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
									SDL_RenderDrawPoint(renderer, x, y);
								}
								if (Check(tr->x[1], tr->y[1], tr->x[2], tr->y[2], x, y) && p_belong(4, sq, tr, x, y))
								{
									SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
									SDL_RenderDrawPoint(renderer, x, y);
								}
								if (Check(tr->x[2], tr->y[2], tr->x[0], tr->y[0], x, y) && p_belong(4, sq, tr, x, y))
								{
									SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
									SDL_RenderDrawPoint(renderer, x, y);
								}

							}
						}

						SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

						SDL_RenderFillRect(renderer, rect1);
						SDL_RenderFillRect(renderer, rect2);
						SDL_RenderFillRect(renderer, rect3);
						SDL_RenderFillRect(renderer, rect4);

						SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

						SDL_RenderPresent(renderer);
						angle_SQ = 0;

						break;
					case SDLK_RIGHT:
						Tx_TR += 10;
						SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
						SDL_RenderClear(renderer);

						SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
						Draw_TRIANGLE(renderer, tr, Tx_TR, Ty_TR, angle_TR, trxcenter, trycenter);


						DrawClippingWindow(renderer, w);

						Draw_SQUARE(renderer, sq, Tx_SQ, Ty_SQ, angle_SQ, sqxcenter, sqycenter);
						LOOK_AT_THIS_FUNC(sq, tr, Minx, Miny, Maxx, Maxy);

						for (double x = Minx; x < Maxx; x += 2)
						{
							for (double y = Miny; y < Maxy; y += 2)
							{
								if (Check(tr->x[0], tr->y[0], tr->x[1], tr->y[1], x, y) && p_belong(4, sq, tr, x, y))
								{
									SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
									SDL_RenderDrawPoint(renderer, x, y);
								}
								if (Check(tr->x[1], tr->y[1], tr->x[2], tr->y[2], x, y) && p_belong(4, sq, tr, x, y))
								{
									SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
									SDL_RenderDrawPoint(renderer, x, y);
								}
								if (Check(tr->x[2], tr->y[2], tr->x[0], tr->y[0], x, y) && p_belong(4, sq, tr, x, y))
								{
									SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
									SDL_RenderDrawPoint(renderer, x, y);
								}

							}
						}

						SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

						SDL_RenderFillRect(renderer, rect1);
						SDL_RenderFillRect(renderer, rect2);
						SDL_RenderFillRect(renderer, rect3);
						SDL_RenderFillRect(renderer, rect4);

						SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

						SDL_RenderPresent(renderer);


						break;
					case SDLK_LEFT:
						Tx_TR -= 10;
						SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
						SDL_RenderClear(renderer);

						SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
						Draw_TRIANGLE(renderer, tr, Tx_TR, Ty_TR, angle_TR, trxcenter, trycenter);
						Draw_SQUARE(renderer, sq, Tx_SQ, Ty_SQ, angle_SQ, sqxcenter, sqycenter);
						LOOK_AT_THIS_FUNC(sq, tr, Minx, Miny, Maxx, Maxy);

						for (double x = Minx; x < Maxx; x += 2)
						{
							for (double y = Miny; y < Maxy; y += 2)
							{
								if (Check(tr->x[0], tr->y[0], tr->x[1], tr->y[1], x, y) && p_belong(4, sq, tr, x, y))
								{
									SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
									SDL_RenderDrawPoint(renderer, x, y);
								}
								if (Check(tr->x[1], tr->y[1], tr->x[2], tr->y[2], x, y) && p_belong(4, sq, tr, x, y))
								{
									SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
									SDL_RenderDrawPoint(renderer, x, y);
								}
								if (Check(tr->x[2], tr->y[2], tr->x[0], tr->y[0], x, y) && p_belong(4, sq, tr, x, y))
								{
									SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
									SDL_RenderDrawPoint(renderer, x, y);
								}

							}
						}
						DrawClippingWindow(renderer, w);

						SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

						SDL_RenderFillRect(renderer, rect1);
						SDL_RenderFillRect(renderer, rect2);
						SDL_RenderFillRect(renderer, rect3);
						SDL_RenderFillRect(renderer, rect4);

						SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

						SDL_RenderPresent(renderer);


						break;
					case SDLK_UP:
						Ty_TR -= 10;
						SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
						SDL_RenderClear(renderer);

						SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
						Draw_TRIANGLE(renderer, tr, Tx_TR, Ty_TR, angle_TR, trxcenter, trycenter);
						Draw_SQUARE(renderer, sq, Tx_SQ, Ty_SQ, angle_SQ, sqxcenter, sqycenter);
						LOOK_AT_THIS_FUNC(sq, tr, Minx, Miny, Maxx, Maxy);

						for (double x = Minx; x < Maxx; x += 2)
						{
							for (double y = Miny; y < Maxy; y += 2)
							{
								if (Check(tr->x[0], tr->y[0], tr->x[1], tr->y[1], x, y) && p_belong(4, sq, tr, x, y))
								{
									SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
									SDL_RenderDrawPoint(renderer, x, y);
								}
								if (Check(tr->x[1], tr->y[1], tr->x[2], tr->y[2], x, y) && p_belong(4, sq, tr, x, y))
								{
									SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
									SDL_RenderDrawPoint(renderer, x, y);
								}
								if (Check(tr->x[2], tr->y[2], tr->x[0], tr->y[0], x, y) && p_belong(4, sq, tr, x, y))
								{
									SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
									SDL_RenderDrawPoint(renderer, x, y);
								}

							}
						}
						DrawClippingWindow(renderer, w);

						SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

						SDL_RenderFillRect(renderer, rect1);
						SDL_RenderFillRect(renderer, rect2);
						SDL_RenderFillRect(renderer, rect3);
						SDL_RenderFillRect(renderer, rect4);

						SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

						SDL_RenderPresent(renderer);


						break;
					case SDLK_DOWN:
						Ty_TR += 10;
						SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
						SDL_RenderClear(renderer);

						SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
						Draw_TRIANGLE(renderer, tr, Tx_TR, Ty_TR, angle_TR, trxcenter, trycenter);
						Draw_SQUARE(renderer, sq, Tx_SQ, Ty_SQ, angle_SQ, sqxcenter, sqycenter);
						LOOK_AT_THIS_FUNC(sq, tr, Minx, Miny, Maxx, Maxy);

						for (double x = Minx; x < Maxx; x += 2)
						{
							for (double y = Miny; y < Maxy; y += 2)
							{
								if (Check(tr->x[0], tr->y[0], tr->x[1], tr->y[1], x, y) && p_belong(4, sq, tr, x, y))
								{
									SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
									SDL_RenderDrawPoint(renderer, x, y);
								}
								if (Check(tr->x[1], tr->y[1], tr->x[2], tr->y[2], x, y) && p_belong(4, sq, tr, x, y))
								{
									SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
									SDL_RenderDrawPoint(renderer, x, y);
								}
								if (Check(tr->x[2], tr->y[2], tr->x[0], tr->y[0], x, y) && p_belong(4, sq, tr, x, y))
								{
									SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
									SDL_RenderDrawPoint(renderer, x, y);
								}

							}
						}
						DrawClippingWindow(renderer, w);

						SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

						SDL_RenderFillRect(renderer, rect1);
						SDL_RenderFillRect(renderer, rect2);
						SDL_RenderFillRect(renderer, rect3);
						SDL_RenderFillRect(renderer, rect4);

						SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

						SDL_RenderPresent(renderer);


						break;
					case SDLK_n:
						trxcenter = tr->x[1];
						trycenter = tr->y[1];
						angle_TR += Pi / 180;
						SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
						SDL_RenderClear(renderer);

						SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
						Draw_SQUARE(renderer, sq, Tx_SQ, Ty_SQ, angle_SQ, sqxcenter, sqycenter);
						Draw_TRIANGLE(renderer, tr, Tx_TR, Ty_TR, angle_TR, trxcenter, trycenter);
						LOOK_AT_THIS_FUNC(sq, tr, Minx, Miny, Maxx, Maxy);

						for (double x = Minx; x < Maxx; x += 2)
						{
							for (double y = Miny; y < Maxy; y += 2)
							{
								if (Check(tr->x[0], tr->y[0], tr->x[1], tr->y[1], x, y) && p_belong(4, sq, tr, x, y))
								{
									SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
									SDL_RenderDrawPoint(renderer, x, y);
								}
								if (Check(tr->x[1], tr->y[1], tr->x[2], tr->y[2], x, y) && p_belong(4, sq, tr, x, y))
								{
									SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
									SDL_RenderDrawPoint(renderer, x, y);
								}
								if (Check(tr->x[2], tr->y[2], tr->x[0], tr->y[0], x, y) && p_belong(4, sq, tr, x, y))
								{
									SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
									SDL_RenderDrawPoint(renderer, x, y);
								}

							}
						}

						SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

						SDL_RenderFillRect(renderer, rect1);
						SDL_RenderFillRect(renderer, rect2);
						SDL_RenderFillRect(renderer, rect3);
						SDL_RenderFillRect(renderer, rect4);

						SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

						DrawClippingWindow(renderer, w);


						SDL_RenderPresent(renderer);
						angle_TR = 0;
						break;
					case SDLK_m:
						trxcenter = tr->x[1];
						trycenter = tr->y[1];
						angle_TR -= Pi / 180;
						SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
						SDL_RenderClear(renderer);

						SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
						Draw_TRIANGLE(renderer, tr, Tx_TR, Ty_TR, angle_TR, trxcenter, trycenter);
						Draw_SQUARE(renderer, sq, Tx_SQ, Ty_SQ, angle_SQ, sqxcenter, sqycenter);
						LOOK_AT_THIS_FUNC(sq, tr, Minx, Miny, Maxx, Maxy);

						for (double x = Minx; x < Maxx; x += 2)
						{
							for (double y = Miny; y < Maxy; y += 2)
							{
								if (Check(tr->x[0], tr->y[0], tr->x[1], tr->y[1], x, y) && p_belong(4, sq, tr, x, y))
								{
									SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
									SDL_RenderDrawPoint(renderer, x, y);
								}
								if (Check(tr->x[1], tr->y[1], tr->x[2], tr->y[2], x, y) && p_belong(4, sq, tr, x, y))
								{
									SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
									SDL_RenderDrawPoint(renderer, x, y);
								}
								if (Check(tr->x[2], tr->y[2], tr->x[0], tr->y[0], x, y) && p_belong(4, sq, tr, x, y))
								{
									SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
									SDL_RenderDrawPoint(renderer, x, y);
								}

							}
						}

						DrawClippingWindow(renderer, w);

						SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

						SDL_RenderFillRect(renderer, rect1);
						SDL_RenderFillRect(renderer, rect2);
						SDL_RenderFillRect(renderer, rect3);
						SDL_RenderFillRect(renderer, rect4);

						SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

						SDL_RenderPresent(renderer);
						angle_TR = 0;
						break;

					}


					sqxcenter = 0;
					sqycenter = 0;
					trxcenter = 0;
					trycenter = 0;
					Tx_SQ = 0;
					Ty_SQ = 0;
					Tx_TR = 0;
					Ty_TR = 0;
					break;


				}

			}

		}

		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();

		return 0;
	}
}