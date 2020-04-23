/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_appearance.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 20:01:06 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/03/05 18:47:03 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/map_editor.h"

void		ft_zoom(t_key *key, t_map *map)
{
	if (key->zoom_in == 1)
		map->base_gap += 1;
	if (key->zoom_out == 1)
	{
		if (map->base_gap >= 1)
			map->base_gap -= 1;
	}
}

void		ft_move(t_key *key, t_map *map)
{
	if (key->up == 1)
		map->oy -= 3;
	if (key->down == 1)
		map->oy += 3;
	if (key->left == 1)
		map->ox -= 3;
	if (key->right == 1)
		map->ox += 3;
}
