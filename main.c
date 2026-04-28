/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifonsec <pifonsec@student.42Angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 09:10:23 by pifonsec          #+#    #+#             */
/*   Updated: 2026/03/04 09:10:23 by pifonsec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char			*args;
	char			*tmp;
	int				i;
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	args = NULL;
	i = 1;
	if (argc < 2)
	{
		write (2, "Error\n", 6);
		return (1);
	}
	while (i < argc)
	{
		if (!args)
			args = ft_strjoin("", argv[i]);
		else
		{
			tmp = ft_strjoin(args, " ");
			free(args);
			args = ft_strjoin(tmp, argv[i]);
			free(tmp);
		}
		i++;
	}
	stack_init(&a, args);
	if (check_duplicates(a) == 1)
	{
		error_free(&a, args);
		return (1);
	}
	if (!a)
	{
		free(args);
		write(2, "Error\n", 6);
		return (1);
	}
	if (stack_sorted(a) == 1)
		push_swap(&a, &b);
	free(args);
	free_stack(&a);
}
