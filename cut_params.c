/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:36:05 by rrabeari          #+#    #+#             */
/*   Updated: 2023/12/17 18:21:05 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int		count_nbr_lettre(char *str);
char	*cut_nbr(char *str);
void	print_word(char *str);
int		detect_mill(char **collection, char *find);
void	print_hundred_word(char **collection, int nb);
int		detect_line(char **collection, int nb);
char	*build_str_dict(void);
char	**ft_split(char *str, int *nbline);

int	atoi_special(char *str, int begin, int end)
{
	int	return_value;

	return_value = 0;
	while (begin <= end)
	{
		return_value = return_value * 10 + str[begin - 1] - '0';
		begin++;
	}
	return (return_value);
}

void	print_mill_1_6(int pow, char **collection)
{
	int	index_mill;

	if (pow == 1)
		index_mill = detect_mill(collection, "1000");
	else if (pow == 2)
		index_mill = detect_mill(collection, "1000000");
	else if (pow == 3)
		index_mill = detect_mill(collection, "1000000000");
	else if (pow == 4)
		index_mill = detect_mill(collection, "1000000000000");
	else if (pow == 5)
		index_mill = detect_mill(collection, "1000000000000000");
	else if (pow == 6)
		index_mill = detect_mill(collection, "1000000000000000000");
	print_word(collection[index_mill - 1]);
}

void	print_mill_7_12(int pow, char **coll)
{
	int	index;

	if (pow == 7)
		index = detect_mill(coll, "1000000000000000000000");
	else if (pow == 8)
		index = detect_mill(coll, "1000000000000000000000000");
	else if (pow == 9)
		index = detect_mill(coll, "1000000000000000000000000000");
	else if (pow == 10)
		index = detect_mill(coll, "1000000000000000000000000000000");
	else if (pow == 11)
		index = detect_mill(coll, "1000000000000000000000000000000000");
	else if (pow == 12)
		index = detect_mill(coll, "1000000000000000000000000000000000000");
	print_word(coll[index - 1]);
}

int	writesmt(char *str, int nb, int *mill, char **coll)
{
	int	hundred_print;
	int	i;

	i = 1;
	hundred_print = atoi_special(str, i, nb % 3);
	print_hundred_word(coll, hundred_print);
	if (*mill <= 6)
		print_mill_1_6(*mill, coll);
	else
		print_mill_7_12(*mill, coll);
	*mill = *mill - 1;
	i = nb % 3 + 1;
	return (i);
}

int	writeqlq(char *str, int *i, char **coll)
{
	int	hundred_print;

	hundred_print = atoi_special(str, *i, *i + 2);
	print_hundred_word(coll, hundred_print);
	return (hundred_print);
}

void	print_total(char *str, char **collection)
{
	int	nb_len;
	int	mill_pow;
	int	i;
	int hun;

	i = 1;
	str = cut_nbr(str);
	nb_len = count_nbr_lettre(str);
	mill_pow = 0;
	if (nb_len % 3 && nb_len / 3)
		mill_pow = nb_len / 3;
	else
		mill_pow = nb_len / 3 - 1;
	if (nb_len % 3)
		i = writesmt(str, nb_len, &mill_pow, collection);
	while (mill_pow >= 1)
	{
		hun = writeqlq(str, &i, collection);
		if (hun % 1000)
		{
			if (mill_pow <= 6)
				print_mill_1_6(mill_pow, collection);
			else
				print_mill_7_12(mill_pow, collection);
		}
		mill_pow--;
		i += 3;
	}
	writeqlq(str, &i, collection);
}

int main(int c, char *ar[])
{
	int     i;
    char    *v = build_str_dict();
    char    **collection = ft_split(v, &i);
	print_total(ar[1], collection);
}
