#include <fcntl.h>
#include <stdio.h>
#include "./utils/gnl/get_next_line.h"
#include <stdlib.h>
#include <ctype.h>
#include <stddef.h>
#include <stdbool.h>

enum	range
{
	FULLY = 1,
	NOT_FULLY = 0
};

// AB-CD;	A<C && D<B | C<A && B<D |;
//			0<2 && 3<1 | 2<0 && 1<3 |;
int pairComparison(int *fields)
{
	if (fields[0] <= fields[2] && fields[1] >= fields[3])
		return (FULLY);
	if (fields[2] <= fields[0] && fields[3] >= fields[1])
		return (FULLY);
	return (NOT_FULLY);
}

int *pairCreate(char *string)
{
	int index = 0;
	int i = 0;
	int *pair = malloc(sizeof(int) * 4);

	while(string[i])
	{
		pair[index] = atoi(&string[i]);
		printf("Pair %d \t", pair[index]);
		index++;
		while(isdigit(string[i]))
			i++;
		if(string[i])
			i++;
	}
	printf("\n");
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
