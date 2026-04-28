/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifonsec <pifonsec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:39:28 by pifonsec          #+#    #+#             */
/*   Updated: 2025/11/05 11:39:28 by pifonsec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strslen(char const *s1, char const *s2)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (s1[i])
		i++;
	len += i;
	i = 0;
	while (s2[i])
		i++;
	len += i;
	return (len);
}

char	*ft_strcat(char const *s1, char const *s2, char *final_str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		final_str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		final_str[i + j] = s2[j];
		j++;
	}
	final_str[i + j] = '\0';
	return (final_str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final_str;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return ((char *)s2);
	else if (!s2)
		return ((char *)s1);
	final_str = malloc(sizeof(char) * (ft_strslen(s1, s2) + 1));
	if (!final_str)
		return (NULL);
	final_str = ft_strcat(s1, s2, final_str);
	return (final_str);
}
