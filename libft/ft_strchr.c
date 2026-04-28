/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifonsec <pifonsec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:30:13 by pifonsec          #+#    #+#             */
/*   Updated: 2025/11/05 11:30:13 by pifonsec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int searchedChar)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)searchedChar)
			break ;
		i++;
	}
	if (str[i] == (char)searchedChar)
		return ((char *)&str[i]);
	return (NULL);
}
