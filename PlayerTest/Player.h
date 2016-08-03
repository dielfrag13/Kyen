#include <cmath>
#include <SDL2\SDL.h>

//todo: use texture instead of a rect

class Player
{
public:

	double velocity_;

	Player(SDL_Renderer &renderer, int width, int height, int startX = 0, int startY = 0);
	~Player();
	void Render(void);
	void setPosition(int x, int y);
	void Move(double angle);

private:
	SDL_Renderer &renderer_;
	SDL_Color color_;
	SDL_Rect rect_;
};