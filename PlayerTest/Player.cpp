#include "Player.h"

//constructor
Player::Player(SDL_Renderer &renderer, int width, int height, int startX, int startY)
	: renderer_(renderer)
{
	color_ = SDL_Color{ 0, 255, 0, SDL_ALPHA_OPAQUE };
	rect_.x = startX;
	rect_.y = startY;
	rect_.w = width;
	rect_.h = height;
	velocity_ = 0;
}

//destructor
Player::~Player()
{

}

void Player::Render(void)
{
	//set renderer to player color
	SDL_SetRenderDrawColor(&renderer_, color_.r, color_.g, color_.b, color_.a);
	//draw a rectangle to represent the player
	SDL_RenderFillRect(&renderer_, &rect_);
}

void Player::setPosition(int x, int y)
{
	rect_.x = x;
	rect_.y = y;
}

void Player::Move(double angle)
{
	int xChange = (int)(velocity_ * cos(angle * M_PI / 180.0));
	int yChange = -(int)(velocity_ * sin(angle * M_PI / 180.0));

	rect_.x += xChange;
	rect_.y += yChange;
}