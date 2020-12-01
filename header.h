#ifndef HEADER
#define HEADER

#define true 1
#define false 0
#define _Width 600
#define _Height 600
#define CELLWIDTH (_Width / 3)
#define CELLHIGHT (_Height / 3)
typedef int bol;

#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_test_images.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL_image.h>



/* not using them in this project */
enum KeyPressSurfaces
{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};

/* grid of 3 * 3 */
#define N 3

/* players */
#define EMPTY 0
#define Player_X 1
#define Player_O 2

/* state */
#define Pl_X_win 1
#define Pl_O_win 2
#define Tie 3
#define ISRunning 4
#define STOP 0

/**
 * struct game_t - all logic is here : we have 2 players and default one , 5
 * states and an array of int that represent the move of the player or an empty
 * cell
 * @players: players
 * @state: senario of the game
 * @board: the board we are playing on it
 */
typedef struct game_t
{
	int players;
	int state;
	int board[N * N];
} game_t;
void render_game(SDL_Renderer *render, game_t *game);
void handle_logic(int x, int y, game_t *game);
#endif
