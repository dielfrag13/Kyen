#include <iostream>
#include <SDL2\SDL.h>
#include "Player.h"

struct EventData {
	bool loop;
	bool render;
};

void EventHandler(EventData &data);
void EventHandler_Mouse(SDL_Event &event, EventData &data);
void EventHandler_Keyboard(SDL_Event &event, EventData &data);

Player *g_player;


int main(int argc, char **argv)
{
	int width = 640;
	int height = 480;
	Uint32 windowFlags = SDL_WINDOW_RESIZABLE;
	Uint32 rendererFlags = SDL_RENDERER_ACCELERATED;
	SDL_Window *window;
	SDL_Renderer *renderer;

	//Initialize SDL (video and events)
	SDL_Init(SDL_INIT_VIDEO);
	//create window
	window = SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, windowFlags);
	//create renderer to draw on in window
	renderer = SDL_CreateRenderer(window, -1, rendererFlags);

	g_player = new Player(*renderer, 30, 30, 50, 50);
	g_player->velocity_ = 4;

	//Main loop
	EventData controller{ true, true };
	while (controller.loop) {
		
		//handle events (mouse, keyboard, etc)
		EventHandler(controller);

		//clear renderer (set everything black)
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);

		//render the player
		g_player->Render();
		//show rendering changes on screen
		SDL_RenderPresent(renderer);

		SDL_Delay(16); // ~60 updates per second
	}

	delete g_player;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	return EXIT_SUCCESS;
}

void EventHandler(EventData &data)
{
	//poll every event and handle them
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			data.loop = false;
			return;
		case SDL_WINDOWEVENT:
			switch (event.window.event) {
			case SDL_WINDOWEVENT_CLOSE:
				//TODO: only close window with same windowID
				data.loop = false;
				break;
			case SDL_WINDOWEVENT_RESIZED:
				data.render = true;
				break;
			}
			break;
		case SDL_MOUSEBUTTONDOWN:
		case SDL_MOUSEBUTTONUP:
		case SDL_MOUSEMOTION:
			EventHandler_Mouse(event, data);
			break;
		}
		EventHandler_Keyboard(event, data);
	}
}


void EventHandler_Mouse(SDL_Event &event, EventData &data)
{
	switch (event.button.button) {
	case SDL_BUTTON_LEFT:
		g_player->setPosition(event.button.x, event.button.y);
		break;
	case SDL_BUTTON_RIGHT:
		break;
	case SDL_BUTTON_MIDDLE:
		break;
	}
}

void EventHandler_Keyboard(SDL_Event &event, EventData &data)
{
	//alternate way to get key state, can also use the event
	const Uint8 *state = SDL_GetKeyboardState(NULL);

	int x = 1;
	int y = 1;
	double angles[3][3] = { { 225, 180, 135 }, { 270, -1, 90 }, { 315, 0, 45 } };
	if(state[SDL_SCANCODE_UP   ]) y++;
	if(state[SDL_SCANCODE_DOWN ]) y--;
	if(state[SDL_SCANCODE_LEFT ]) x--;
	if(state[SDL_SCANCODE_RIGHT]) x++;

	if (!(x == 1 && y == 1)) {
		double angle = angles[x][y];
		//move the player at that angle
		g_player->Move(angle);
	}
}