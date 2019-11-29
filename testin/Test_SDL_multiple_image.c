/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test_SDL_multiple_image.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:17:47 by jmoucach          #+#    #+#             */
/*   Updated: 2019/11/01 17:53:42 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../SDL2/Headers/SDL.h"
#include "test_header.h"
#include <stdio.h>

short init(SDL_Window **win, SDL_Surface **surf)
{
	short success;
	success = 1;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = 0;
	}
	else
	{
		*win = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
								SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (*win == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = 0;
		}
		else
			*surf = SDL_GetWindowSurface(*win);
	}
	return (success);
}

SDL_Surface *LoadSurface(char *path)
{
	SDL_Surface *LoadedSurface;

	LoadedSurface = SDL_LoadBMP(path);
	if (LoadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", path, SDL_GetError());
	}
	return (LoadedSurface);
}

short loadmedia(SDL_Surface *KeyPressSurfaces[])
{
	short success;

	success = 1;
	KeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] = LoadSurface("down.bmp");
	if (KeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] == NULL)
		success = 0;
	KeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] = LoadSurface("left.bmp");
	if (KeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] == NULL)
		success = 0;
	KeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] = LoadSurface("right.bmp");
	if (KeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] == NULL)
		success = 0;
	KeyPressSurfaces[KEY_PRESS_SURFACE_UP] = LoadSurface("up.bmp");
	if (KeyPressSurfaces[KEY_PRESS_SURFACE_UP] == NULL)
		success = 0;
	KeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] = LoadSurface("press.bmp");
	if (KeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] == NULL)
		success = 0;
	return success;
}

void close_all(SDL_Surface **surface, SDL_Window **window)
{
	SDL_FreeSurface(*surface);
	*surface = NULL;

	//Destroy window
	SDL_DestroyWindow(*window);
	*window = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

int main(int ac, char **av)
{
	SDL_Window *window = NULL;
	SDL_Surface *screenSurface = NULL;
	SDL_Surface *LoadedSurfaces[KEY_PRESS_SURFACE_TOTAL];
	SDL_Surface *CurrentSurface = NULL;
	short quit;
	SDL_Event e;

	quit = 0;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		if (init(&window, &screenSurface))
		{
			loadmedia(LoadedSurfaces);
			CurrentSurface = LoadedSurfaces[KEY_PRESS_SURFACE_DEFAULT];
			while (!quit)
			{
				while (SDL_PollEvent(&e))
				{
					if (e.type == SDL_QUIT)
						quit = 1;
					if (e.type == SDL_KEYDOWN)
					{
						if (e.key.keysym.sym == SDLK_DOWN)
							CurrentSurface = LoadedSurfaces[KEY_PRESS_SURFACE_DOWN];
						else if (e.key.keysym.sym == SDLK_LEFT)
							CurrentSurface = LoadedSurfaces[KEY_PRESS_SURFACE_LEFT];
						else if (e.key.keysym.sym == SDLK_RIGHT)
							CurrentSurface = LoadedSurfaces[KEY_PRESS_SURFACE_RIGHT];
						else if (e.key.keysym.sym == SDLK_UP)
							CurrentSurface = LoadedSurfaces[KEY_PRESS_SURFACE_UP];
						else
							CurrentSurface = LoadedSurfaces[KEY_PRESS_SURFACE_DEFAULT];
					}
				}
				SDL_BlitScaled(CurrentSurface, NULL, screenSurface, NULL);
				SDL_UpdateWindowSurface(window);
			}
		}
		else
		{
			printf("Failed to load media");
		}
	}
	close_all(&screenSurface, &window);
	return (1);
}
