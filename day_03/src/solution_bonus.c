#include <fcntl.h>
#include <stdio.h>
#include "./utils/gnl/get_next_line.h"
#include <stdlib.h>
#include <ctype.h>
#include <stddef.h>
#include <stdbool.h>

char search_badge(char **content)
{
	int i;
	int j;
	int k;

	i = 0;
	while(i < strlen(content[0])){
		j = 0;
		while(j < strlen(content[1])){
			if(content[0][i] == content[1][j]){
				k = 0;
				while(k < strlen(content[2])){
					if(content[1][j] == content[2][k])
						return(content[0][i]);
					++k;
				}
			}
			++j;
		}
		++i;
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
	char	*content[3];
	int		amount = 0;
	int		rustpack_num;
	char	badge;
	int 	fd;
	int		i;

	fd = open("/Users/frmessin/Desktop/advent_of_code/day_03/input_files/input.txt", O_RDONLY);
	content[0] = get_next_line(fd);
	i = 1;
	while (content[0] != NULL)
	{
		if(i == 3){
			badge = search_badge(content);
			amount += calculate_value(badge); 
			i = 0;
		}
		content[i] = get_next_line(fd);
		i++;
	}
	printf("Amount : %d \n", amount);
	return (0);
}
