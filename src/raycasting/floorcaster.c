/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floorcaster.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:51:01 by jmoucach          #+#    #+#             */
/*   Updated: 2019/11/26 15:22:53 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/wolf3d.h"

void			floor_side(t_floorcast *f, t_raycast *r)
{
	if (r->side == 0 && r->ray.dir.x > 0)
	{
		f->floor.x = r->m_pos.x;
		f->floor.y = r->m_pos.y + r->wall;
	}
	else if (r->side == 0 && r->ray.dir.x < 0)
	{
		f->floor.x = r->m_pos.x + 1.0;
		f->floor.y = r->m_pos.y + r->wall;
	}
	else if (r->side == 1 && r->ray.dir.y > 0)
	{
		f->floor.x = r->m_pos.x + r->wall;
		f->floor.y = r->m_pos.y;
	}
	else
	{
		f->floor.x = r->m_pos.x + r->wall;
		f->floor.y = r->m_pos.y + 1.0;
	}
}

void			roofcaster(t_data *data, t_raycast *r, int x)
{
	t_floorcast	f;
	int			y;
	int			color;

	y = r->drawstart;
	f.currentdist = 0;
	floor_side(&f, r);
	while (y > 0)
	{
		f.currentdist = (double)SCREEN_HEIGHT / -(double)(2 * y
			- (SCREEN_HEIGHT + data->yaw) + 1);
		f.weight = f.currentdist / r->walldist;
		f.currentfloor.x = f.weight * f.floor.x
			+ (1 - f.weight) * data->p.pos.x;
		f.currentfloor.y = f.weight * f.floor.y
			+ (1 - f.weight) * data->p.pos.y;
		f.floortex.x = (int)(f.currentfloor.x * data->surface[5]->w)
														% data->surface[5]->w;
		f.floortex.y = (int)(f.currentfloor.y * data->surface[5]->h)
														% data->surface[5]->h;
		color = (get_pixel(data->surface[5], f.floortex.x, f.floortex.y));
		data->pixels[x + y * SCREEN_WIDTH] = color;
		y--;
	}
}

void			floorcaster(t_data *data, t_raycast *r, int x)
{
	t_floorcast	f;
	int			y;
	int			color;

	y = r->drawend;
	f.currentdist = 0;
	floor_side(&f, r);
	while (y < SCREEN_HEIGHT)
	{
		f.currentdist = (double)SCREEN_HEIGHT / (double)(2 * y
			- (SCREEN_HEIGHT + data->yaw) + 1);
		f.weight = f.currentdist / r->walldist;
		f.currentfloor.x = f.weight * f.floor.x
			+ (1 - f.weight) * data->p.pos.x;
		f.currentfloor.y = f.weight * f.floor.y
			+ (1 - f.weight) * data->p.pos.y;
		f.floortex.x = (int)(f.currentfloor.x * data->surface[4]->w)
														% data->surface[4]->w;
		f.floortex.y = (int)(f.currentfloor.y * data->surface[4]->h)
														% data->surface[4]->h;
		color = (get_pixel(data->surface[4], f.floortex.x, f.floortex.y));
		data->pixels[x + y * SCREEN_WIDTH] = color;
		y++;
	}
	roofcaster(data, r, x);
}
