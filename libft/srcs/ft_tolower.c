/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 12:40:49 by dcastro-          #+#    #+#             */
/*   Updated: 2017/01/10 16:22:25 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tolower(int c)
{
	int a;

	if (c >= 65 && c <= 90)
	{
		c = (97 + c - 65);
		return (c);
	}
	else
	{
		a = c;
		return (a);
	}
}