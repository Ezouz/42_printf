/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 13:59:05 by ehouzard          #+#    #+#             */
/*   Updated: 2018/05/02 22:40:44 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdio.h>
# include <wchar.h>
# include <unistd.h>
# include <locale.h>

# define BUF_SIZE 1024
# define PLUS 0x1
# define MINUS 0x2
# define HASH 0x4
# define ZERO 0x8
# define SPACE 0x10
# define L 0x20
# define H 0x40
# define J 0x80
# define Z 0x100
# define LL 0x200
# define HH 0x400

typedef union			u_var
{
	intmax_t			im;
	wchar_t				*wstr;
	char				*str;
}						u_var;

typedef union			u_string
{
	char			*s;
	wchar_t			*ws;
}						u_str;

typedef struct		s_pchar
{
//	u_char			us;
	char			*s;
	int				len;
	struct s_pchar	*next;
}					t_pchar;

typedef struct		s_printf
{
	unsigned int	gab;
	unsigned int	pre;
	int				flags;
	int				shift;
	int				len;
	int				err;
	int				arg;
	va_list			va;
	t_pchar			*ret;
}					t_printf;

int					ft_printf(const char *format, ...);
int					ft_stroc(char *str, char c);
int					initprintf(t_printf *s, int size);

t_pchar				*new_pchar(int size);
void				ft_delpchar(t_pchar **ret);
int					fpass(t_printf *s);
void				ft_printf_lst(t_pchar **ret);

int					fparse(const char *format, t_printf *s);
int					get_interpret(const char *format, t_printf *s);
int					fparse_flags(const char *format, t_printf *s, int nbflags, int f);

int					ft_isatb(char c);
int					ft_ismodif(char c);
int					ft_istype(char c);
int					parse_atb(char c, t_printf *s);
int					parse_numb(char *format, t_printf *s, int point, int i);
int					parse_modif(char c, t_printf *s);
//int					parse_type(char f, t_printf *s);
#endif
