#include <fcntl.h>
#include <stdio.h>
#include "./utils/gnl/get_next_line.h"
#include <stdlib.h>
#include <ctype.h>
#include <stddef.h>
#include <stdbool.h>

enum	range
{
	OVERLAP = 1,
	NOT_OVERLAP = 0
};

// AB-CD;	A<C && D<B | C<A && B<D || A<C && B<D && B>C| C<A && D<B && D>=A |
//			0<2 && 3<1 | 2<0 && 1<3 || 0<2 && 1<3 && 1>2| 2-0 && 3-1 |

int pairComparison(int *fields)
{
	if (fields[0] <= fields[2] && fields[3] <= fields[1])
		return (OVERLAP);
	if (fields[2] <= fields[0] && fields[1] <= fields[3])
		return (OVERLAP);
	if (fields[0] <= fields[2] && fields[1] <= fields[3] && fields[1] >= fields[2])
		return (OVERLAP);
	if (fields[2] <= fields[0] && fields[3] <= fields[1]&& fields[3] >= fields[0])
		return (OVERLAP);
	return (NOT_OVERLAP);
}

int *pairCreate(char *string)
{
	int index = 0;
	int i = 0;
	int *pair = malloc(sizeof(int) * 4);

	while(string[i])
	{
		pair[index] = atoi(&string[i]);
		index++;
		while(isdigit(string[i]))
			i++;
		if(string[i])
			i++;
	}
	return (pair);
}

int main (void)
{
	int	*fields;
	char *content;
	int count = 0;
	int fd = open("/Users/frame/Desktop/smth/advent_of_code/aoc/day_04/input_files/input.txt", O_RDONLY);

	content = get_next_line(fd);
	while(content != NULL)
	{
		fields = pairCreate(content);
		count += pairComparison(fields);
		content = get_next_line(fd);
	}
	printf("count : %d \n", count);
	return 0;
}
