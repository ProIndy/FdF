/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:58:14 by ijaaskel          #+#    #+#             */
/*   Updated: 2021/11/30 15:51:34 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_atoi_plus(const char *str, int index)
{
	int	result;

	result = 0;
	index++;
	while (ft_isdigit(str[index]) == 1)
	{
		result = (result * 10) + (str[index] - '0');
		index++;
	}
	return (result);
}

static int	ft_atoi_neg(const char *str, int index)
{
	int	result;

	result = 0;
	index++;
	while (ft_isdigit(str[index]) == 1)
	{
		result = (result * 10) + (str[index] - '0');
		index++;
	}
	return (-result);
}

int	ft_atoi(const char *str)
{
	int	index;
	int	result;

	result = 0;
	index = 0;
	while (ft_iswhitespace(str[index]) == 1 && str[index] != '\0')
		index++;
	if (str[index] == '+')
		result = ft_atoi_plus(str, index);
	else if (str[index] == '-')
		result = ft_atoi_neg(str, index);
	else if (ft_isdigit(str[index]) == 1)
	{
		while (ft_isdigit(str[index]) == 1)
		{
			result = (result * 10) + (str[index] - '0');
			index++;
		}
	}
	return (result);
}
