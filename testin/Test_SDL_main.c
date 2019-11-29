/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test_SDL_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:17:47 by jmoucach          #+#    #+#             */
/*   Updated: 2019/11/01 17:53:41 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../SDL2/Headers/SDL.h"
#include "test_header.h"

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

short loadmedia(SDL_Surface **LoadedMedia)
{
	short success;
	success = 1;

	if (*LoadedMedia == NULL)
	{
		*LoadedMedia = SDL_LoadBMP("hello_world.bmp");
		if (*LoadedMedia == NULL)
		{
			printf("Unable to load image %s! SDL Error: %s\n", "hello_world.bmp", SDL_GetError());
			success = 0;
		}
	}
	return (success);
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
	SDL_Surface *LoadedSurface = NULL;
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
			if (loadmedia(&LoadedSurface))
			{
				while (!quit)
				{
					while (SDL_PollEvent(&e))
					{
						if (e.type == SDL_QUIT)
							quit = 1;
					}
					SDL_BlitScaled(LoadedSurface, NULL, screenSurface, NULL);
					SDL_UpdateWindowSurface(window);
				}
			}
			else
			{
				printf("Failed to load media");
			}
		}
	}
	close_all(&screenSurface, &window);
	return (1);
}
