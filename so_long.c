#include "so_long.h"
#include <fcntl.h>

/*verifier le .ber*/
int	ft_file_name(char *av)
{
	int i;

	i = 0;
	while (av[i])
	{
		if (av[i] == '.' && av[i + 1] == 'b' && av[i + 2] == 'e' && av[i + 3] == 'r')
			return (1);
		i++;
	}
	printf("bad file name");
	return (-1);
}

/*checker les var*/
int ft_var(t_var **var)
{
	if ((*var)->item < 1)
	{
		printf("minimum 1 collectible\n");
		return (-1);
	}
	else if ((*var)->door != 1)
	{
		printf("strictement 1 sortie\n");
		return (-1);
	}
	else if ((*var)->start != 1)
	{
		printf("strictement 1 position de depare\n");
		return (-1);
	}
	return (0);
}
/*compter les var*/
int ft_count_var(char *map, t_var **var)
{
	int		i;


	(*var)->v_oid = 0;
	(*var)->wall = 0;
	(*var)->item = 0;
	(*var)->door = 0;
	(*var)->start = 0;
	i = 0;
	while (map[i])
	{
		if (map[i] == '0')
			(*var)->v_oid += 1;
		else if (map[i] == '1')
			(*var)->wall += 1;
		else if (map[i] == 'C')
			(*var)->item += 1;
		else if (map[i] == 'E')
			(*var)->door += 1;
		else if (map[i] == 'P')
			(*var)->start += 1;
		i++;
	}
	if (ft_var(var) == -1)
		return (-1);
	return (0);
}
/*lit le ficher et lance le cj=heck de var*/
int	ft_map_var(char *av, t_var **var)
{
	int fd;
	char *map;
	char *rs;

	(*var)->lrg = 0;
	rs = NULL;
	fd = open(av, O_RDONLY);
	rs = get_next_line(fd);
	while (rs != NULL)
	{
		map = ft_strjoin_gnl(map, rs);
		rs = get_next_line(fd);
		(*var)->lrg++;
		//printf("%d : %s", (*var)->lrg, rs);
	}
	if ((*var)->lrg < 3)
		return (-1);
	if (ft_count_var(map, var) == -1)
		return (-1);
	return (0);
}

/*check si la maps est carrer*/
int ft_is_squar(t_var **var)
{
    int ligne;
    int next_l;
    int i;

    i = 0;
    while ((*var)->maps[i] && (*var)->maps[i + 1])
    {
        ligne = ft_strlen((*var)->maps[i]);
        if ((*var)->maps[i][ligne - 1] == '\n')
            ligne--;
        next_l = ft_strlen((*var)->maps[i + 1]);
        if ((*var)->maps[i + 1][next_l - 1] == '\n')
            next_l--;
        if (ligne != next_l)
        {
            printf("not square\n");
            return (-1);
        }
        i++;
    }
    return (0);
}

/*relit le fichier et place tout dans une matrice*/
int ft_map_shape(char *map, t_var **var)
{
    char    *ligne;
    int     i;
    int     fd;

    i = 0;
    (*var)->maps = malloc(sizeof(char *) * ((*var)->lrg + 1));
    if (!(*var)->maps)
        return (-1);

    fd = open(map, O_RDONLY);
    if (fd == -1)
    {
        //perror("Error opening file");
        free((*var)->maps);
        return (-1);
    }
    ligne = get_next_line(fd);
    while (ligne != NULL && i < (*var)->lrg)
    {
        (*var)->maps[i] = ligne;
        i++;
        ligne = get_next_line(fd);
    }
    (*var)->maps[i] = NULL;
	if (ft_is_squar(var) == -1)
		return (-1);
    return (0);
}
int ft_wall(t_var **var)
{
	int i;

	i = 0;
	while ()

}

int ft_back_tracking(t_var **var)
{
	ft_wall(var);
}


int	ft_parsing(int ac, char **av, t_var **var)
{
	if (ac != 2)
		return (-1);
	if (ft_file_name(av[1]) == -1)
		return (-1);
	if (ft_map_var(av[1], var) == -1)
		return (-1);
	if (ft_map_shape(av[1], var) == -1)
		return (-1);
	if (ft_back_tracking(var) == -1)
		return (-1);

	return (0);
}

int main(int ac, char **av)
{
	t_var *var;
	var = malloc(sizeof(t_var));
	if (!var)
		return (-1);
	ft_parsing(ac, av, &var);
}