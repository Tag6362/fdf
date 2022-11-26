/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atou_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:47:36 by tgernez           #+#    #+#             */
/*   Updated: 2022/11/26 17:34:10 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static unsigned int	hexa_atou(char c)
{
	int	i;

	i = 0;
	if ('0' <= c && c <= '9')
		return (c - '0');
	else if ('a' <= c && c <= 'f')
	{
		while (HEXA_LOW[i] != c)
			i++;
		return (i);
	}
	else if ('A' <= c && c <= 'F')
	{
		while (HEXA_UP[i] != c)
			i++;
		return (i);
	}
	return (0);
}

unsigned int	ft_atou_hexa(const char *str)
{
	unsigned int	nb;
	int				i;

	nb = 0;
	i = 0;
	while (str[i] == ' ' || (8 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	i += 2;
	while (('0' <= str[i] && str[i] <= '9')
		|| ('a' <= str[i] && str[i] <= 'f')
		|| ('A' <= str[i] && str[i] <= 'F'))
	{
		nb = nb * 16 + hexa_atou(str[i]);
		i++;
	}
	return (nb);
}

// int main(void)
// {
// 	char *str = "0x81000000";
// 	printf("%lx\n", ft_atoil_hexa((const char *)str));
// 	return (0);
// }