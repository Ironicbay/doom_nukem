/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 12:22:59 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/03/04 19:52:12 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/map_editor.h"

void		ft_origin(t_map *map)
{
	map->ox = (1120 - ((map->x) * map->base_gap)) / 2;
	map->oy = (HEIGHT - ((map->y) * map->base_gap)) / 2;
}

float		ft_height(t_map *map)
{
	float	height;

	if (map->zmax >= 1 && map->zmax < 50)
		height = 50 / map->base_gap;
	else if (map->zmax >= 50 && map->zmax < 100)
		height = 10 / map->base_gap;
	else if (map->zmax >= 100 && map->zmax < 500)
		height = 1 / (2 * map->base_gap);
	//if (map->zmax >= 500)
	else
		height = 1 / (10 * map->base_gap);
	return (height);
}

int			ft_gap(t_map *map)
{
	int		gap_H;
	int		gap_W;

	gap_H = (HEIGHT * 0.9) / map->y;
	gap_W = (1120 * 0.9) / map->x;
	if (gap_H > gap_W)
		return (gap_W);
	else
		return (gap_H);
}
