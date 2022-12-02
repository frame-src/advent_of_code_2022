#include <fcntl.h>
#include <stdio.h>
#include "./utils/gnl/get_next_line.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include "./utils/libft/libft.h"


enum move_point
{
ROCK=		1,
PAPER=		2,
SCISSORS=	3,
};

enum points
{
WINN=		6,
DRAW=		3,
LOSS=		0
};

static int opponent_move(char move)
{
	if(move == 'A')
		return(ROCK);
	else if(move == 'B')
		return(PAPER);
	else if(move == 'C')
		return(SCISSORS);
	else
		return (0);
}

static int player_move(char move)
{
	if (move == 'X')
		return(ROCK);
	else if (move == 'Y')
		return(PAPER);
	else if (move == 'Z')
		return(SCISSORS);
	else
		return (0);
}

static int	*moves_parsing(char *string)
{
	int		*moves;

	moves = malloc(sizeof(int) * 2);
	moves[0] = opponent_move(string[0]);
	moves[1] = player_move(string[2]);
	return moves;
}

static int calculate_win(int *moves)
{
	if (moves[0] == moves[1])
		return (DRAW);
	else if ((moves[0] == SCISSORS && moves[1] == ROCK) ||\
			 (moves[0] == ROCK && moves[1] == PAPER) ||\
			 (moves[0] == PAPER && moves[1] == SCISSORS) )
		return (WINN);
	else
		return (LOSS);
}

static int calculate_result_bonus(int *moves)
{
	if (moves[1] == DRAW)
		return (DRAW + moves[0]);
	else if(moves[1] == WINN)
	{
		if(moves[0] == SCISSORS)
			return (WINN + ROCK);
		else if (moves[0] == ROCK)
			return (WINN + PAPER);
		else if (moves[0] == PAPER)
			return ( WINN + SCISSORS);
	}
	else
	{
		if(moves[0] == PAPER)
			return (ROCK);
		if(moves[0] == SCISSORS)
			return (PAPER);
		if(moves[0] == ROCK)
			return (SCISSORS);
	}
	return LOSS;
}

int main (void)
{
	char	*strategy;
	int		*moves;
	int		amount = 0;
	int fd = open("/Users/frmessin/Desktop/advent_of_code/day02/input_files/input.txt", O_RDONLY);

	strategy = get_next_line(fd);
	while (strategy != NULL)
	{
		moves = moves_parsing(strategy);
		amount += calculate_result_bonus(moves);
		strategy = get_next_line(fd);
	}
	printf("Amount : %d \n", amount);
	return 0;
}
