#include <stdlib.h>

int	check_entrie(int argc, char **argv);
int	is_total_numeric(char *str);
void	write_error_message(void);
char	*build_str_dict(void);
char	**ft_split(char *str, int *nbline);
void	print_total(char *str, char **collection);

int main(int argc, char **argv)
{
	int	i;
	char	*v;
	char	**collection;

	if (!check_entrie(argc, argv))
	{
		write_error_message();
		return (0);
	}
	else
	{
		if (argc == 3)
			// creer un simple fonction qui modifie un fichier avec open, et ajoute le mot " argv[1] : argv[2]\n " à la fin du fichier numbers.dict
			//N'oublie pas de fermer le open avec close avant la fin
		if (argc == 2)
		{
			v = build_str_dict();
			collection = ft_split(v, &i);
			print_total(argv[1], collection);
			free(v);
			free(collection);
			return (0);
		}
	}
	return (0);
}

