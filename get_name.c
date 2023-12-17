/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 22:18:31 by rrabeari          #+#    #+#             */
/*   Updated: 2023/12/17 15:17:12 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int		detect_line(char **collection, int nb);
char	*build_str_dict(void);
char	**ft_split(char *str, int *nbline);

void	print_word(char *str)
{
	int	i;

	i = 0;
	while (str[i] <= '9' && str[i] >= '0')
		i++;
	while (str[i] < 33)
		i++;
	while (str[i] == ':')
		i++;
	while (str[i] < 33)
		i++;
	while (str[i])
	{
		write(1, str + i, 1);
		i++;
	}
}

void	print_line_hundred(int nb, int digit, char **collection)
{
	write(1, " ", 1);
	if (digit == 3)
	{
		print_word(collection[detect_line(collection, nb)]);
		write(1, " ", 1);
		print_word(collection[detect_line(collection, 100)]);
		write(1, " ", 1);
	}
	if (digit == 2)
	{
		if (nb <= 20)
		{
			print_word(collection[detect_line(collection, nb)]);
			write(1, " ", 1);
		}
		else
		{
			print_word(collection[detect_line(collection, nb)]);
			write(1, " ", 1);
			if (nb % 10 == 0)
				return ;
			print_word(collection[detect_line(collection, nb % 10)]);
			write(1, " ", 1);
		}
	}
}

void	print_hundred_word(char **collection, int nb)
{
	int	line;

	line = 0;
	if (nb / 100)
	{
		print_line_hundred(nb / 100, 3, collection);
		if (nb % 100)
			write(1, "and", 5);
	}
	if (nb % 100)
	{
		print_line_hundred(nb % 100, 2, collection);
	}
}
/*
int	main(void)
{
	int		i;
	char	*v = build_str_dict();
	char 	**collection = ft_split(v, &i);
	print_hundred_word(collection, 990);
	return (0);
}
*/
