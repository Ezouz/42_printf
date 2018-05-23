/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 14:04:21 by ehouzard          #+#    #+#             */
/*   Updated: 2018/05/02 20:53:25 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				fparse_flags(const char *format, t_printf *s, int nbflags, int f)
{
	while (f < nbflags)
	{
		if (ft_isatb((char)*format) && parse_atb((char)*format, s))
			format++;
		else if (ft_isdigit((char)*format) || *format == '.')
		{
			if (s->gab == 0 && s->pre == 0)
				if (!parse_numb((char *)format, s, 0, 0))
					return (0);
			format++;
		}
		else if (ft_ismodif((char)*format) && parse_modif((char)*format, s))
			format++;
		else
		{
			s->err = -1;
			break ;
		}
		f++;
	}
	if (s->err == -1)
		return (0);
	s->arg++;
	return (1);
}

int				err_type(char f,  t_printf *s)
{
	if (f == 'c' || f == 'C' || f == 's' || f == 'S'
			|| f == 'd' || f == 'D' || f == 'i'|| f == 'u' || f == 'U')
		if ((s->flags & 0x1F) == 4)
			return (0);
	if (f == 'u' || f == 'U' || f == 'x' || f == 'X')
		if ((s->flags & 0x1F) == 1 || (s->flags & 0x1F) == 16)
			return (0);
	if ((f == 'c' || f == 'C') && s->pre != 0)
		return (0);
	if (f == 'p' && s->flags != 0 && s->flags != 2)
			return (0);
	if ((f == 'c' || f == 's') && s->flags > 0x3F)
		return (0);
	if ((f == 'C' || f == 'S') && s->flags > 0x1F)
		return (0);
	return (1);
}

int				write_s(t_printf  *s, char *str, size_t len)
{
	int i;

	i = 0;
	while (len--)
	{
		s->ret->s[s->ret->len] = str[i];
		s->ret->len++;
		i++;
		if (s->ret->len >= BUF_SIZE - 1)
			if (!fpass(s))
				return (0);
	}
	return (1);
}

int				get_type(char f, t_printf *s)
{
	printf("type:%c, flag:%d\n",f, s->flags);
	u_var data;
	// si ls ou S ?
	if (f == 's')
	{
		if ((s->flags & L) == L)
			data.wstr = va_arg(s->va, wchar_t *);
		else
		{
			data.str = va_arg(s->va, char *);
			if (!write_s(s, data.str, ft_strlen(data.str)))
				return (0);
		}
	}
	if (f == 'c')
	{
		data.im = va_arg(s->va, intmax_t);
		if ((s->flags & L) == L)
			printf("L\n");
		else
		{
			if (s->ret->len >= (BUF_SIZE - 1) && !fpass(s))
				return (0);
			s->ret->s[s->ret->len++] = data.im;
		}
}
/*
	if (f == 'u' || f == 'U' || f == 'o' || f == 'O' || f == 'x' || f == 'X' || f == 'p')
		uim = va_arg(s->va, uintmax_t);
	if (f == 'd' || f == 'D' || f == 'i')
		im = va_arg(s->va, uintmax_t);
*/
	return (1);
}

int				get_interpret(const char *format, t_printf *s)
{
	int c;

	c = 0;
	while (!(ft_istype(format[c])))
		c++;
	if (!fparse_flags(format + 1, s, c, 1))
		return (0);
	s->shift = c + 1;
	if (!err_type(*(format + c), s))
	{
		s->err = -1;
		return (0);
	}
	if (!get_type(*(format + c), s))
	{
		s->err = -1;
		return (0);
	}
//	printf("s:%s, len:%d, size:%d\n", s->ret->s, s->len, s->ret->len);
	return (1);
}
