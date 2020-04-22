/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 12:48:35 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/03/04 21:31:04 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/map_editor.h"

t_item			*ft_sub_init(TTF_Font *font, SDL_Color color, SDL_Renderer *renderer)
{
	t_item	*sub;

	if (!(sub = malloc(sizeof(t_item))))
		return (0);
	TTF_SizeText(font, "Sous-menu", &sub->rect.w, &sub->rect.h);
	sub->rect.x = 10;
	sub->rect.y = 10;
	if (!(sub->surface = TTF_RenderText_Solid(font, "Sous-menu", color)))
		ft_error_fd((char *)TTF_GetError(), 2);
	if (!(sub->texture = SDL_CreateTextureFromSurface(renderer,
					sub->surface)))
		ft_error_fd((char *)SDL_GetError(), 2);
	SDL_FreeSurface(sub->surface);
	return (sub);
}

t_item			*ft_menu_init(TTF_Font *font, SDL_Color color, SDL_Renderer *renderer)
{
	t_item		*menu;

	if (!(menu = malloc(sizeof(t_item))))
		return (NULL);
	TTF_SizeText(font, "Menu", &menu->rect.w, &menu->rect.h);
	menu->rect.x = 10;
	menu->rect.y = 10;
	if (!(menu->surface = TTF_RenderText_Solid(font, "Menu", color)))
		ft_error_fd((char *)TTF_GetError(), 2);
	if (!(menu->texture = SDL_CreateTextureFromSurface(renderer,
					menu->surface)))
		ft_error_fd((char *)SDL_GetError(), 2);
	SDL_FreeSurface(menu->surface);
	return (menu);
}

t_txt			*ft_txt_init(t_fdf *img)
{
	t_txt		*txt_ptr;

	if (!(txt_ptr = malloc(sizeof(t_txt))))
		return (NULL);
	if (!(txt_ptr->font = TTF_OpenFont("Fonts/BaroneysTextured.ttf", 32)))
		ft_error_fd((char *)TTF_GetError(), 2);
	txt_ptr->color = ft_hexa_to_SDL(SAND);
	if (!(txt_ptr->menu = ft_menu_init(txt_ptr->font, txt_ptr->color, img->renderer)))
		return (NULL);
	return (txt_ptr);
}
