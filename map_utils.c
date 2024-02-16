#include "so_long.h"

int column_count(char *map)
{
    int row;
    int i;

    row = 0;
    i = 0;
    while (map[i] != '\n' && map[i])
    {
        row++;
        i++;
    }
    return (row);
}

int	row_count(char *map)
{
	int	i;
	int	row;

	i = 0;
	row = 0;
    if (map[0]) //either start row from 1, depending on where this is in the map validation
        row++;
	while (map[i])
	{
		if (map[i] == '\n')
		    row++;
		i++;
	}
	return (row);
}