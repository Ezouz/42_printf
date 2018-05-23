/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 16:43:50 by ehouzard          #+#    #+#             */
/*   Updated: 2018/05/01 20:56:46 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_istype(char c)
{
	char		*s;
	int			i;

	s = "sSpdDioOuUxXcC";
	i = 14;
	while (i--)
		if (c == s[i])
			return (1);
	return (0);
}

int				ft_ismodif(char c)
{
	char		*s;
	int			i;

	s = "lhjz";
	i = 4;
	while (i--)
		if (c == s[i])
			return (1);
	return (0);
}

int				ft_isatb(char c)
{
	char		*s;
	int			i;

	s = " #+-0";
	i = 5;
	while (i--)
		if (c == s[i])
			return (1);
	return (0);
}

int             ft_stroc(char *str, char c)
{
    int i;

    i = 0;
    if (!str || !c)
        return (0);
    while (str[i] != '\0' && str[i] != c)
        i++;
    return (i);
}
