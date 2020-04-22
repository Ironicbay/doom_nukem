/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:49:15 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/03/06 14:34:43 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/map_editor.h"

void			ft_print_menu_background(t_fdf *img)
{
	//SDL_Color	color;
	int		i;
	t_pt		start;
	t_pt		end;

	i = -1;
	while (++i < 270)
	{
		start = coord_to_pt((WIDTH - 300) + i, 0);
		end = coord_to_pt(start.x, HEIGHT - 1);
		//start = coord_to_pt(0, 0);
		//end = coord_to_pt(100, 100);
		draw_line(start, end, img->pixels, 0x2E2E2E);
	}
}

void			initialize_and_write_lines(t_fdf *img, int loop)
{
	ft_bzero(img->pixels, WIDTH * HEIGHT * sizeof(Uint32));
	ft_print_grid(img);
	if (!img->grid)
		{
			if (!(img->grid = SDL_CreateTexture(img->renderer,
			SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, WIDTH,
			HEIGHT)))
			ft_clean_exit(img, (char *)SDL_GetError());
		}
	draw_menu_squares(img);
	ft_print_pressed_button(img, loop);
}
void			ft_clear_and_render(t_fdf *img, int	loop)
{
	//IN THIS FIRST PART WE PRINT LINES
	initialize_and_write_lines(img, loop);
	/* Moved in function initialize_and_... right above
	ft_bzero(img->pixels, WIDTH * HEIGHT * sizeof(Uint32));
	ft_print_grid(img);
	if (!img->grid)
		{
			if (!(img->grid = SDL_CreateTexture(img->renderer,
			SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, WIDTH,
			HEIGHT)))
			ft_clean_exit(img, (char *)SDL_GetError());
		}
	draw_menu_squares(img);
	ft_print_pressed_button(img, loop);*/
	SDL_UpdateTexture(img->grid, NULL, img->pixels, WIDTH * 4);
	SDL_RenderCopy(img->renderer, img->grid, NULL, NULL);

	//IN THIS SECOND PART WE PRINT TEXTURES
	ft_parse_and_print_textures(img);
	draw_menu_textures(img);
	//ft_print_menu_background(img);
	//SDL_RenderClear(img->renderer);//whole screen is white if uncommented
	//SDL_SetRenderDrawColor(img->renderer, 0, 0, 0, 0);
	SDL_RenderPresent(img->renderer);
	SDL_RenderClear(img->renderer);
}
