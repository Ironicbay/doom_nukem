/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skybox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 13:23:12 by acostaz           #+#    #+#             */
/*   Updated: 2020/03/11 17:59:35 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

void		mod_col(int *col, int tot)
{
	while (*col < 0)
		*col += tot;
	while (*col >= tot)
		*col -= tot;
}

double		two_pi_mod(double angle)
{
	while (angle >= 2 * M_PI)
		angle -= 2 * M_PI;
	while (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}

/*
** each skybox should be 3200*300px
*/

int			get_y(t_data *data, double i)
{
	int		diff;
	int		res;

	diff = (int)(150.0 * ((double)data->yaw / 720.0));
	res = 150 - diff + (int)(i * 150.0 / ((double)SCREEN_HEIGHT / 2.0));
	return (res);
}

/*
** TODO get the skybox height & width in defines (3200 * 300)
*/

void		print_skybox(t_data *data)
{
	t_skybox	sky;
	int			counter;
	int			i;
	Uint32		color;

	sky.dir = atan2(data->p.dir.y, data->p.dir.x);
	sky.dir = two_pi_mod(sky.dir + M_PI / 3.0);
	sky.col = (int)(sky.dir * 3200.0 / (2 * M_PI));
	sky.col_step = 3200.0 / (double)SCREEN_WIDTH / 6.0;
	counter = 0;
	while (counter < SCREEN_WIDTH)
	{
		sky.cur_col = (int)(sky.col - (double)counter * sky.col_step);
		mod_col(&(sky.cur_col), 3200);
		i = -1;
		while (++i < (SCREEN_HEIGHT / 2) + data->yaw / 2)
		{
			color = get_pixel(data->surface[data->shaded ? 8 : 7],
					sky.cur_col, get_y(data, (double)i));
			data->pixels[i * SCREEN_WIDTH + counter] = color;
		}
		counter++;
	}
}
