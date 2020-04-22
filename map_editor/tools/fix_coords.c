/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_coords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 13:34:16 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/03/09 14:25:12 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/map_editor.h"

void		ft_sub_fix_coords(t_map *map, int *x, int *y)
{
	int		tempx;
	int		tempy;
	int		crossx;
	int		crossy;

	tempx = *x - map->ox;
	tempy = *y - map->oy;
	crossx = tempx / map->base_gap;
	crossy = tempy / map->base_gap;
	*x = crossx; 
	*y = crossy; 
}

void		ft_fix_coords(t_map *map, int *x, int *y)
{
//	printf("original x = %d\n original y = %d\n ox = %d\n oy = %d\n endx = %d\n endy = %d\n", *x, *y, map->ox, map->oy, map->endx, map->endy);
	if (*x < map->ox)
		*x = map->ox;
	if (*y < map->oy)
		*y = map->oy;
	if (*x > map->endx)
		*x = map->endx;
	if (*y > map->endy)
		*y = map->endy;
	ft_sub_fix_coords(map, x, y);
}

t_pt		coord_to_pt(int x, int y)
{
	t_pt	point;

	point.x = x;
	point.y = y;
	return (point);
}

void		mk_point_and_trace_line(int x1, int y1, int x2, int y2, t_fdf *img)
{
	t_pt	start;
	t_pt	end;

	start = coord_to_pt(x1, y1);
	end = coord_to_pt(x2, y2);
	ft_calculate_grid_coord_and_draw_line(start, end, img, WHITE);
}