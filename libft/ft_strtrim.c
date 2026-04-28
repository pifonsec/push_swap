/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifonsec <pifonsec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:52:11 by pifonsec          #+#    #+#             */
/*   Updated: 2025/11/05 11:52:11 by pifonsec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*empty_string(void)
{
	char	*str;

	str = malloc(sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	end;
	size_t	s1_len;
	char	*final_str;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && is_in_set(s1[i], set) == 1)
		i++;
	s1_len = ft_strlen(s1);
	end = s1_len - 1;
	if (s1_len == i)
		return (empty_string());
	while (end > 0 && is_in_set(s1[end], set) == 1)
		end--;
	final_str = malloc((end - i + 2) * sizeof(char));
	if (!final_str)
		return (NULL);
	ft_strlcpy(final_str, (s1 + i), (end - i + 2));
	return (final_str);
}
