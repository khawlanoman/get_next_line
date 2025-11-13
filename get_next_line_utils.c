/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khnoman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:17:35 by khnoman           #+#    #+#             */
/*   Updated: 2025/11/06 14:17:37 by khnoman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	len;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	
	len = ft_strlen(s);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
	{
		return (NULL);
	}
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*arr;

	i = 0;
	if (!s)
	{
		return (NULL);
	}
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	arr = malloc((len + 1) * sizeof(char));
	if (!arr)
		return (NULL);
	while (i < len && s[start])
	{
		arr[i++] = s[start++];
	}
	arr[i] = '\0';
	return (arr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	k;
	size_t	len_s1;
	size_t	len_s2;
	char	*str;

	i = 0;
	k = 0;
	if (!s1 && !s2)
	{
		return (NULL);
	}
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!s1)
	{
		str = malloc((len_s2 + 1) * sizeof(char));
		if (!str)
			return (NULL);
		while (s2[i])
			str[k++] = s2[i++];
	}
	else if (!s2)
	{
		str = malloc((len_s1 + 1) * sizeof(char));
		if (!str)
			return (NULL);
		while (s1[i])
			str[k++] = s1[i++];
	}
	else
	{
		str = malloc((len_s1 + len_s2 + 1) * sizeof(char));
		if (!str)
			return (NULL);
		while (s1[i])
			str[k++] = s1[i++];
		i = 0;
		while (s2[i])
			str[k++] = s2[i++];
	}
	str[k] = '\0';
	return (str);
}