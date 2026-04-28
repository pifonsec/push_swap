/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifonsec <pifonsec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:55:27 by pifonsec          #+#    #+#             */
/*   Updated: 2025/11/05 11:55:27 by pifonsec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*final_s;

	i = 0;
	if (start >= ft_strlen(s))
		len = 0;
	else if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	final_s = malloc(sizeof(char) * (len + 1));
	if (!final_s)
		return (NULL);
	while (start + i < ft_strlen(s) && i < len)
	{
		final_s[i] = s[start + i];
		i++;
	}
	final_s[i] = '\0';
	return (final_s);
}
