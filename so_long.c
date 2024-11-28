#include <fcntl.h>
#include "libft/libft.h"
#include "so_long.h"

int	ft_file_name(char *av)
{
	int i;

	i = 0;
	while (av[i])
	{
		if (av[i] == '.' && av[i + 1] == 'b' && av[i + 2] == 'e' && av[i + 3] == 'r')
			return (0);
		i++;
	}
	return (1);
}
int ft_var(t_var **game)
{
	if ((*game)->collectible < 1)
	{
		printf("minimum 1 collectible\n");
		return (-1);
	}
	else if ((*game)->end != 1)
	{
		printf("strictement 1 sortie\n");
		return (-1);
	}
	else if ((*game)->start != 1)
	{
		printf("strictement 1 position de depare\n");
		return (-1);
	}
	return (0);
}

//int	ft_parsing(int ac, char **av)
//{
//	if (ac != 2)
//	{
//		perror("mauvais nombre d'argument")
//		exite(1);
//	}
//	if (ft_file_name(av[1]) == 1)
//	{
//		perror("mauvais nom de fichier")
//		exite(1);
//	}
//	if (ft_map_var(av[1]) == 1)
//	{
//		perror("probleme de variable de map")
//		exite(1);
//	}
//	if (ft_map_shape(av[1]) == 1)
//	{
//		perror("la map n'est pas reglementaire")
//		exite(1);
//	}

//	return (0);
//}

char **ft_fill_map(char **av)
{

	int i;
	int fd;
	char **map;
	char *rs;

	i = 0;
	fd = open(av[1], O_RDONLY);
	rs = get_next_line(fd);
	while(rs != NULL)
	{
		map[i] = ft_strdup(rs);
		rs = get_next_line(fd);
		i++;
	}
	return (map);
}

int ft_get_map_data(int ac, char **av, t_game *game, t_map *map)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = ft_fill_map(av);
	while(map[i])
	{
		j = 0;
		while(map[j])
		{
			if (map[j] == '1')
				game->wall++;
			else if (map[j] == '0')
				game->floor++;
			else if (map[j] == 'C')
				game->item++;
			else if (map[j] == 'P')
				game->start++;
			else if (map[j] == 'E')
				game->end++;
		}
		j++;
	}
	game->length = i;
	game->width = j;
}

int main(int ac, char **av)
{
	t_game	game;
	t_map	map;

	if (ft_file_name(av) == 1)
		exit(1);
	ft_init(game, map);
	ft_get_map_data(ac, av, &game, &map);

	
}