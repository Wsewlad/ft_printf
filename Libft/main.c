/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 16:08:14 by vfil              #+#    #+#             */
/*   Updated: 2017/11/09 16:41:14 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#define KYEL   "\x1B[33m"
#define KGRN  "\x1B[32m"
#define KCYN   "\x1B[36m"
#define RESET "\x1B[0m"

void	ft_putchar_ptr(char *c)
{
	write(1, c, 1);
}

void	ft_putchar_i_ptr(unsigned int i, char *c)
{
	while (i--)
		write(1, c, 1);
	write(1, "\n", 1);
}

char	ft_toupper2(char c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}
char	ft_toupper2_i(unsigned int i, char c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	while (i--)
		printf("%c", c);
	return (c);
}

void		test_arriter(void *t)
{
	printf("ft_arriter: %s\n", (char*)t);
}

int	main(int argc, char **argv)
{
	char	*test;

	test = NULL;
	if (argc > 1)
		test = argv[1];

puts("==================== START =================");

	//ft_memset
	int		str_mset[20] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int		str_ft_mset[20] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	printf(KCYN "memset: %i, res: %s\n" RESET, str_mset[0], memset(str_mset, '$', 5));
	printf(KYEL "ft_memset: %i, res: %s\n\n" RESET, str_ft_mset[0], ft_memset(str_ft_mset, '$', 5));

puts("============================================");

	//ft_bzero
	char	str_bz[20] = "0123456789**********";
	char	str_ft_bz[20] = "0123456789**********";
	char	*ptr_mid;
	char	*ptr_ft_mid;
	char	*ptr_bz;
	char	*ptr_ft_bz;
	size_t	i_bz;

	i_bz = 10;
	ptr_mid = &str_bz[10];
	ptr_ft_mid = &str_ft_bz[10];
	ptr_bz = &str_bz[15];
	ptr_ft_bz = &str_ft_bz[15];

	printf(KCYN "bzero: src: %s, mid: %s, quarter: %s, n = %zu\n" RESET, str_bz, ptr_mid, ptr_bz, i_bz);
	bzero(ptr_mid, i_bz);
	printf(KCYN "///bzero res: src: %s, mid: %s, quarter: %s, n = %zu\n\n" RESET, str_bz, ptr_mid, ptr_bz, i_bz);
	printf(KYEL "ft_bzero: src: %s, mid: %s, quarter: %s\n, n = %zu\n" RESET, str_ft_bz, ptr_ft_mid, ptr_ft_bz, i_bz);
	ft_bzero(ptr_ft_mid, i_bz);
	printf(KYEL "///ft_bzero res: src: %s, mid: %s, quarter: %s, n = %zu\n\n" RESET, str_ft_bz, ptr_ft_mid, ptr_ft_bz, i_bz);

puts("========================================");

	//ft_memcpy
	const char	src_memcpy[30] = "Hello from memcpy!!!";
	char		dest_mcpy[30];
	char		dest_ft_mcpy[30];
	size_t		i_mcpy;

	i_mcpy = 5;
	printf(KCYN "memcpy: before: src = %s, dst = %s\n" RESET, src_memcpy, dest_mcpy);
	printf(KCYN "memcpy: after: src = %s, n = %zu, dst = %s\n\n" RESET, src_memcpy, i_mcpy, memcpy(dest_mcpy, src_memcpy, i_mcpy));
	printf(KYEL "ft_memcpy: before: src = %s, dst = %s\n" RESET, src_memcpy, dest_ft_mcpy);
	printf(KYEL "ft_memcpy: after: src = %s, n = %zu, dst = %s\n\n" RESET, src_memcpy, i_mcpy, ft_memcpy(dest_ft_mcpy, src_memcpy, i_mcpy));

puts("========================================");

	//ft_memccpy
	const char	src_memccpy[30] = "Hello from memcpy!!!";
	char		dest_mccpy[30];
	char		dest_ft_mccpy[30];
	size_t		i_mccpy;

	i_mccpy = 5;
	printf(KCYN "memccpy: before: src = %s, dst = %s\n" RESET, src_memccpy, dest_mccpy);
	memccpy(dest_mccpy, src_memccpy, test[0], i_mccpy);
	printf(KCYN "memccpy: after: src = %s, c = %c, n = %zu, dst = %s\nres = %s\n\n" RESET, src_memccpy, test[0], i_mccpy, dest_mccpy, memccpy(dest_mccpy, src_memccpy, test[0], i_mccpy));

	printf(KYEL "ft_memccpy: before: src = %s, dst = %s\n" RESET, src_memccpy, dest_ft_mccpy);
	ft_memccpy(dest_ft_mccpy, src_memccpy, test[0], i_mccpy);
	printf(KYEL "ft_memccpy: after: src = %s, c = %c, n = %zu, dst = %s\nres = %s\n\n" RESET, src_memccpy, test[0], i_mccpy, dest_ft_mccpy, ft_memccpy(dest_ft_mccpy, src_memccpy, test[0], i_mccpy));

puts("========================================");

	//ft_memmove
	char	src_memmv[30] = "Hello from memcpy!!!";
	char	src_memmv2[30] = "Hello from memcpy!!!";
	size_t		i_mmv;

	i_mmv = 12;
	printf(KCYN "memmove: before: dst = %s\n" RESET, src_memmv);
	memmove(src_memmv + 10, src_memmv + 6, i_mmv);
	printf(KCYN "memmove: after: src = %s, n = %zu, dst = %s\n\n" RESET, src_memmv + 6, i_mmv, src_memmv);
	printf(KYEL "ft_memmove: before: dst = %s\n" RESET, src_memmv2);
	ft_memmove(src_memmv2 + 10, src_memmv2 + 6, i_mmv);
	printf(KYEL "ft_memmove: after: src = %s, n = %zu, dst = %s\n\n" RESET, src_memmv2 + 6, i_mmv, src_memmv2);

puts("========================================");

	//ft_memchr
	char	test2[] = "abcde";
	char	c_mchr;

	c_mchr = 'a';
	if (argv[2])
		c_mchr = argv[2][0];
	printf(KCYN "memchar: s = %s, c = %c, found = %s\n" RESET, test2, c_mchr, memchr(test2, c_mchr, sizeof(test)));
	printf(KYEL "ft_memchar: s = %s, c = %c, found = %s\n\n" RESET, test2, c_mchr, ft_memchr(test2, c_mchr, sizeof(test)));

puts("========================================");

	//ft_memcmp
	char	*test3 = NULL;
	size_t	n_memcmp;

	n_memcmp = 5;
	if (argv[2])
		test3 = argv[2];
	printf(KCYN "memcmp: s1 = %s, s2 = %s, n = %zu, res = %i\n" RESET, test, test3, n_memcmp, memcmp(test, test3, n_memcmp));
	printf(KYEL "ft_memcmp: s1 = %s, s2 = %s, n = %zu, res = %i\n\n" RESET, test, test3, n_memcmp, ft_memcmp(test, test3, n_memcmp));

puts("========================================");

	//ft_strlen
	printf(KCYN "strlen: %s , length: %lu\n" RESET, test, strlen(test));
	printf(KYEL "ft_strlen: %s , length: %zu\n\n" RESET, test, ft_strlen(test));

puts("========================================");

	//ft_strdup
	char	*dest_dup;
	char	*ft_dest_dup;
	
	dest_dup = strdup(test);
	ft_dest_dup = ft_strdup(test);
	printf(KCYN "strdup: %s\n" RESET, dest_dup);
	printf(KYEL "ft_strdup: %s\n\n" RESET, ft_dest_dup);

puts("========================================");

	//ft_strcpy
	char	dst_cpy[11];
	char	ft_dst_cpy[11];

	printf(KCYN "strcpy: %s\n" RESET, strcpy(dst_cpy, test));
	printf(KYEL "ft_strcpy: %s\n\n" RESET, ft_strcpy(ft_dst_cpy, test));

puts("========================================");

	//ft_strncpy
	char	dst_ncpy[6];
	char	ft_dst_ncpy[6];

	printf(KCYN "strncpy: %s\n" RESET, strncpy(dst_ncpy, test, 6));
	printf(KYEL "ft_strncpy: %s\n\n" RESET, ft_strncpy(ft_dst_ncpy, test, 6));

puts("========================================");

	//ft_strcat
	char	s1_cat[15] = "00";
	char	s1_ft_cat[15] = "00";

	printf(KCYN "strcat: %s\n" RESET, strcat(s1_cat, test));
	printf(KYEL "ft_strcat: %s\n\n" RESET, ft_strcat(s1_ft_cat, test));

puts("========================================");

	//ft_strncat
	char	s1_ncat[11] = "aaaaa";
	char	s1_ft_ncat[11] = "aaaaa";

	printf(KCYN "strncat: %s\n" RESET, strncat(s1_ncat, test, 5));
	printf(KYEL "ft_strncat: %s\n\n" RESET, ft_strncat(s1_ft_ncat, test, 5));

puts("========================================");

	//ft_strlcat
	char	dest_lcat[50] = {0};
	char	dest_ft_lcat[50] = {0};
	size_t	i_lcat;

	printf(KCYN "strlcat: %lu,  %s\n" RESET, strlcat(dest_lcat, "Hello ", 4), dest_lcat);
	printf(KYEL "ft_strlcat: %zu,  %s\n\n" RESET, ft_strlcat(dest_ft_lcat, "Hello ", 4), dest_ft_lcat);

	ft_memset(dest_lcat, 0, sizeof(dest_lcat));
	ft_memset(dest_ft_lcat, 0, sizeof(dest_lcat));
	
	printf(KCYN "strlcat: %lu,  %s\n" RESET, strlcat(dest_lcat, "Hello ", 4), dest_lcat);
	printf(KYEL "ft_strlcat: %zu,  %s\n\n" RESET, ft_strlcat(dest_ft_lcat, "Hello ", 4), dest_ft_lcat);

	printf(KCYN "strlcat: %lu,  %s\n" RESET, strlcat(dest_lcat, "Hello ", 1), dest_lcat);
	printf(KYEL "ft_strlcat: %zu,  %s\n\n" RESET, ft_strlcat(dest_ft_lcat, "Hello ", 1), dest_ft_lcat);
	i_lcat = 0;
	while (i_lcat < 6)
	{
		dest_lcat[4 + i_lcat] = 'z';
		dest_ft_lcat[4 + i_lcat] = 'z';
		++i_lcat;
	}
	printf(KCYN "strlcat: %lu,  %s\n" RESET, strlcat(dest_lcat, "abc", 6), dest_lcat);
	printf(KYEL "ft_strlcat: %zu,  %s\n\n" RESET, ft_strlcat(dest_ft_lcat, "abc", 6), dest_ft_lcat);

	char	d_lcat[10];
	char	d2_lcat[10];
	bzero(d_lcat, 10);
	bzero(d2_lcat, 10);
	memset(d_lcat, 'a', 10);
	memset(d2_lcat, 'a', 10);
	printf(KCYN "strlcat: %lu, %s\n" RESET, ft_strlcat(d_lcat, "ccc", 10), d_lcat);
	printf(KYEL "ft_strlcat: %zu, %s\n\n" RESET, strlcat(d2_lcat, "ccc", 10), d2_lcat);

puts("========================================");

	//ft_strchr
	char	s_ft_chr[] = "unitfactory_cool";

	printf(KCYN "strchr: %s, res: %s\n" RESET, s_ft_chr, strchr(s_ft_chr, 'c'));
	printf(KYEL "ft_strchr: %s, res: %s\n\n" RESET, s_ft_chr, ft_strchr(s_ft_chr, 'c'));

puts("========================================");

	//ft_strrchr
	printf(KCYN "strrchr: %s, res: %s\n" RESET, s_ft_chr, strrchr(s_ft_chr, 'c'));
	printf(KYEL "ft_strrchr: %s, res: %s\n\n" RESET, s_ft_chr, ft_strrchr(s_ft_chr, 'c'));

puts("========================================");

	printf(KCYN "strrchr: %s, res: %s\n" RESET, s_ft_chr, strrchr(s_ft_chr, 'u'));
	printf(KYEL "ft_strrchr: %s, res: %s\n\n" RESET, s_ft_chr, ft_strrchr(s_ft_chr, 'u'));

puts("========================================");

	//ft_strstr
	char s1[] = "MZIRIBMZIRIBMZP";
	char s2[] = "MZIRIBMZP";

	printf(KCYN "strstr: %s, res: %s\n" RESET, s1, strstr(s1, s2));
	printf(KYEL "ft_strstr: %s, res: %s\n\n" RESET, s1, ft_strstr(s1, s2));

puts("========================================");

	//ft_strnstr

	printf(KCYN "strnstr n = 5: %s, res:\n" RESET, strnstr("unitfactory", "it", 5));
	printf(KYEL "ft_strnstr n = 5: %s, res:\n\n" RESET, ft_strnstr("unitfactory", "it", 5));

	printf(KCYN "strnstr n = 15: %s\n" RESET, strnstr("ozaraboze123", "ozaraboze", 15));
	printf(KYEL "ft_strnstr n = 15: %s\n\n" RESET, ft_strnstr("ozaraboze123", "ozaraboze", 15));

puts("========================================");

	//ft_strcmp
	char	s1_cmp[] = "abcdefg";

	printf(KCYN "strcmp s1: %s, s2: %s, res: %i\n" RESET, s1_cmp, test, strcmp(s1_cmp, test));
	printf(KYEL "ft_strcmp s1: %s, s2: %s, res: %i\n\n" RESET, s1_cmp, test, ft_strcmp(s1_cmp, test));

puts("========================================");

	//ft_strncmp
	int	ncmp;

	ncmp = 3;
	printf(KCYN "strncmp n = %i, s1: %s, s2: %s, res: %i\n" RESET, ncmp, s1_cmp, test, strncmp(s1_cmp, test, ncmp));
	printf(KYEL "ft_strncmp n = %i, s1: %s, s2: %s, res: %i\n\n" RESET, ncmp, s1_cmp, test, ft_strncmp(s1_cmp, test, ncmp));

	printf(KCYN "strncmp n = 0, s1: q, s2: a, res: %i\n" RESET, strncmp("q", "a", 0));
	printf(KYEL "ft_strncmp n = 0, s1: q, s2: a, res: %i\n\n" RESET, ft_strncmp("q", "a", 0));

	printf(KCYN "strncmp n = 2, s1: abc, s2: abd, res: %i\n" RESET, strncmp("abc", "abd", 2));
	printf(KYEL "ft_strncmp n = 2, s1: abc, s2: abd, res: %i\n\n" RESET, ft_strncmp("abc", "abd", 2));

puts("========================================");

	//ft_atoi
	printf("ft_atoi\n\n");
	int i_ati;
	char *str_ati;
	char *array_ati[100] = {
	  "",
	  "-1",
	  "0",
	  "-0",
	  "+0",
	  "-2147483648",
	  "2147483647",
	  "-2147483649",
	  "2147483648",
	  "-2147483650",
	  "2147483649",
	  "-2147483648000",
	  "2147483647000",
	  "-2147483648123",
	  "2147483647123",
	  "-9223372036854775808",
	  "9223372036854775807",
	  "-9223372036854775809",
	  "9223372036854775809",
	  "-9223372036854775900",
	  "9223372036854775900",
	  "-9223372036854775808123",
	  "9223372036854775807132",
	  "999999999999999999999999999999999999",
	  "-999999999999999999999999999999999999",
	  "99999999999999999999999999999999999912345678901234567890123456789012345678901234567890123456789012345678901234567890",
	  "-99999999999999999999999999999999999912345678901234567890123456789012345678901234567890123456789012345678901234567890",
	};

	i_ati = 0;
	while(array_ati[i_ati] != NULL)
	{
	  str_ati = array_ati[i_ati];

	  puts("========================================");
	  printf(KGRN "STR: \"%s\"\n" RESET, str_ati);
	  puts("----------------------------------------");
	  printf(KCYN "atoi: %d\n" RESET, atoi(str_ati));
	  printf(KYEL "ft_atoi: %d\n" RESET, ft_atoi(str_ati));
	  i_ati++;
	}

puts("========================================");

	//ft_isalpha
	printf(KCYN "isalpha: %c, res: %i\n" RESET, test[0], isalpha(test[0]));
	printf(KYEL "ft_isalpha: %c, res: %i\n\n" RESET, test[0], ft_isalpha(test[0]));

puts("========================================");

	//ft_isdigit
	printf(KCYN "isdigit: %c, res: %i\n" RESET, test[0], isdigit(test[0]));
	printf(KYEL "ft_isdigit: %c, res: %i\n\n" RESET, test[0], ft_isdigit(test[0]));

puts("========================================");

	//ft_isalnum
	printf(KCYN "isalnum: %c, res: %i\n" RESET, test[0], isalnum(test[0]));
	printf(KYEL "ft_isalnum: %c, res: %i\n\n" RESET, test[0], ft_isalnum(test[0]));

puts("========================================");

	//ft_isascii
	int i_ascii;

	i_ascii = 0;
	while (i_ascii < 130)
	{
		printf(KCYN "isascii: %i = %c, res: %i	" RESET, i_ascii, i_ascii, isascii(i_ascii));
		printf(KYEL "ft_isascii: %i = %c, res: %i\n" RESET, i_ascii, i_ascii, ft_isascii(i_ascii));
	i_ascii++;
	}

puts("========================================");

	//ft_isprint
	int i_print;

	i_print = 31;
	while (i_print < 128)
	{
		printf(KCYN "isprint: %i = %c, res: %i	" RESET, i_print, i_print, isprint(i_print));
		printf(KYEL "ft_isprint: %i = %c, res: %i\n" RESET, i_print, i_print, ft_isprint(i_print));
	i_print++;
	}

puts("========================================");

	//ft_toupper
	printf(KCYN "toupper: %c, res: %c\n" RESET, test[0], toupper(test[0]));
	printf(KYEL "ft_toupper: %c, res: %c\n\n" RESET, test[0], ft_toupper(test[0]));

puts("========================================");

	//ft_tolower
	printf(KCYN "tolower: %c, res: %c\n" RESET, test[0], tolower(test[0]));
	printf(KYEL "ft_tolower: %c, res: %c\n\n" RESET, test[0], ft_tolower(test[0]));

puts("========================================");

	//ft_memalloc
	char	*memalloc = NULL;
	size_t i_malloc;

	i_malloc = 0;
	memalloc = (char*)ft_memalloc(10);
	while (i_malloc < 10)
	{
		memalloc[i_malloc] = argv[1][i_malloc];
		i_malloc++;
	}
	printf(KYEL "ft_memalloc: %s\n\n" RESET, memalloc);	
	
puts("========================================");

	//ft_memdel
	ft_memdel((void*)&memalloc);
	printf(KYEL "ft_memdel: %s\n\n" RESET, memalloc);

puts("========================================");

	//ft_strnew
	char	*strnew = NULL;
	size_t i_strnew;

	i_strnew = 0;
	strnew = ft_strnew(10);
	while (i_strnew < 10)
	{
		strnew[i_strnew] = argv[1][i_strnew];
		i_strnew++;
	}
	printf(KYEL "ft_memalloc: %s\n\n" RESET, strnew);	

puts("========================================");

	//ft_memdel
	ft_strdel(&strnew);
	printf(KYEL "ft_strdel: %s\n\n" RESET, strnew);

puts("========================================");

	//ft_strclr
	char	str_clr[] = "0123456789";
	printf(KYEL "ft_strclr: before: str = %s, str + 5 = %s\n" RESET, str_clr, str_clr + 5);
	ft_strclr(str_clr);
	printf(KYEL "ft_strclr: after: str = %s, str + 5 = %s\n\n" RESET, str_clr, str_clr + 5);

puts("========================================");

	//ft_striter

	printf(KYEL "\n\nft_striter: s = %s, NULL\n" RESET, test);
	ft_striter(test, NULL);

	printf(KYEL "ft_striter: s = %s, &ft_putchar_ptr\n" RESET, test);
	ft_striter(test, &ft_putchar_ptr);

puts("\n\n========================================");

	//ft_striteri
	printf(KYEL "\n\nft_striteri:\n" RESET);
	ft_striteri(test, &ft_putchar_i_ptr);
	printf("\n\n");

puts("========================================");

	//ft_strmap
	printf(KYEL "ft_strmap: %s, ft_toupper: %s\n\n" RESET, test, ft_strmap(test, &ft_toupper2));

puts("========================================");

	//ft_strmapi
	printf(KYEL "ft_strmapi: %s\n" RESET, test);
	char *t = ft_strmapi(test, &ft_toupper2_i);
	printf("\nres: %s\n\n" RESET, t);

puts("========================================");

	//ft_strequ
	printf(KYEL "ft_strequ: s1 = %s, s2 = %s, res: %i\n\n" RESET, argv[1], argv[2], ft_strequ(argv[1], argv[2]));

puts("========================================");

	//ft_strnequ
	printf(KYEL "ft_strnequ: s1 = %s, s2 = %s, n = 5, res = %i\n\n" RESET, argv[1], argv[2], ft_strnequ(argv[1], argv[2], 5));

puts("========================================");

	//ft_strsub
	printf(KYEL "ft_strsub: s = %s, start = 5, len = 7, new = %s\n\n" RESET, test, ft_strsub(test, 5, 7));

puts("========================================");

	//ft_strjoin
	printf(KYEL "ft_strjoin: s1 =%s, s2 = %s, new = %s\n\n" RESET, argv[1], argv[2], ft_strjoin(argv[1], argv[2]));

puts("========================================");

	//ft_strtrim
	printf(KYEL "ft_strtrim: s = %s, new = %s\n\n" RESET, argv[1], ft_strtrim(argv[1]));
	
puts("========================================");

	//ft_strsplit
	char	**new_split;
	int		i_split;
	char *s = "     hello  ololo";

	i_split = 0;
//	new_split = ft_strsplit(argv[1], argv[2][0]);
	new_split = ft_strsplit(s, ' ');
	while (*new_split)
	{
		printf(KYEL "ft_strsplit = %s\n" RESET, *new_split);
		new_split++;
		i_split++;
	}
	printf("\n");

puts("========================================");

	//ft_arriter
	ft_arriter(new_split - i_split, &test_arriter);

puts("========================================");

	//ft_itoa
	int i_itoa = -2147483648;
	printf(KYEL "\nft_itoa = %s, int = %i\n" RESET, ft_itoa(i_itoa), i_itoa);
	printf(KYEL "ft_itoa = %s, int = 0\n\n" RESET, ft_itoa(0));

puts("========================================");

	//ft_putchar
	ft_putchar(argv[2][0]);

puts("\n\n========================================");

	//ft_putstr
	ft_putstr("\nft_putstr: Hello, World!!!\n\n");

puts("========================================");

	//ft_putendl
	ft_putendl("ft_putendl: Hello, World!!!\n");

puts("========================================");

	//ft_putnbr
	ft_putstr("ft_putnbr: ");
	ft_putnbr(ft_atoi(argv[1]));
	ft_putstr("\n\n");

puts("========================================");

	//ft_putchar_fd
	ft_putstr("ft_putchar_fd: ");
	ft_putchar_fd('c', 1);
	ft_putstr("\n\n");

puts("========================================");

	//ft_putstr_fd
	ft_putstr_fd("ft_putstr_fd: ", 1);
	ft_putstr_fd(argv[1], 1);
	ft_putstr_fd("\n\n", 1);

puts("========================================");

	//ft_putendl_fd
	ft_putendl_fd("ft_putendl_fd:", 1);
	ft_putendl_fd(argv[1], 1);

puts("========================================");

	//ft_putnbr_fd
	ft_putstr_fd("\n\nft_putnbr_fd: ", 1);
	ft_putnbr_fd(ft_atoi(argv[1]), 1);

puts("\n\n========================================");

	//ft_lstnew
	ft_print_list(ft_lstnew("\n\nHello, lstnew!!!", 16));
	ft_print_list(ft_lstnew(NULL, 10));
	ft_print_list(ft_lstnew("Hello, lstnew!!!", 0));

puts("========================================");

	//ft_lstdelone
	t_list	*delone;

	ft_putstr("Before ft_lstdelone:\n");
	delone = ft_lstnew("delone-1", 8);
	ft_lstadd(&delone, ft_lstnew("delone-0", 8));
	ft_print_list(delone);
	ft_lstdelone(&delone, &ft_lstdelcont);
	ft_putstr("After ft_lstdelone:\n");
	ft_print_list(delone);

puts("========================================");

	//ft_itoa_base
	printf(KYEL "\nft_itoa_base: n = %d, base = %i, res = %s\n\n" RESET, ft_atoi(argv[1]), ft_atoi(argv[2]), ft_itoa_base(ft_atoi(argv[1]), ft_atoi(argv[2])));

puts("================= END ====================");

	return (0);
}








