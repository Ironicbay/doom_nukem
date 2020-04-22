/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infinite_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:10:12 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/03/06 14:54:12 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/map_editor.h"

void			ft_infinite_loop(t_fdf *img, t_mouse *mous)
{
	int			isquit;
	SDL_Event	event;

	isquit = 0;
	while (isquit == 0)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				isquit = 1;
			ft_menu_event( mous, event);
			ft_keys_event(img, event);
			ft_mouse_event(img, mous, event);
		}
		ft_clear_and_render(img, mous->loop);
	}
}

void		ft_fdf(t_map *map, char *map_name)
{
	t_fdf	*img;
	t_mouse	mous;
	t_key	key;

	if (!(img = ft_ptr_init(map_name)))
		ft_clean_exit(img, "Problems during main structure creation");
	if (!(ft_mouse_init(&mous)) || !(ft_key_init(&key)))
		ft_clean_exit(img, "Problems during mouse or key initilization");
	img->map = map;
	ft_clear_and_render(img, mous.loop);
	ft_infinite_loop(img, &mous);
}
