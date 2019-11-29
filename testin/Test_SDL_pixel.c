#include "../SDL2/Headers/SDL.h"
#include "test_header.h"
#include <stdio.h>
#include <math.h>

short init(SDL_Window **win, SDL_Renderer **renderer, SDL_Texture **texture)
{
	short success;

	success = 1;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Failed to initialize! Error: %s", SDL_GetError());
	}
	else
	{
		*win = SDL_CreateWindow("Pixel", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (*win == NULL)
		{
			success = 0;
			printf("Failed to create window! Error: %s", SDL_GetError());
		}
		else
		{
			*renderer = SDL_CreateRenderer(*win, -1, 0);
			*texture = SDL_CreateTexture(*renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH, SCREEN_HEIGHT);
		}
	}
	return (success);
}

Uint32 *drawLine(t_pt pt_one, t_pt pt_two, Uint32 *pixels)
{
	Uint32 *pix;
	t_pt d;
	t_pt pt;
	t_pt inc;
	int error;
	int off;

	inc.x = (pt_one.x < pt_two.x ? 1 : -1);
	inc.y = (pt_one.y < pt_two.y ? 1 : -1);
	d.x = abs(pt_two.x - pt_one.x);
	d.y = abs(pt_two.y - pt_one.y);
	off = d.x - d.y;
	pix = pixels;
	pt = pt_one;

	while (pt.x != pt_two.x || pt.y != pt_two.y)
	{
		pix[pt.x + pt.y * SCREEN_WIDTH] = 0;
		if ((error = off * 2) > -d.y)
		{
			off -= d.y;
			pt.x += inc.x;
		}
		if (error <= d.x)
		{
			off += d.x;
			pt.y += inc.y;
		}
	}
	pix[pt.x + pt.y * SCREEN_WIDTH] = 0;
	return (pix);
}

int main(int ac, char **av)
{
	SDL_Window *window = NULL;
	short quit;
	SDL_Event e;
	SDL_Renderer *renderer = NULL;
	SDL_Texture *texture = NULL;
	short lmbDown;
	t_pt prev_point;
	t_pt actual_point;
	Uint32 *pixels;

	pixels = (Uint32 *)malloc(sizeof(Uint32) * SCREEN_WIDTH * SCREEN_HEIGHT);
	lmbDown = 0;
	quit = 0;
	prev_point.x = 0;
	prev_point.y = 0;

	if (init(&window, &renderer, &texture) == 1)
	{
		memset(pixels, 255, SCREEN_HEIGHT * SCREEN_HEIGHT * sizeof(Uint32));
		while (!quit)
		{
			while (SDL_PollEvent(&e))
			{
				if (e.type == SDL_QUIT)
					quit = 1;
				if (e.type == SDL_MOUSEBUTTONDOWN)
					if (e.button.button == SDL_BUTTON_LEFT)
						lmbDown = 1;
				if (e.type == SDL_MOUSEBUTTONUP)
					if (e.button.button == SDL_BUTTON_LEFT)
					{
						prev_point.x = 0;
						prev_point.y = 0;
						lmbDown = 0;
					}
				if (e.type == SDL_MOUSEMOTION)
					if (lmbDown == 1)
					{
						actual_point.x = e.motion.x;
						actual_point.y = e.motion.y;
						if ((prev_point.x > actual_point.x + 1 || prev_point.y > actual_point.y + 1
						|| prev_point.x < actual_point.x - 1 || prev_point.y < actual_point.y - 1)
						&& prev_point.x != 0 && prev_point.y != 0)
							drawLine(prev_point, actual_point, pixels);
						pixels[actual_point.x + actual_point.y * SCREEN_WIDTH] = 0;
						prev_point.x = actual_point.x;
						prev_point.y = actual_point.y;
					}
			}
			SDL_UpdateTexture(texture, NULL, pixels, SCREEN_WIDTH * sizeof(Uint32));
			SDL_RenderClear(renderer);
			SDL_RenderCopy(renderer, texture, NULL, NULL);
			SDL_RenderPresent(renderer);
		}
	}
	free(pixels);
	SDL_DestroyTexture(texture);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return (1);
}