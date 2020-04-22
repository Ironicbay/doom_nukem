/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 13:29:46 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/03/05 18:41:37 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/map_editor.h"

/*COMMENTED BECAUSE WE REMOVED THE POSSIBILITIES TO ZOOM AND MOVE BECAUSE IT WAS CAUSING TOO MANY ERRORS
void		key_press(t_fdf *img, t_key *key, SDL_Event e)
{
	if (e.type == SDL_KEYDOWN)
	{ 
		if (e.key.keysym.sym == SDLK_UP)
			key->up = 1;
		if (e.key.keysym.sym == SDLK_DOWN)
			key->down = 1;
		if (e.key.keysym.sym == SDLK_LEFT)
			key->left = 1;
		if (e.key.keysym.sym == SDLK_RIGHT)
			key->right = 1;
		if (e.key.keysym.sym == ZOOM_IN)
			key->zoom_in = 1;
		if (e.key.keysym.sym == ZOOM_OUT)
			key->zoom_out = 1;
		if (e.key.keysym.sym == 27)
			ft_clean_exit(img, "You pushed esc");
	}
}

void		key_release(t_key *key, SDL_Event e)
{
	if (e.type == SDL_KEYUP)
	{ 
		if (e.key.keysym.sym == SDLK_UP)
			key->up = 0;
		if (e.key.keysym.sym == SDLK_DOWN)
			key->down = 0;
		if (e.key.keysym.sym == SDLK_LEFT)
			key->left = 0;
		if (e.key.keysym.sym == SDLK_RIGHT)
			key->right = 0;
		if (e.key.keysym.sym == ZOOM_IN)
			key->zoom_in = 0;
		if (e.key.keysym.sym == ZOOM_OUT)
			key->zoom_out = 0;
	}
}
*/
void		ft_keys_event(t_fdf *img, SDL_Event e/*, t_key *key*/)
{
	if (e.type == SDL_KEYDOWN)
	{
		if (e.key.keysym.sym == 27)
			ft_clean_exit(img, "You pushed esc");
	}
	/*COMMENTED BECAUSE WE REMOVED THE POSSIBILITIES TO ZOOM AND MOVE BECAUSE IT WAS CAUSING TOO MANY ERRORS
	key_press(img, key, e);
	key_release(key, e);
	ft_move(key, img->map);
	ft_zoom(key, img->map);

	if (e.type == SDL_KEYDOWN)
	{
		img->map->endx = img->map->ox + ((img->map->x - 1) * img->map->base_gap);
		img->map->endy = img->map->oy + ((img->map->y - 1) * img->map->base_gap);
	}*/
}
