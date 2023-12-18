#include <unistd.h>

int	is_total_numeric(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] == '0')
	{
		j = 0;
		while (str[i + j + 1])
		{
			str[i + j] = str[i + j + 1];
			j++;
		}
		if (i != j)
			str[i + j] = str[i + j + 1];
		else
			break;
			
	}
	while (str[i] <= '9' && str[i] >= '0')
		i++;
	if (str[i] == '\0' && i != 0)
		return (1);
	return (0);
}

void	write_error_message(void)
{
	write(1, "Error\n", 6);
}

int	check_entrie(int argc, char **argv)
{
	if (argc < 2 || argc > 3)
		return (0);
	if (argc == 2)
	{
		if (!is_total_numeric(argv[1]))
			return (0);
		else
			return (1);
	}
	if (argc == 3)
	{
		if (!is_total_numeric(argv[1]))
			return (0);
		else
			return (1);
	}
	return (0);
}
