#include "header.h"
#include <stdlib.h>



/*
 * if the user click we want to start filling the board at some position
 * with the user x or o
 * check for wining condition if no one win and no more empty cells the game is
 * over
 * then switch the user
 *
 */


/**
 * check_player_won - check if the player has won the game
 * @game: poitet to staruct game_t
 * @player: player
 *
 * Return: 1
 * Error: 0
 */
int check_player_won(game_t *game, int player)
{
	int row_count = 0;
	int column_count = 0;
	int diag1_count = 0;
	int diag2_count = 0;
	int i, j;

	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < N; ++j)
		{
			if (game->board[i * N + j] == player)
				row_count++;
			if (game->board[j * N + i] == player)
				column_count++;
		}
		if (row_count >= N || column_count >= N)
			return (1);
		row_count = 0;
		column_count = 0;

		if (game->board[i * N + i] == player)
			diag1_count++;

		if (game->board[i * N + N - i - 1] == player)
			diag2_count++;
	}
	return (diag1_count >= N || diag2_count >= N);
}

/**
* count_empty_cells - check how many empty cells there is
* @game: pointer to struct game_t
*
* Return: void
*/
int count_empty_cells(game_t *game)
{
	int count = 0, i = 0;

	for (i = 0; i < N * N; ++i)
		if (game->board[i] == EMPTY)
			count++;

	return (count);
}
/**
* game_over_condition - check if one of the player wins the game else its tie
* @game: pointer to struct game_t
*
* Return: void
*/
void game_over_condition(game_t *game)
{
	if (check_player_won(game, Player_X))
		game->state = Pl_X_win;
	else if (check_player_won(game, Player_O))
		game->state = Pl_O_win;
	else if (count_empty_cells(game) == 0)
		game->state = Tie;
}
/**
* switch_user- switch_user
* @game: pointer to struct game_t
*
* Return: void
*/
void switch_user(game_t *game)
{
	if (game->players == Player_X)
		game->players = Player_O;
	else if (game->players == Player_O)
		game->players = Player_X;
}

/**
* player_turn - fill the board of the player value, then check if he will win
* if he dont win switch user and end turn
* @game: pointer to struct game_t
* @row: row
* @column: column
* Return: void
*/
void player_turn(game_t *game, int row, int column)
{

	if (game->board[row * N + column] == EMPTY)
	{
		game->board[row * N + column] = game->players;
		game_over_condition(game);
		switch_user(game);
	}
}
/**
* restart_game - restart_game
* @game: pointer to struct game_t
*
* Return: void
*/
void restart_game(game_t *game)
{
	int i = 0, j = 0;

	game->players = Pl_X_win;
	game->state = ISRunning;
	for (i = 0; i < N * N; i++)
		game->board[i] = EMPTY;
}

/**
* handle_logic - chech if the game is running then do some logic else
* restart the game
* @game: pointer to struct game_t
* @x: coordinate for the width
* @y: coordinate for y
*
* Return: void
*/
void handle_logic(int x, int y, game_t *game)
{
	int row = y / (CELLWIDTH);
	int column = x / (CELLHIGHT);

	if (game->state == ISRunning)
		player_turn(game, row, column);
	else
		restart_game(game);
}
