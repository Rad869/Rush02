/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 10:59:38 by rrabeari          #+#    #+#             */
/*   Updated: 2023/12/17 12:10:26 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (i < n && *(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i++;
	}
	while (i < n)
	{
		*(dest + i) = '\0';
		i++;
	}
	return (dest);
}

int	is_printable(char c)
{
	if ((c >= ' ' && c <= '~') || c == '\n')
		return (1);
	return (0);
}

int	nbr_total_dict(char *str)
{
	int	i;

	i = 0;
	while (is_printable(str[i]))
		i++;
	return (i);
}

int	str_len_for_split(char *str, int j)
{
	int	i;
	int	k;
	int	l;

	i = 0;
	k = 1;
	l = 0;
	while (k < j && str[i])
	{
		if (str[i] == '\n')
			k++;
		i++;
	}
	if (str[i])
	{
		if (str[i] == '\n')
			i++;
		while (str[i + l] != '\n' && str[i + l])
			l++;
	}
	return (l);
}

int	is_numeric(char c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}
