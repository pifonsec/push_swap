/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifonsec <pifonsec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:50:43 by pifonsec          #+#    #+#             */
/*   Updated: 2025/11/05 11:50:43 by pifonsec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int searchedChar)
{
	int	i;

	i = ft_strlen(str);
	if (searchedChar == '\0')
		return ((char *) str + i);
	while (i >= 0)
	{
		if (str[i] == (char) searchedChar)
			return ((char *) str + i);
		i--;
	}
	return (NULL);
}
