/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hprudhom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:04:55 by hprudhom          #+#    #+#             */
/*   Updated: 2021/01/21 12:06:23 by hprudhom         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_flag_dot(const char *save, int start,
				t_flags *flags, va_list args)
{
	int i;

	i = start;
	i++;
	flags->zero = 0;
	if (save[i] == '*')
	{
		flags->dot = va_arg(args, int);
		i++;
	}
	else
	{	
		flags->dot = 0;
		while (ft_isdigit(save[i]))
			flags->dot = (flags->dot * 10) + (save[i++] - '0');
	}
	return (i);
}

t_flags		ft_flag_minus(t_flags flags)
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

t_flags		ft_flag_width(va_list args, t_flags flags)
{
	flags.star = 1;
	flags.width = va_arg(args, int);
	if (flags.width < 0)
	{
		flags.minus = 1;
		flags.width *= -1;
	}
	return (flags);
}

t_flags		ft_flag_digit(char c, t_flags flags)
{
	if (flags.star == 1)
		flags.width = 0;
	flags.width = (flags.width * 10) + (c - '0');
	return (flags);
}

t_flags         ft_flag_plus(t_flags flags)
{
    if (flags.space == 1)
        flags.space = 0;
    flags.plus = 1;
    return (flags);
}