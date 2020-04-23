/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:46:23 by jmoucach          #+#    #+#             */
/*   Updated: 2020/03/10 14:12:28 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

char			*join_strings(char *s1, char *s2)
{
	char		*str;
	const int	l1 = (s1) ? ft_strlen(s1) : 0;
	const int	l2 = (s2) ? ft_strlen(s2) : 0;

	if (!(str = (char *)malloc(sizeof(char) * (l1 + l2 + 1))))
		return (NULL);
	ft_memcpy(str, s1, l1);
	ft_memcpy(str + l1, s2, l2);
	str[l1 + l2] = '\0';
	return (str);
}

char			*read_map(int fd)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	char		*str;
	char		*tmp;

	str = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = str;
		str = join_strings(tmp, buf);
		free(tmp);
	}
	if (ret == -1 || !str)
		return (NULL);
	return (str);
}

void			allocate_map(t_data *data, short id)
{
	int			i;

	i = 0;
	if (!(data->maps[id].map =
				(int**)malloc(sizeof(int*) * data->maps[id].height)))
		clean_exit(data, "Map malloc error");
	nullify_tab((void**)data->maps[id].map, data->maps[id].height);
	while (i < data->maps[id].height)
	{
		if (!(data->maps[id].map[i] =
					(int*)malloc(sizeof(int) * data->maps[id].width)))
			clean_exit(data, "Map malloc error");
		i++;
	}
}

void			new_map(t_data *data, char *title, short id)
{
	int			fd;
	char		*str;

	fd = open(title, O_NOCTTY | O_RDONLY | O_NOFOLLOW | O_NONBLOCK);
	if (fd < 0)
		clean_exit(data, "Couldn't open map");
	close(fd);
	fd = open(title, O_DIRECTORY);
	if (fd >= 0)
		clean_exit(data, "Map is a directory, not a file");
	close(fd);
	if (map_too_big(title))
		clean_exit(data, "Map is too big or has too many enemies");
	fd = open(title, O_NOCTTY | O_RDONLY | O_NOFOLLOW | O_NONBLOCK);
	if (!(str = read_map(fd)))
		clean_exit(data, "Read error");
	if (!count_lines_and_col(data, str, id))
		clean_exit(data, "Map is not rectangular");
	str = ft_replace(str, '\n', ',');
	close(fd);
	allocate_map(data, id);
	fill_raw_map(data, str, id);
	parse_map(data, str, id);
	free(str);
}
