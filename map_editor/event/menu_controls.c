/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:53:31 by aruiz-ba          #+#    #+#             */
/*   Updated: 2020/03/10 17:10:05 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/map_editor.h"

void			set_mous_loop(t_mouse *mous, int i)
{
	if (i == 12)
		return ;
	mous->loop = i;
}

void			ft_menu_event(t_mouse *mous, SDL_Event e)
{
	int			tmx;
	int			tmy;
	int			x;
	int			y;
	int			i;

	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		if (e.button.button == SDL_BUTTON_LEFT)
		{
			SDL_GetMouseState(&tmx, &tmy);
			if (tmx >= 1120 && tmx <= 1355 && tmy >= 120 && tmy <= 600)
			{
				x = (tmx - 1120) / 80;
				y = (tmy - 120) / 80;
				i = y * 3 + x + 1;
				set_mous_loop(mous, i);
			}
			if (tmx >= 1120 && tmx <= 1350 && tmy >= 650 && tmy <= 762)
				set_mous_loop(mous, 0);
			if (tmx >= 1120 && tmx <= 1350 && tmy >= 782 && tmy <= 894)
				set_mous_loop(mous, -1);
		}
	}
}
