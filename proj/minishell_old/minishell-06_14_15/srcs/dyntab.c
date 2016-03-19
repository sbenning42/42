# include "dyntab.h"
# include "int_dyntab.h"

int		dt_tabnew(t_dynt *edtab, unsigned int dsize, unsigned int offset)
{
	t_int_dynt	*dtab;

	dtab = (t_int_dynt *)edtab;
	if (dtab == NULL)
		return (0);
	dtab->data = ft_memalloc(dsize * (offset + 1));
	if (dtab->data == NULL)
		return (0);
	dtab->ability = offset;
	dtab->dsize = dsize;
	dtab->offset = offset;
	return (42);
}

void		dt_tabdel(t_dynt *edtab)
{
	t_int_dynt	*dtab;

	dtab = (t_int_dynt *)edtab;
	if (dtab == NULL)
		return ;
	free(dtab->data);
	ft_bzero((void *)dtab, sizeof(t_dynt));
}


int		dt_tabpush(t_dynt *edtab, void *data)
{
	t_int_dynt	*dtab;
	void	*tmp;

	dtab = (t_int_dynt *)edtab;
	if (dtab == NULL)
		return (0);
	if (dtab->size >= dtab->ability)
	{
		tmp = dtab->data;
		dtab->data = ft_memalloc(dtab->dsize * (dtab->ability + dtab->offset + 1));
		if (dtab->data == NULL)
		{
			dtab->data = tmp;
			dt_tabdel(edtab);
			return (0);
		}
		ft_memcpy(dtab->data, tmp, dtab->dsize * dtab->size);
		dtab->ability += dtab->offset;
	}
	ft_memcpy(dtab->data + (dtab->dsize * dtab->size), data, dtab->dsize);
	dtab->size++;
	return (42);
}

static void	dt_dump(void *dump, unsigned int dsize)
{
	unsigned int	i;
	unsigned char		*tmp;

	i = 0;
	tmp = dump;
	while (i < dsize)
	{
		ft_putstr("[");
		ft_putnbr(*(tmp + i));
		i++;
		if (i == dsize)
			ft_putstr("]\n");
		else
			ft_putstr("]-");
	}
}
void		dt_tabput_dump(t_dynt *edtab)
{
	unsigned int	i = 0;
	t_int_dynt	*dtab;

	dtab = (t_int_dynt *)edtab;
	ft_putstr("\n-- DYN TAB --\n\n\tsize\t\t");
	ft_putnbr(dtab->size);
	ft_putstr("\n\tability\t\t");
	ft_putnbr(dtab->ability);
	ft_putstr("\n\toffset\t\t");
	ft_putnbr(dtab->offset);
	ft_putstr("\n\tdsize\t\t");
	ft_putnbr(dtab->dsize);
	ft_putstr("\n\n");
	while (i < dtab->size)
	{
		ft_putstr("\tCell ");
		ft_putnbr(i);
		ft_putstr("\t\t");
		dt_dump(dtab->data + (i++ * dtab->dsize), dtab->dsize);
	}
	ft_putendl("");
}
