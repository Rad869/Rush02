/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 22:33:25 by rrabeari          #+#    #+#             */
/*   Updated: 2023/12/16 23:54:58 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	return_value;

	i = 0;
	return_value = 0;
	while (str[i] <= '9' && str[i] >= '0' && str[i])
	{
		return_value = return_value * 10 + str[i] - '0';
		i++;
	}
	return (return_value);
}

int	detect_line(char **collection, int nb)
{
	int	i;

	i = 0;
	while (ft_atoi(collection[i]) < nb)
		i++;
	if (ft_atoi(collection[i]) == nb)
		return (i);
	return (i - 1);
}
