/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 16:37:45 by ehouzard          #+#    #+#             */
/*   Updated: 2018/05/02 13:39:28 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				parse_atb(char c, t_printf *s)
{
	if (s->flags > 0x1F)
	{
		s->err = -1;
		return (0);
	}
	if (c == ' ')
		s->flags |= SPACE;
	else if (c == '+')
		s->flags |= PLUS;
	else if (c == '-')
		s->flags |= MINUS;
	else if (c == '#')
		s->flags |= HASH;
	else if (c == '0')
		s->flags |= ZERO;
	if (s->flags == 11 || s->flags == 14
			|| s->flags == 10 || s->flags == 17)
	{
		s->err = -1;
		return (0);
	}
	if (s->flags == 3)
		s->flags = 1;
	return (1);
}

int				numby_check(t_printf *s, char *f, int *i, int point)
{
	if (point)
		(*i) = 0;
	while (f[(*i)] && !ft_ismodif(f[(*i)]))
	{
		if (f[(*i)] == '.')
			return (1);
		else if (ft_isatb(f[*i]) && f[*i] != '0')
		{
			s->err = -1;
			return (0);
		}
		(*i)++;
	}
	return (1);
}

int				parse_numb(char *format, t_printf *s, int point, int i)
{
	if ((s->flags | 0x1F) != 0x1F)
	{
		s->err = -1;
		return (0);
	}
	if (!numby_check(s, format, &i, 0))
		return (0);
	s->gab = ft_atoi(format);
	while (format[i] == '.')
	{
		i++;
		point++;
		if (point > 1)
			s->err = -1;
	}
	if (ft_isatb(format[i]) && format[i] != '0')
		s->err = -1;
	else if (ft_isdigit(format[i]))
	{
		format += i;
		if (!numby_check(s, format, &i, 1))
			return (0);
		s->pre = ft_atoi(format);
	}
	return (1);
}

void			modif_two(t_printf *s, char c, int *tmp)
{
	if (c == 'l')
	{
		if (*tmp == 0x3F)
		{
			*tmp = 0x21F;
			s->flags ^= L;
		}
		else
			*tmp |= L;
	}
	else if (c == 'h')
	{
		if (*tmp == 0x5F)
		{
			*tmp = 0x41F;
			s->flags ^= H;
		}
		else
			*tmp |= H;
	}
}

int				parse_modif(char c, t_printf *s)
{
	int tmp;

	tmp = s->flags | 0x1F;
	if (c == 'l' && (tmp == 0x1F || tmp == 0x3F))
		modif_two(s, c, &tmp);
	else if (c == 'h' && (tmp == 0x1F || tmp == 0x5F))
		modif_two(s, c, &tmp);
	else if (c == 'j' && (tmp == 0x1F))
		tmp |= J;
	else if (c == 'z' && (tmp == 0x1F))
		tmp |= Z;
	else
	{
		s->err = -1;
		return (0);
	}
	tmp ^= 0x1F;
	s->flags |= tmp;
	return (1);
}
