#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "so_long.h"
#include <string.h>

void	write_map_to_file(char *filename, char *map_content)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		printf("Error: Unable to create the file %s\n", filename);
		return;
	}
	write(fd, map_content, strlen(map_content));
	close(fd);
}

void	print_map(char **map)
{
	int	index;

	if (!map)
	{
		printf("Error: Map is NULL");
		return;
	}
	index = 0;
	while (map[index])
	{
		printf("%s", map[index]);
		index++;
	}
}

void	free_map(char **map)
{
	int	index;

	if (!map)
		return;
	index = 0;
	while (map[index])
	{
		free(map[index]);
		index++;
	}
	free(map);
}

int	main(void)
{
	char	**map;
	char	*test_files[] = {"map1.txt", "map2.txt", "map3.txt", "map4.txt", NULL};
	char	*maps[] = {
		"1111\n1P01\n1C01\n1111\n",       // Mapa válido
		"111\n1P01\n1C01\n1111\n",        // Mapa não retangular
		"1111\n1P01\n1C01\n1101\n",       // Borda inferior inválida
		"",                               // Arquivo vazio
		NULL
	};
	int		i;

	i = 0;
	while (maps[i])
	{
		write_map_to_file(test_files[i], maps[i]); // Cria os arquivos de teste
		i++;
	}
	printf("Running map tests...\n");
	i = 0;
	while (test_files[i])
	{
		printf("\nTest %d - File: %s\n", i + 1, test_files[i]);
		map = read_map(test_files[i]);
		if (!map)
			printf("Failed to read map from file %s\n", test_files[i]);
		else
		{
			printf("Map content:\n");
			print_map(map);
			free_map(map);
		}
		i++;
	}
	return (0);
}

