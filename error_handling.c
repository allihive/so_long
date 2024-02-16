#include "so_long.h"

void error_msg(char *str)
{
    ft_putstr_fd("Error\n", 2);
    ft_putendl_fd(str, 2);
    exit (1);
}