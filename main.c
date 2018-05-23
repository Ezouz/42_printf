/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 14:01:56 by ehouzard          #+#    #+#             */
/*   Updated: 2018/05/02 19:32:33 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//#include <locale.h>
int main(void)
{
/*
	ft_printf("%%c%%%%\n");
	printf("%%c%%%%\n");
	ft_printf("wifbiweufwiuef%%c\n");
	printf("wifbiweufwiuef%%c\n");
	ft_printf("val: %uu\n", 010);
	printf("val: %uu\n", 010);
	//printf("size wchar_t : %lu, size int %lu, char %lu, unsigned char: %lu, uchar:%lu\n",sizeof(wchar_t), sizeof(int), sizeof(char), sizeof(unsigned char), sizeof(unsigned char));
	ft_printf("Line one\n\t\tLine two\n");
	printf("Line one\n\t\tLine two\n");
	ft_printf("oui %8.3s\n\n", "abcdefghijklmnopqrstuwxyz");
	printf("oui %8.3s\n\n", "abcdefghijklmnopqrstuwxyz");
	//printf("h: %S, %lO\n", L"wewchar_t texteSalut Gérard Salut Géraoife¶¶¶`", 9223372036854775800);
	ft_printf("%+++-+--2.9d\n", 775800);
	printf("%+++-+--2.9d\n", 775800);
	ft_printf("oui c'est ca %d%%%%%%eroufhwheifhw oeihf kfebekw  qljc\n", 3);
	printf("oui c'est ca %d%%%%%%eroufhwheifhw oeihf kfebekw  qljc\n", 3);
	ft_printf("oui c'est ca %d%%%%%%er\n", 3);
	printf("oui c'est ca %d%%%%%%er\n", 3);
	ft_printf("");
	printf("");
	ft_putchar ('\n');
	//ft_putchar ('\n');
	//ft_printf("%-+++-+--2.9d\n", 775800);
	//ft_printf("%  2.9d\n", 775800);
	ft_printf("%-1.llu\n", (unsigned long long)9223372036854775806);
	printf("%-1.llu\n", (unsigned long long)9223372036854775806);
	ft_putchar ('\n');
	ft_printf("%-1.lu\n", (unsigned long)92233720368);
	printf("%-1.lu\n", (unsigned long)92233720368);
	ft_putchar ('\n');
	ft_printf("%+01.hd\n", 123 );
	printf("%+01.hd\n", (short)123 );
	ft_putchar ('\n');
	ft_printf("abcdef %+01.10hhd\n", 123 );
	printf("abcdef %+01.10hhd\n", (unsigned char)123 );
	ft_putchar ('\n');
	ft_printf("%%%%%%%%%d\n", 123 );
	printf("%%%%%%%%%d\n", 123 );
	ft_printf("%%%%%%%%%%d\n", 123 );
	printf("10 d\n");
	ft_printf("%%%%%%%%%%%\n", 123 );
	printf("11\n");
	ft_printf("%%%%%%%%%%%%\n", 123 );
	printf("12\n");
	ft_printf("%1\n"); // mais faudrait trouver exactement pourquoi
	ft_printf("%%%%%%0\n");
	ft_printf("%%%%%0\n");
	ft_printf("%.28ll+++-+--d\n", (unsigned long long)9223372036854775806);
	printf("%+++-+--.28lld\n", (unsigned long long)9223372036854775806);
	ft_printf("%+++-+--.28lld\n", (unsigned long long)9223372036854775806);

	ft_printf("abc %#d\n", 12); // '#d'
	ft_printf("abc %#hd o\n", 123);
	printf("x:%+.15ld\n", 123456789123); // '+' 'pre'
	printf("x:%+15ld\n", 123456789123); // '+' 'gab'
	printf("x:%015ld\n", 123456789123); // '-' '0'
	printf("x:%.2s\n", "a\0bcdef"); // 'pre'
*/	
	//printf("abc %c\n", 123);
	//printf("x:%.2s\n", "a\0bcdef"); // '+' 'gab'
/*
	printf("abc %s\n", "abcdef");
	ft_printf("abc %s\n", "abcdef");
	printf("********************************\n");
	printf("def %S\n", L"abcdef");
	ft_printf("def %S\n", "abcdef");
	printf("********************************\n");
	printf("abc %ls\n", L"abcdef");
	ft_printf("abc %ls\n", "abcdef");
	printf("********************************\n");
	printf("err++++++++++lS\n");
	ft_printf("def %lS\n", "abcdef");
	printf("********************************\n");
	printf("shin: %lu\n", sizeof(unsigned long long int));
*/
	printf("abc %c\n", 'c');
	ft_printf("abc %c\n", 'c');
	printf("********************************\n");
	printf("def %C\n", 'c');
	ft_printf("def %C\n", 'c');
	printf("********************************\n");
	printf("abc %lc\n", 'c');
	ft_printf("abc %lc\n", 'c');
	printf("********************************\n");
	printf("err+++++++++lC\n");
	ft_printf("def %lC\n", 'c');
	printf("********************************\n");
/*
	char c = 'z';

	ft_printf("p:%p\n", &c);
	printf("p:%p\n", &c);
	ft_printf("q:%u\n", 123);
	printf("q:%zu\n", 123123123123);
*/




//	while (1)
//	{}
	
	return (0);
}
