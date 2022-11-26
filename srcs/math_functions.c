/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 19:31:37 by tgernez           #+#    #+#             */
/*   Updated: 2022/11/26 22:36:33 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

long power(int nb, int power)
{
	int		i;
	long	new_nb;

	i = 0;
	if (nb == 0)
		return (0);
	new_nb = 1;
	while (i < power)
	{
		new_nb *= nb;
		i++;
	}
	return (new_nb);
}

int ft_rev_bigger(int *a, int *b)
{
	int	tmp;

	if (*a > *b)
	{
		tmp = *a;
		*a = *b;
		*b = tmp;
		return (1);
	}
	return (0);
}