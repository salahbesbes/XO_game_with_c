#include "header.h"
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <stdlib.h>
const SDL_Color GRID_COLOR = {.r = 255, .g = 255, .b = 255};
const SDL_Color PLAYER_X_COLOR = {.r = 50, .g = 50, .b = 255};
const SDL_Color PLAYER_O_COLOR = {.r = 255, .g = 100, .b = 50};
const SDL_Color TIE_COLOR = {.r = 100, .g = 100, .b = 100};
/**
 * render_grid - render grid
 * @render: renderer
 * @color
 *
 * Return: void
 */
void render_grid(SDL_Renderer *render, const SDL_Color *color)
{
	int i = 1;

	SDL_SetRenderDrawColor(render, color->r, color->g, color->b, 255);

	for (i = 0; i < N; i++)
	{
		SDL_RenderDrawLine(render, 0, _Width * i / 3, _Width, _Width * i / 3);
		SDL_RenderDrawLine(render, _Height * i / 3, 0, _Height * i / 3, _Height);
	}
}

/**
 * render_x - render X
 * @render: renderer
 * @row: position in row
 * @column: position in column
 * @color: color
 * @arg: desc
 *
 * Return: void
 */
void render_x(SDL_Renderer *render, int row, int column,
	      const SDL_Color *color)
{
	const float half_box_side = fmin(CELLWIDTH, CELLHIGHT) * 0.25;
	const float center_x = CELLWIDTH * 0.5 + column * CELLWIDTH;
	const float center_y = CELLHIGHT * 0.5 + row * CELLHIGHT;

	SDL_SetRenderDrawColor(render, color->r, color->g, color->b, color->a);

	SDL_RenderDrawLine(render,
			   center_x - half_box_side,
			   center_y - half_box_side,
			   center_x + half_box_side,
			   center_y + half_box_side);
	SDL_RenderDrawLine(render,
			   center_x + half_box_side,
			   center_y - half_box_side,
			   center_x - half_box_side,
			   center_y + half_box_side);
	thickLineRGBA(render,
		      center_x - half_box_side,
		      center_y - half_box_side,
		      center_x + half_box_side,
		      center_y + half_box_side, 10,
		      color->r, color->g, color->b, 255);
	thickLineRGBA(render,
		      center_x + half_box_side,
		      center_y - half_box_side,
		      center_x - half_box_side,
		      center_y + half_box_side, 10,
		      color->r, color->g, color->b, 255);
	/*
	 */
}

/**
 * render_o - render  O
 * @render: renderer
 * @row: position in row
 * @column: position in column
 * @color: color
 * Return: void
 */
void render_o(SDL_Renderer *render, int row, int column,
	      const SDL_Color *color)
{

	const float half_box_side = fmin(CELLWIDTH, CELLHIGHT) * 0.25;
	const float center_x = CELLWIDTH * 0.5 + column * CELLWIDTH;
	const float center_y = CELLHIGHT * 0.5 + row * CELLHIGHT;

	SDL_SetRenderDrawColor(render, color->r, color->g, color->b, color->a);
	filledCircleRGBA(render,
			 center_x,
			 center_y,
			 half_box_side + 5,
			 color->r, color->g, color->b, 255);
	filledCircleRGBA(render,
			 center_x,
			 center_y,
			 half_box_side - 5,
			 0, 0, 0, 255);
}

/**
 * render_board - render the content of each cell
 * @render: renderer
 * @board: array of int
 * @color_O: blue
 * @color_X: red
 *
 * Return: void
 */
void render_board(SDL_Renderer *render, int *board,
		  const SDL_Color *color_O, const SDL_Color *color_X)
{
	int i = 0, j = 0;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			switch (board[i * N + j])
			{
			case Player_X:
				render_x(render, i, j, color_X);
				break;
			case Player_O:
				render_o(render, i, j, color_O);
				break;
			default:
				break;
			}
		}
	}
}

/**
 * render_running_state - render game when its not finiched yet
 * @render: renderer
 * @game: pointer to strcut game
 *
 * Return: void
 */
void render_running_state(SDL_Renderer *render, game_t *game)
{

	render_grid(render, &GRID_COLOR);
	render_board(render, game->board, &PLAYER_O_COLOR, &PLAYER_X_COLOR);
}
/**
 * render_game_over_state - render game when one of the player won or in case of
 * tie
 * @render: renderer
 * @game: pointer to strcut game
 *
 * Return: void
 */
void render_game_over_state(SDL_Renderer *render, game_t *game,
			    const SDL_Color *color)
{
	render_grid(render, color);
	render_board(render, game->board, color, color);
}

/**
 * render_game - render game is different senario of the state
 * @arg: desc
 * @render: renderer
 * @game: pointer to strcut game
 *
 * Return: void
 */
void render_game(SDL_Renderer *render, game_t *game)
{
	switch (game->state)
	{
	case ISRunning:
		render_running_state(render, game);
		break;
	case Pl_X_win:
		render_game_over_state(render, game, &PLAYER_X_COLOR);
		break;
	case Pl_O_win:
		render_game_over_state(render, game, &PLAYER_O_COLOR);
		break;
	case Tie:
		render_game_over_state(render, game, &TIE_COLOR);
		break;
	default:
		break;
	}
}
