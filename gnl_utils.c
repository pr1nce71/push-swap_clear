/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yevkahar <yevkahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:26:02 by yevkahar          #+#    #+#             */
/*   Updated: 2025/03/21 16:01:06 by yevkahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	my_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*my_strdup_gnl(const char *s)
{
	char	*len;
	size_t	i;

	len = malloc(my_strlen(s) + 1);
	if (!len)
		return (NULL);
	i = 0;
	while (s[i])
	{
		len[i] = s[i];
		i++;
	}
	len[i] = '\0';
	return (len);
}

char	*my_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*my_strcpy(char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*my_strjoin(char *s1, const char *s2)
{
	unsigned int	len1;
	unsigned int	len2;
	char			*result;

	if (!s1)
		return (my_strdup_gnl(s2));
	if (!s2)
		return (NULL);
	len1 = my_strlen(s1);
	len2 = my_strlen(s2);
	result = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!result)
		return (NULL);
	my_strcpy(result, s1);
	my_strcpy(result + len1, s2);
	return (result);
}
