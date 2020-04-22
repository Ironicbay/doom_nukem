/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:22:53 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/03/10 19:19:38 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/map_editor.h"

SDL_Texture		*loadimage(char *path, t_fdf *img)
{
	SDL_Surface *loadedsurface;
	SDL_Texture	*texture;

	loadedsurface = SDL_LoadBMP(path);
	if (!loadedsurface)
	{
		ft_putendl_fd(SDL_GetError(), 2);
		return (NULL);
	}
	if (!(texture = SDL_CreateTextureFromSurface(img->renderer, loadedsurface)))
		{
			SDL_FreeSurface(loadedsurface);//NEWLY ADDED
			ft_clean_exit(img, (char *)SDL_GetError);//NEWLY ADDED
		}
	SDL_FreeSurface(loadedsurface);
	return (texture);
}

char			**path_to_textures(void)
{
	char		**path_tab;

	if (!(path_tab = malloc(sizeof(char *) * 22)))
		return (NULL);
	path_tab[0] = NULL;
	path_tab[1] = ft_strdup("../pics/bluestone.bmp");
	path_tab[2] = ft_strdup("../pics/greystone.bmp");
	path_tab[3] = ft_strdup("../pics/mossy.bmp");
	path_tab[4] = ft_strdup("../pics/tile2.bmp");
	path_tab[5] = ft_strdup("../pics/wood.bmp");
	path_tab[6] = ft_strdup("../pics/redbrick.bmp");
	path_tab[7] = ft_strdup("../sprites/doom_guy_face.bmp");
	path_tab[8] = ft_strdup("../sprites/enemy_face.bmp");
	path_tab[9] = ft_strdup("../sprites/soul_button.bmp");
	path_tab[10] = ft_strdup("../sprites/boss_button.bmp");
	path_tab[11] = ft_strdup("../pics/keydoor.bmp");
	path_tab[12]= ft_strdup("../pics/pillar.bmp");//could also not load anything, but then it will return NULL and will cause trouble
	path_tab[13] = ft_strdup("../sprites/shells_button.bmp");
	path_tab[14] = ft_strdup("../sprites/bullets_button.bmp");
	path_tab[15] = ft_strdup("../sprites/cell_button.bmp");
	path_tab[16] = ft_strdup("../sprites/health_button.bmp");
	path_tab[17] = ft_strdup("../sprites/key_button.bmp");
	path_tab[18] = ft_strdup("../sprites/pickups/armor_pu.bmp");
	path_tab[19] = ft_strdup("../sprites/delete.bmp");
	path_tab[20] = ft_strdup("../sprites/save.bmp");
	path_tab[21] = NULL;
	return (path_tab);
}

short			loadmedia(t_fdf *img)
{
	int			i;
	char		**path_tab;

	i = 0;
	path_tab = path_to_textures();
	img->texture[0] = NULL;
	while (++i <= 20)
	{
		img->texture[i] = loadimage(path_tab[i], img); //loadimage
		if (!img->texture[i])
		{
			free_tab(path_tab);
			ft_clean_exit(img, "Could not load all textures");
			return (0);
		}
	}
	free_tab(path_tab);
	return (1);
}
