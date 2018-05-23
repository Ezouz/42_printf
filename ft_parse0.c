/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 14:04:21 by ehouzard          #+#    #+#             */
/*   Updated: 2018/05/02 18:15:19 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			checkperce(const char *format, int *i, int *f)
{
	
	while (format[*i] == '%')
		(*i)++;
	(*f) = (*i);
	if (ft_isdigit(format[*i]) || format[*i] == '.')
		while (ft_isdigit(format[*f]) || format[*i] == '.')
			(*f)++;
	if (format[*f] != '\0')
	{
		if (ft_isatb(format[*f])  || ft_ismodif(format[*f]) || ft_istype(format[*f]))
			(*f) = 1;
		else
			(*f) = 0;
	}
//	printf("f:%d, i:%d\n", *f, *i);
}

int				write_perce(t_printf *s, int i)
{
		while (i-- > 0)
		{
			if (s->ret->len == BUF_SIZE)
				if (!fpass(s))
					return (0);
			s->ret->s[s->ret->len++] = '%';
		}
	return (1);
}

int				perce(const char *format, t_printf *s)
{
	int i;
	int f;

	i = 0;
	f = 0;
	checkperce(format, &i, &f);
	s->shift = i + 1;
	if ((i % 2) == 1)
	{
		if (!write_perce(s, (i + 1) / 2))
			return (0);
	}
	else if ((i % 2) == 0 && f == 1)
	{
		f = i;
		if (!write_perce(s, i / 2))
			return (0);
		if (!get_interpret(format + f, s))
			return (0);
	}
	else
		s->err = -1;
	return (1);
}

int				fperce(const char *format, t_printf *s)
{
	int m;

	m = ft_stroc((char *)format + 1, '%');
	if (m > 1)	// c a d que la prochaine occurence est loin ou jamais
		get_interpret(format, s);
	else		// ici ca veut juste dire plusieurs %%% d'affile
		if (!perce(format + 1, s))
			return (0);
	return (1);
}

int				fparse(const char *format, t_printf *s)
{
	int c;

	c = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			s->ret->len = c;
			if (!fperce(format, s))
				return (0);
			c = s->ret->len;
			s->len += s->shift;
		}
		else
		{
			s->ret->s[c] = *format;
			c++;
			s->len++;
		}
		format += s->shift;
		if (s->shift > 1)
			s->shift = 1;
		//format decallage avec shift / c = s->ret->len / s->len = curseur format
	}
	return (1);
}
