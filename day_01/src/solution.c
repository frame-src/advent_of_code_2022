#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include "./utils/gnl/get_next_line.h"
#include "./utils/libft/libft.h"

struct dwarf_list
{
	int					id;
	long int			calories;

	struct dwarf_list	*next_dwarf;
};

static struct dwarf_list	*new_dwarf(int id)
{
	struct dwarf_list	*new;

	new = (struct dwarf_list *)malloc(sizeof(struct dwarf_list));
	if (!new)
		return (NULL);
	new->id = id;
	new->calories = 0;
	new->next_dwarf = NULL;
	return (new);
}

static bool	dwarfs_separator(char *string)
{
	if(string[0] == '\n')
		return (true);
	else
		return(false);
}

static void	dwarfs_go_next(struct dwarf_list **dwarfs, int index)
{
	(*dwarfs)->next_dwarf = new_dwarf(index);
	*dwarfs = (*dwarfs)->next_dwarf;
	(*dwarfs)->calories = 0;
}

static long int	richest_dwarf_index(struct dwarf_list *first_dwarf, long int limit)
{
	long int					tmp_calories = 0;
	int							tmp_id = 0;
	struct dwarf_list	*dwarfs;

	dwarfs = first_dwarf;
	while(dwarfs != NULL)
	{
		if((dwarfs)->calories > tmp_calories && (dwarfs)->calories < limit)
		{
			tmp_id = dwarfs->id;
			tmp_calories = dwarfs->calories;
		}
		dwarfs = dwarfs->next_dwarf;
	}
	return (tmp_calories);
}

int main (void)
{
	int					fd;
	int					i = 1;
	struct dwarf_list	*dwarfs;
	struct dwarf_list	*first_dwarf;
	char				*info;
	long int			richest[3];

	fd = open ("/Users/frmessin/Desktop/advent_of_code/day_01/input_files/input.txt", O_RDONLY);
	dwarfs = new_dwarf(i);
	first_dwarf = dwarfs;
	dwarfs->calories = 0;
	info = get_next_line(fd);
	while (info != NULL)
	{
		if (dwarfs_separator(info) == true)
		{
			++i;
			dwarfs_go_next(&dwarfs, i);
		}
		else
			dwarfs->calories += atoi(info);
		info = get_next_line(fd);
	}
	dwarfs = first_dwarf;
	richest[0] = richest_dwarf_index(first_dwarf, 5656656565);
	richest[1] = richest_dwarf_index(first_dwarf, richest[0]);
	richest[2] = richest_dwarf_index(first_dwarf, richest[1]);
	printf("%ld", richest[0] + richest[1]+ richest[2]);
	return(0);
}
