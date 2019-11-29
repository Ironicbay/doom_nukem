/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:19:39 by jmoucach          #+#    #+#             */
/*   Updated: 2019/11/26 12:20:52 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "wolf3d.h"

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_parse
{
	int				i;
	int				col;
	int				tmp;
}					t_parse;

typedef struct		s_d_point
{
	double			x;
	double			y;
}					t_d_point;

typedef struct		s_line_param
{
	t_point			diff;
	t_point			inc;
	int				error;
	int				off;
}					t_line_param;

typedef struct		s_ray
{
	t_d_point		pos;
	t_d_point		dir;
}					t_ray;

typedef struct		s_player
{
	double			angle;
	t_d_point		plane;
	t_d_point		pos;
	t_d_point		dir;
	int				is_sprinting;
	double			walkspeed;
	double			sprintspeed;
	double			rspeed;
}					t_player;

typedef struct		s_raycast
{
	t_ray			ray;
	double			camera;
	t_point			m_pos;
	t_d_point		sidedist;
	t_d_point		deltadist;
	t_point			step;
	int				hit;
	double			wall;
	int				side;
	int				texh;
	int				texw;
	int				texnum;
	t_point			tex;
	int				lineheight;
	Uint32			color;
	int				drawstart;
	int				drawend;
	double			walldist;
}					t_raycast;

typedef struct		s_floorcast
{
	t_d_point		floor;
	t_d_point		currentfloor;
	t_point			floortex;
	double			currentdist;
	double			weight;
}					t_floorcast;

typedef struct		s_data
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
	SDL_Surface		**surface;
	Uint32			*pixels;
	double			ftime;
	int				yaw;
	t_player		p;
	double			sensitivity;
	int				**map;
	t_point			msize;
	short			toggle_minimap;
	short			quit;
}					t_data;

#endif
