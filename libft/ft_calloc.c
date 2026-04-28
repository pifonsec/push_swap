/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifonsec <pifonsec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 10:21:42 by pifonsec          #+#    #+#             */
/*   Updated: 2025/11/05 10:21:42 by pifonsec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*tab;

	if (elementSize != 0 && elementCount > ((size_t) -1 / elementSize))
		return (NULL);
	tab = malloc(elementCount * elementSize);
	if (!tab)
		return (NULL);
	ft_bzero(tab, elementCount * elementSize);
	return (tab);
}
