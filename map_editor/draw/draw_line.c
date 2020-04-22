/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:27:49 by jmoucach          #+#    #+#             */
/*   Updated: 2020/02/26 12:49:25 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/map_editor.h"

void				setup_param(t_pt pt_one, t_pt pt_two,
	t_line_param *line_param)
{
	line_param->diff.x = ft_abs(pt_two.x - pt_one.x);
	line_param->diff.y = ft_abs(pt_two.y - pt_one.y);
	line_param->off = line_param->diff.x - line_param->diff.y;
	line_param->inc.x = (pt_one.x < pt_two.x ? 1 : -1);
	line_param->inc.y = (pt_one.y < pt_two.y ? 1 : -1);
}

void				draw_line(t_pt pt_one, t_pt pt_two,
	Uint32 *pixels, int colour)
{
	t_pt			pt;
	t_line_param	line_param;
	Uint32			*pix;

	pix = pixels;
	setup_param(pt_one, pt_two, &line_param);
	pt.x = pt_one.x;
	pt.y = pt_one.y;
	while (pt.x != pt_two.x || pt.y != pt_two.y)
	{
		if (pt.x + pt.y * WIDTH >= 0 && pt.x + pt.y * WIDTH < WIDTH * HEIGHT)//protection for the SDL_DestroyRenderer problem
			pix[pt.x + pt.y * WIDTH] = colour;
		if ((line_param.error = line_param.off * 2) > -line_param.diff.y)
		{
			line_param.off -= line_param.diff.y;
			pt.x += line_param.inc.x;
		}
		if (line_param.error <= line_param.diff.x)
		{
			line_param.off += line_param.diff.x;
			pt.y += line_param.inc.y;
		}
	}
	if (pt.x + pt.y * WIDTH >= 0 && pt.x + pt.y * WIDTH < WIDTH * HEIGHT)//protection for the SDL_DestroyRenderer problem
		pix[pt.x + pt.y * WIDTH] = colour;
}
/*
int		is_out_of_grid(t_pt *pt)
{
	int	out_of_grid;

	out_of_grid = 0;
	if (pt->x < 0)
	{
		pt->x = 0;
		out_of_grid++;
	}
	if (pt->y < 0)
	{
		pt->y = 0;
		out_of_grid++;
	}
	if (pt->x >= WIDTH)
	{
		pt->x = WIDTH - 1;
		out_of_grid++;
	}
	if (pt->y >= HEIGHT)
	{
		pt->y = HEIGHT - 1;
		out_of_grid++;
	}
	return (out_of_grid);
}

void	check_and_draw_line(t_pt start, t_pt end, t_fdf *img, int col)
{
	//if (is_out_of_grid(&start) && is_out_of_grid(&end))
	//	return ;
	if (start.x < 0)
		start.x = 0;
	if (start.y < 0)
		start.y = 0;
	if (end.x < 0)
		end.x = 0;
	if (end.y < 0)
		end.y = 0;
	if (start.x >= WIDTH)
		start.x = WIDTH - 1;
	if (start.y >= HEIGHT)
		start.y = HEIGHT - 1;
	if (end.x >= WIDTH)
		end.x = WIDTH - 1;
	if (end.y >= HEIGHT)
		end.y = HEIGHT - 1;
	draw_line(start, end, img->pixels, col);
}
*/
void			ft_calculate_grid_coord_and_draw_line(t_pt a, t_pt b, t_fdf *img, int col)
{
	t_pt			pt_one;
	t_pt			pt_two;

	pt_one.x = img->map->ox + a.x * img->map->base_gap;
	pt_one.y = img->map->oy + a.y * img->map->base_gap;
	pt_two.x = img->map->ox + b.x * img->map->base_gap;
	pt_two.y = img->map->oy + b.y * img->map->base_gap;
	//check_and_draw_line(pt_one, pt_two, img, col);//replaced by draw_line since we cannot move or zoom the map anymore
	draw_line(pt_one, pt_two, img->pixels, col);
}
