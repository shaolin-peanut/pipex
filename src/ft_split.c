#include "pipex.h"

char	*pp_strcpy(char *str, int s, int e)
{
	int		lenght;
	char	*r;

	lenght = e - s + 1; // start + end + 1. Quesaqo?
	r = (char *)malloc(lenght * sizeof(char) + 1);
	if (!r)
		errormsg("malloc error in ft_split.c:pp_strcpy():11");
	r[lenght] = 0;
	while (lenght--)
		r[lenght] = str[s + lenght];
	return (r);
}

static int	line_counter(char *str, char c)
{
	int	r;

	r = 1;
	if (*str == c)
		r = 0;
	while (*str)
	{
		if (*str == c)
		{
			r++;
			while (str[1] == c)
				str++;
		}
		str++;
	}
	if (*(--str) == c)
		r--;
	return (r);
}

char	**ft_split(char *str, char c)
{
	char	**r;
	int		line;
	int		start;
	int		end;
	int		i;

	line = line_counter(str, c); // compte le nombre d'elements a decouper pour malloquer
	r = (char **)malloc(sizeof(char *) * line + 1);
	if (!r)
		return (0);
	r[line] = 0;// met un null a la fin de l'array en avance
	end = 0;
	i = 0;
	while (line--)
	{
		while (str[end] == c) // iter sur le separateur s'il se trouve au debut
			end ++;
		start = end;
		while (str[end] != 0 && str[end] != c) // tant que string est pas fini, et str[i] n'est pas le separateur, itere
			end ++;
		r[i] = pp_strcpy(str, start, end - 1); // quand sep trouver ou fin de string, copy la portion de la string qu'il faut copier dans l'array. Debut et fin sont compter
		if (!r[i++]) // error checking
			return (0);
	}
	return (r);
}
