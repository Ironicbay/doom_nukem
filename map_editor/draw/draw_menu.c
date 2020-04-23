/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 13:41:59 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/03/10 17:15:26 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/map_editor.h"

void			ft_print_rectangle(t_fdf *img, t_pt pt, int w, int h)
{
	t_pt			pt_a;
	t_pt			pt_b;
	t_pt			pt_c;
	t_pt			pt_d;

	pt_a = coord_to_pt(pt.x, pt.y);
	pt_b = coord_to_pt(pt.x + w, pt.y);
	pt_c = coord_to_pt(pt.x + w, pt.y + h);
	pt_d = coord_to_pt(pt.x, pt.y + h);
	draw_line(pt_a, pt_b, img->pixels, WHITE);
	draw_line(pt_b, pt_c, img->pixels, WHITE);
	draw_line(pt_c, pt_d, img->pixels, WHITE);
	draw_line(pt_d, pt_a, img->pixels, WHITE);
}

void			draw_menu_squares(t_fdf *img)
{
	int			i;
	t_pt		pt;

	i = 0;
	while (++i <= 18)
	{
		if (i == 12)
			i++;
		pt.x = 1120 + (((i - 1) % 3) * 80) - 1;
		pt.y = 120 + (((i - 1) / 3) * 80) - 1;
		ft_print_rectangle(img, pt, 70 + 2, 70 + 2);
	}
}

void			ft_print_pressed_button(t_fdf *img, int i)
{
	t_pt		start;

	if (i == 12 || i == -1)
		return ;
	if (i == 0)
	{
		start = coord_to_pt(1119, 649);
		ft_print_rectangle(img, start, 232, 114);
		start = coord_to_pt(1118, 648);
		ft_print_rectangle(img, start, 234, 116);
	}
	else
	{
		start.x = 1120 + (((i - 1) % 3) * 80) - 1;
		start.y = 120 + (((i - 1) / 3) * 80) - 1;
		ft_print_rectangle(img, start, 72, 72);
		start.x = 1120 + (((i - 1) % 3) * 80) - 2;
		start.y = 120 + (((i - 1) / 3) * 80) - 2;
		ft_print_rectangle(img, start, 74, 74);
	}
}
