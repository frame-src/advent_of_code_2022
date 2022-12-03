#include <fcntl.h>
#include <stdio.h>
#include "./utils/gnl/get_next_line.h"
#include <stdlib.h>
#include <ctype.h>
#include <stddef.h>
#include <stdbool.h>

char check_rustpack(char *content)
{
	int pivot;
	int i;
	int j;

	pivot = strlen(content)/2;
	i = 0;
	while(i < pivot){
		j = 0;
		while(content[j + pivot]){
			if(content[i] == content[j + pivot])
				return content[i];
			++j;
		}
		i++;
	}
	return (0);
}

int calculate_value(char object){
	if(islower(object))
		return( 1 + object - 'a');
	else
		return( 27 + object - 'A');
}

int main (void)
{
	char	*content;
	int		amount = 0;
	int fd = open("/Users/frmessin/Desktop/advent_of_code/day_03/input_files/input.txt", O_RDONLY);

	content = get_next_line(fd);
	while (content != NULL)
	{
		printf("Amount : %s \n", content);

		char	object = check_rustpack(content);
		amount += calculate_value(object); 
		content = get_next_line(fd);
	}
	printf("Amount : %d \n", amount);
	return (0);
}
