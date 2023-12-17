/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_dict_to_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:47:49 by rrabeari          #+#    #+#             */
/*   Updated: 2023/12/17 11:57:50 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int		is_printable(char c);
char	*ft_strncpy(char *dest, char *src, int n);
int		nbr_total_dict(char *str);
int		str_len_for_split(char *str, int j);

int	count_return(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (str[i])
	{
		if (str[i] == '\n')
			j++;
		i++;
	}
	return (j);
}

char	**creat_tab(char *str, int *nbline)
{
	int		i;
	int		j;
	int		nbr_return;
	char	**return_value;
	int		len_str;

	i = 0;
	j = 1;
	nbr_return = count_return(str);
	return_value = (char **)malloc(sizeof(char *) * nbr_return);
	while (i < nbr_return)
	{
		len_str = str_len_for_split(str, i + 1) + 1;
		return_value[i] = (char *)malloc(sizeof(char) * len_str);
		i++;
	}
	*nbline = nbr_return;
	return (return_value);
}

void	return_line(char *return_value, char *str, int nb_line)
{
	int	i;
	int	line;
	int	j;

	i = 0;
	line = 1;
	j = 0;
	while (line < nb_line && str[i])
	{
		if (str[i] == '\n')
			line++;
		i++;
	}
	while (str[i + j] != '\n' && str[i + j])
	{
		return_value[j] = str[i + j];
		j++;
	}
	return_value[j] = '\0';
}

char	**ft_split(char *str, int *nbline)
{
	char	**return_value;
	int		i;

	i = 0;
	return_value = creat_tab(str, nbline);
	while (i < *nbline)
	{
		return_line(return_value[i], str, i + 1);
		i++;
	}
	return (return_value);
}

char	*build_str_dict(void)
{
	char			*return_value;
	int				nbr;
	char			*str;
	unsigned int	f;

	str = (char *)malloc(sizeof(char) * 1000000);
	f = open("numbers.dict", O_RDONLY);
	read(f, str, 1000000);
	nbr = nbr_total_dict(str);
	return_value = (char *)malloc(sizeof(char) * nbr);
	return_value = ft_strncpy(return_value, str, nbr - 1);
	free(str);
	close(f);
	return (return_value);
}
