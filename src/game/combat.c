/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 11:39:58 by acostaz           #+#    #+#             */
/*   Updated: 2020/03/11 18:06:28 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

void	get_attacking_sprite(t_data *data, t_object *obj)
{
	obj->lastupdate += data->ftime;
	if (obj->current_sprite < obj->first_sprite_attack
			|| obj->current_sprite > obj->first_sprite_attack
			+ obj->num_of_sprites_attack)
	{
		obj->lastupdate = 0;
		obj->current_sprite = obj->first_sprite_attack;
	}
	else if (obj->lastupdate >= 0.5 / obj->num_of_sprites_attack)
	{
		obj->lastframe++;
		obj->lastframe %= obj->num_of_sprites_attack;
		obj->lastupdate = 0;
		obj->current_sprite = obj->first_sprite_attack + obj->lastframe;
	}
}

void	hits_taken(t_data *data, t_object *obj)
{
	get_attacking_sprite(data, obj);
	if (obj->current_sprite == obj->first_sprite_attack
		+ obj->num_of_sprites_attack - 1
			&& data->time - data->p_dmgtime > 500)
	{
		data->p_dmgtime = data->time;
		data->p.hp -= data->p.armor > 5 ? 0 : 5 - data->p.armor;
		data->p.armor = data->p.armor > 5 ? data->p.armor - 5 : 0;
	}
}

void	combat(t_data *data)
{
	data->p.swap_weapon = use_weapon(data, data->p.selected_weapon);
	if (data->obj)
		hits_dealt(data);
}
