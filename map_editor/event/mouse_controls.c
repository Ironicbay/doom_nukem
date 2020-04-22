/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 14:38:23 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/03/08 20:09:48 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/map_editor.h" 

/* void			ft_put_point(t_fdf *img, t_map *map, t_mouse *mous)
{
	SDL_SetRenderDrawColor(img->renderer, 0, 255, 0, 255);
	SDL_RenderDrawLine(img->renderer, mous->click1[0], mous->click1[1], mous->click2[0], mous->click2[1]); }*/

int				ft_even_odd(int i)
{
	if (i % 2 == 0)
		return (0);
	return (1);
}
/*
void			loop_til_release()
{
	int			isquit;
	SDL_Event	e;

	isquit = 0;
	ft_putendl("amhere");
	while (isquit == 0)
	{
		if (SDL_PollEvent(&e)) 
		{
			if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
				exit (0);
			if (e.type == SDL_MOUSEBUTTONUP)
			{
				ft_putendl("buttonup");
				break;
			}
		}
	}
	
}
*/
/*
** We'll need to change this function to return int and print error messages if an action does not work" 
* <= DO WE??
*/
void			ft_mouse_event(t_fdf *img, t_mouse *mous, SDL_Event e)
{
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		if (e.button.button == SDL_BUTTON_LEFT)
		{
			if (mous->loop == -1)
				ft_save_map(img);
			else
				/*error = */click_to_modify_map(img->map, mous);
		}
	}
//	return (ft_error_fd(error));
}
