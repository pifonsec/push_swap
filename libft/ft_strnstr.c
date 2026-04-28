/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifonsec <pifonsec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:49:04 by pifonsec          #+#    #+#             */
/*   Updated: 2025/11/05 11:49:04 by pifonsec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1,	const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (s2[0] == '\0')
		return ((char *) s1);
	while (i < len && s1[i])
	{
		j = 0;
		if (s1[i] == s2[0])
		{
			while (i + j < len && s1[i + j] && s2[j] && s1[i + j] == s2[j])
			{
				if (s2[j + 1] == '\0')
					return ((char *)&s1[i]);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
