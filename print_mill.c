/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 10:59:07 by rrabeari          #+#    #+#             */
/*   Updated: 2023/12/17 14:03:19 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int		is_numeric(char c);
char	*ft_strncpy(char *dest, char *src, int n);
int		detect_line(char **collection, int nb);
char	*build_str_dict(void);
char	**ft_split(char *str, int *nbline);

char	*ft_strcpynm(int n, int m, char *dest, char *src)
{
	int	i;
	int	j;

	i = n;
	j = 0;
	while (i < m && *(src + i) != '\0')
	{
		*(dest + j) = *(src + i);
		j++;
		i++;
	}
	while (i < m)
	{
		*(dest + j) = '\0';
		j++;
		i++;
	}
	return (dest);
}

char	*cut_nbr(char *str)
{
	int		i;
	int		j;
	char	*return_value;

	i = 0;
	j = 0;
	while (str[j] && str[j] < 33)
		j++;
	i = j;
	while (is_numeric(str[i]))
		i++;
	return_value = (char *)malloc(sizeof(char) * (i - j + 1));
	return_value = ft_strcpynm(j, i, return_value, str);
	return_value[i - j + 1] = '\0';
	return (return_value);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (*(s1 + i) && *(s2 + i))
	{
		if (!(*(s1 + i) == *(s2 + i)))
			return ((*(s1 + i) - *(s2 + i)));
		i++;
	}
	if (*(s1 + i) || *(s2 + i))
		return ((*(s1 + i) - *(s2 + i)));
	return (0);
}

int	count_nbr_lettre(char *str)
{
	int	i;

	i = 0;
	while (is_numeric(str[i]))
		i++;
	return (i);
}

int	detect_mill(char **collection, char *find)
{
	char	*coll;
	char	*fi;
	int		len_find;
	int		len_coll;
	int		i;

	i = 0;
	fi = cut_nbr(find);
	len_find = count_nbr_lettre(fi);
	coll = cut_nbr(collection[i]);
	len_coll = count_nbr_lettre(coll);
	while (len_coll < len_find)
	{
		free(coll);
		i++;
		coll = cut_nbr(collection[i]);
		len_coll = count_nbr_lettre(coll);
	}
	free(coll);
	free(fi);
	return (i + 1);
}
