#ifndef DYNTAB_H
# define DYNTAB_H

# include "libft.h"


typedef struct          s_dtab
{
    void                *data;
    const unsigned int	size;
    const char          offset[sizeof(unsigned int) * 3];  
}                       t_dtab;

typedef struct          s_dtab_op
{
    void                *data;     //the token array;
    unsigned int        size;        // the number of token in array;
    unsigned int        cell_size;   // size of cell;
    unsigned int        ability;     //actual max size of array;
    unsigned int        offset;      //se below;
}                       t_dtab_op;

int                     dtab_init(t_dtab *dtab, unsigned int offset, unsigned int cell_size);
unsigned int            dtab_push(t_dtab *dtab, void *tok);
void                    dtab_del(t_dtab *dtab);
void                    dtab_move(t_dtab *udtab, unsigned int old_index, unsigned int index, int groupe);

#endif
