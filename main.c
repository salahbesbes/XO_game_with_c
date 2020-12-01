#include "header.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>


/**
* main - XO Game
* @argc: nb of args
* @argv: array of strings
*
* Return: 0
* Error: -1
*/
int main(int argc, char *argv[])
{

	SDL_Window *window = NULL;
	SDL_Renderer *rendered = NULL;
	bol success = false;
	SDL_Event e;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		printf("can't init() : %s\n", SDL_GetError());
	else
	{
		window = SDL_CreateWindow("X-O", SDL_WINDOWPOS_CENTERED,
				SDL_WINDOWPOS_CENTERED,
				_Height, _Width, 0);
		if (!window)
			printf("can't create window = %s\n", SDL_GetError());
		else
		{
			rendered = SDL_CreateRenderer(window, -1,
					SDL_RENDERER_ACCELERATED |
					SDL_RENDERER_PRESENTVSYNC);
			if (!rendered)
				printf("cant create rendrer = %s\n",
						SDL_GetError());
			else
				success = true;
		}
	}
	if (success)
	{
		game_t game = {
			.players = Pl_X_win,
			.state = ISRunning,
			.board = {
					EMPTY, EMPTY, EMPTY,
					EMPTY, EMPTY, EMPTY,
					EMPTY, EMPTY, EMPTY,
				}
			};
		while (game.state != STOP)
		{
			while (SDL_PollEvent(&e))
			{
				switch (e.type)
				{
					case SDL_QUIT:
						game.state = STOP;
						break;
					case SDL_MOUSEBUTTONDOWN:
						handle_logic(e.button.x,
								e.button.y,
								&game
								);
						break;
				}
			}
			SDL_SetRenderDrawColor(rendered, 0, 0, 0, 255);
			SDL_RenderClear(rendered);
			render_game(rendered, &game);
			SDL_RenderPresent(rendered);
		}
		SDL_DestroyRenderer(rendered);
		SDL_DestroyWindow(window);
		SDL_Quit();

	}
	return (0);
}
