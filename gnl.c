/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yevkahar <yevkahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:25:59 by yevkahar          #+#    #+#             */
/*   Updated: 2025/03/20 14:32:16 by yevkahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*handle_read_join(char *str, int fd, int *len)
{
	char	*buff;
	char	*temp;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (free(str), NULL);
	*len = read(fd, buff, BUFFER_SIZE);
	if (*len == -1)
		return (free(buff), free(str), NULL);
	buff[*len] = '\0';
	if (!str)
		return (buff);
	temp = str;
	str = my_strjoin(str, buff);
	free(buff);
	if (!str)
		return (NULL);
	free(temp);
	return (str);
}
//reads data from file & add them to str

char	*read_line(int fd, char *str)
{
	int	len;

	if (!str)
		str = my_strdup_gnl("");
	if (!str)
		return (NULL);
	len = 1;
	while (!my_strchr(str, '\n') && len != 0)
	{
		str = handle_read_join(str, fd, &len);
		if (!str)
			return (NULL);
	}
	return (str);
}
//reads whole line till \n

char	*print_line(char *str)
{
	size_t	len;
	char	*line;

	len = 0;
	if (!str || !str[0])
		return (NULL);
	while (str[len] && str[len] != '\n')
		len++;
	line = malloc(sizeof(char) * (len + 2));
	if (!line)
		return (NULL);
	len = 0;
	while (str[len] && str[len] != '\n')
	{
		line[len] = str[len];
		len++;
	}
	if (str[len] == '\n')
		line[len++] = '\n';
	line[len] = '\0';
	return (line);
}
//gets buff from str and highlights line till \n

char	*edit_line(char *str)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i] || !str[i + 1])
		return (free(str), NULL);
	i++;
	j = 0;
	while (str[i + j])
		j++;
	new_str = malloc(sizeof(char) * (j + 1));
	if (!new_str)
		return (free(str), NULL);
	j = 0;
	while (str[i])
		new_str[j++] = str[i++];
	new_str[j] = '\0';
	return (free(str), new_str);
}
//cuts line till \n and returns rest of the str

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = read_line(fd, str);
	if (!str || !*str)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	line = print_line(str);
	str = edit_line(str);
	return (line);
}
//main function that reads line from file and returns it