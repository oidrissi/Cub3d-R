#include "../includes/cub3D.h"
#include <stdbool.h>

int check_file_existence(char *name_checker)
{
	int fd;

	fd = open(name_checker, O_RDONLY);
	if (fd <= ERR)
		return (perror_return(name_checker, EXIT_FAILURE));
	close(fd);
	return (0x0);
}

void retrieve_and_free_north(t_variables vars, char **name_checker)
{
	t_map map;

	map.north = *name_checker;
	check_file_existence(*name_checker);
	free(*name_checker);
}

bool check_north_texture(t_variables vars, char *str)
{
	int i;
	char *name_checker;

	i = 0;
	if (str[i] != 'N' || str[i + 1] != 'O')
		return (false);
	i += 2;
	while (str[i] == ' ')
	{
		i++;
		if (str[i] == '\0')
			return (false);
	}
	if (str[i] != '.' || str[i + 1] != '/')
		return (false);
	i++;
	name_checker = strdup(str + i);
	i = 0;
	while (name_checker[i])
		i++;
	if (name_checker[i - 1] != 'm' || name_checker[i - 2] != 'p' ||
		name_checker[i - 3] != 'x' || name_checker[i - 4] != '.')
		{
			printf("XPM Failure - Texture --> %s\n", name_checker);
			free(name_checker);
			return (false);
		}
	retrieve_and_free_north(vars, &name_checker);
	return (true);
}



int main(int argc, char **argv)
{
	t_variables vars;

	char *str = "NO./textures/wood.xpm";
	if (check_north_texture(vars, str))
		printf("All Good\n");
	leaks();
	return (0);
}