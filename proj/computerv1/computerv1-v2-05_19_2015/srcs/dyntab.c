#include "dyntab.h"
#include "libft.h"

int         dtab_init(t_dtab *udtab, unsigned int offset, unsigned int cell_size)
{
  t_dtab_op *dtab;

  dtab = (t_dtab_op *)udtab;
  if (!(dtab->data = ft_memalloc(cell_size * (offset + 1))))
    return (-1);
  ft_bzero(dtab->data, dtab->cell_size * offset + 1);
  dtab->ability = offset;
  dtab->offset = offset;
  dtab->cell_size = cell_size;
  dtab->size = 0;
    return (8); 
}

unsigned int dtab_push(t_dtab *udtab, void *tok)
{
  t_dtab_op *dtab;

  dtab = (t_dtab_op *)udtab;
  void     *tmp;

  if (dtab->size == dtab->ability)
  {
    tmp = dtab->data;
    if (!(dtab->data = (void *)ft_memalloc(dtab->cell_size * (dtab->ability + dtab->offset + 1))))
      {
        ft_bzero(&tmp, dtab->cell_size * dtab->size);
        ft_memdel(&tmp);
        return (0);
      }
    ft_memcpy(dtab->data, tmp, dtab->cell_size * dtab->size);
    dtab->ability = dtab->ability + dtab->offset;
  }
  ft_memcpy(dtab->data + dtab->size * dtab->cell_size, tok, dtab->cell_size);
  dtab->size = dtab->size + 1;
  return (dtab->size);
}

void         dtab_move(t_dtab *udtab, unsigned int old_index, unsigned int index, int groupe)
{
  t_dtab_op *dtab;
  char      tmp[((t_dtab_op *)udtab)->cell_size * groupe];
  char      tmp2[((t_dtab_op *)udtab)->cell_size * (((t_dtab_op *)udtab)->size - index)];

  dtab = (t_dtab_op *)udtab;
  ft_memcpy(&tmp, &dtab->data[dtab->cell_size * old_index], dtab->cell_size * groupe);
  ft_memcpy(&dtab->data[dtab->cell_size * old_index], \
    &dtab->data[dtab->cell_size * old_index + (dtab->cell_size * groupe)], \
    (dtab->size - old_index - groupe) * dtab->cell_size);
  ft_memcpy(tmp2, &dtab->data[dtab->cell_size * index], (dtab->size - index - groupe) * dtab->cell_size);
  ft_memcpy(&dtab->data[dtab->cell_size * index], tmp, dtab->cell_size * groupe);
  ft_memcpy(&dtab->data[dtab->cell_size * (index + groupe)], \
    tmp2, (dtab->size - (index + groupe)) * dtab->cell_size);
}

void        dtab_del(t_dtab *udtab)
{
  t_dtab_op *dtab;

  dtab = (t_dtab_op *)udtab;
  ft_bzero(dtab->data, dtab->cell_size * dtab->size);
  ft_memdel((void **)&dtab->data);
  ft_bzero(dtab, sizeof(t_dtab));
}
