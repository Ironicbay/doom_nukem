/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 17:04:47 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/03/04 19:46:29 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/map_editor.h"

void		ft_free_map(t_map *map)
{
	int		i;

	i = -1;
	while (++i < map->y)
		free(map->map[i]);
	free(map);
}

void		ft_free_fdf(t_fdf *fdf)
{
	ft_free_map(fdf->map);
	free(fdf);
}

void		ft_free_line(t_line *list)
{
	t_line	*tmp;

	while (list != NULL)
	{
		tmp = list;
		list = list->next;
		free(tmp->str);
		free(tmp);
	}
	free(list);
}
/*
static void	free_surfaces(t_data *data)
{
	int	i;
	if (data->surface && (i = -1))
	{
		while (++i < 20)
			if (data->surface[i])
				SDL_FreeSurface(data->surface[i]);
		free(data->surface);
	}
}*/

static void	ft_free_textures(t_fdf *img)
{
	int		i;

	i = 0;
	if (img->texture)
	{
		while (++i < 21)
		{
			if (img->texture[i] != NULL)
				SDL_DestroyTexture(img->texture[i]);
			img->texture[i] = NULL;
		}
		free(img->texture);
	}	
}

void		ft_clean_exit(t_fdf *img, char *err)
{
	if (err)
		ft_putendl_fd(err, 2);
	ft_putendl("Ok1");
	ft_free_textures(img);
	ft_putendl("Ok2");
	if (img->grid != NULL)
		SDL_DestroyTexture(img->grid);
	ft_putendl("Ok3");
	if (img->renderer != NULL)
		SDL_DestroyRenderer(img->renderer);
	ft_putendl("Ok4");
	if (img->pixels != NULL)
		free(img->pixels);
	ft_putendl("Ok5");
	if (img->window)
		SDL_DestroyWindow(img->window);
	ft_putendl("Ok6");
	if (TTF_WasInit())
		TTF_Quit();
	ft_putendl("Ok7");
	if (SDL_WasInit(SDL_INIT_VIDEO) & SDL_INIT_VIDEO)
		SDL_Quit();
	ft_putendl("Ok8");
	if (err)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
	ft_putendl("Ok9");
}
