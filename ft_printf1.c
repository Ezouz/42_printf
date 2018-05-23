/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 14:04:21 by ehouzard          #+#    #+#             */
/*   Updated: 2018/05/02 20:39:24 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *format, ...)
{
	t_printf	s;
	t_pchar		*as;

	as = NULL;
	if (!(initprintf(&s, ft_stroc((char *)format, '%'))))
		return (-1);
	as = s.ret;
	va_start(s.va, format);
	if (!fparse(format, &s))
		return (-1);
	printf("\nflags:%x, gab:%d, pre:%d, len:%d, err:%d\n", s.flags, s.gab, s.pre, s.len, s.err);
	if (s.err != -1)
		ft_printf_lst(&as);
	va_end(s.va);
	ft_delpchar(&as);
	return (s.len);
}

t_pchar         *new_pchar(int size)
{
    t_pchar *m;

    m = NULL;
    if (!(m = malloc(sizeof(t_pchar))))
        return (0);
    if (size > 0 && !(m->s = ft_strnew(BUF_SIZE)))
    {
        free(m);
        return (0);
    }
    else if (size == 0 && !(m->s = ft_strnew(BUF_SIZE)))
    {
        free(m);
        return (0);
    }
    m->len = size;
    m->next = NULL;
    return (m);
}
/*
t_pchar         *new_wpchar(int size)
{
    t_pchar *m;

    m = NULL;
    if (!(m = malloc(sizeof(t_pchar))))
        return (0);
    if (size > 0 && !(m->ws = initialisation strnew pour wchar))
    {
        free(m);
        return (0);
    }
    else if (size == 0 && !(m->s = ft_strnew(BUF_SIZE)))
    {
        free(m);
        return (0);
    }
    m->len = size;
    m->next = NULL;
    return (m);
}
*/

int             initprintf(t_printf *s, int size)
{
    t_pchar     *tmp;

    s->flags = 0;
    s->shift = 1;
    s->len = 0;
    s->err = 0;
    s->gab = 0;
    s->pre = 0;
    s->arg = 0;
    if (!(tmp = new_pchar(size)))
        return (0);
    s->ret = tmp;
    return (1);
}

void            ft_delpchar(t_pchar **ret)
{
    t_pchar *tmp;

    tmp = NULL;
    while (*ret)
    {
        tmp = *ret;
        *ret = (*ret)->next;
        ft_strdel(&tmp->s);
        free(tmp);
    }
}

/*
int             fwpass(t_printf *s)
{
    if (!(s->ret->next = new_pwchar(BUF_SIZE)))
        return (0);
    s->ret = s->ret->next;
    (*s).ret->len = 0;
    return (1);
}
*/

int             fpass(t_printf *s)
{
    if (!(s->ret->next = new_pchar(BUF_SIZE)))
        return (0);
    s->ret = s->ret->next;
    (*s).ret->len = 0;
    return (1);
}

void            ft_printf_lst(t_pchar **ret)
{
    t_pchar *tmp;

    tmp = *ret;
    ft_putstr("-------------------------------\n");
    while (tmp)
    {
        ft_putstr(tmp->s);
        tmp = tmp->next;
    }
    ft_putstr("-------------------------------\n");
}
