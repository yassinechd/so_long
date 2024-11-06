#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "libft/libft.h"

typedef struct  s_var
{
    int door;
    int start;
    int wall;
    int item;
    int v_oid;
    char **maps;
    int lrg;
    int lng;
}               t_var;

#endif
