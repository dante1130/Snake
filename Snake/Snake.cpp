#include "Snake.h"
Snake::Snake()
{
	setX(8);
	setY(16);
	direction = Direction::RIGHT;
}

Snake::Snake(int x, int y, Direction direction)
{
	setX(x);
	setY(y);
	this->direction = direction;
}

std::string Snake::getSpriteHead()
{
	return spriteHead;
}

std::string Snake::getSpriteBody()
{
	return spriteBody;
}

std::vector<Object> Snake::getBody()
{
	return body;
}

Direction Snake::getDirection()
{
	return direction;
}

void Snake::CreateBody(int x, int y)
{
	switch (direction)
	{
	case Direction::UP:
		body.push_back(Object(x, y - 1));
		break;

	case Direction::DOWN:
		body.push_back(Object(x, y + 1));
		break;

	case Direction::LEFT:
		body.push_back(Object(x - 1, y));
		break;

	case Direction::RIGHT:
		body.push_back(Object(x + 1, y));
		break;
	}
}

void Snake::MoveBody()
{
	if (body.size() < 1) return;
	Object temp = body[0];
	Object temp2;
	body[0].setX(prevX);
	body[0].setY(prevY);
	for (int i = 1; i < body.size(); i++)
	{
		temp2 = body[i];
		body[i] = temp;
		temp = temp2;
	}
}

void Snake::Grow()
{
	if (body.size() == 0)
		CreateBody(getX(), getY());
	else
		CreateBody(body.back().getX(), body.back().getY());
}

void Snake::Move(Direction direction)
{
	switch (direction)
	{
	case Direction::UP:
		if (this->direction != Direction::DOWN)
		{
			prevX = getX();
			prevY = getY();
			MoveUp();
			this->direction = direction;
		}
		break;

	
	case Direction::DOWN:
		if (this->direction != Direction::UP)
		{
			prevX = getX();
			prevY = getY();
			MoveDown();
			this->direction = direction;
		}
		break;

	case Direction::LEFT:
		if (this->direction != Direction::RIGHT)
		{
			prevX = getX();
			prevY = getY();
			MoveLeft();
			this->direction = direction;
		}
		break;

	case Direction::RIGHT:
		if (this->direction != Direction::LEFT)
		{
			prevX = getX();
			prevY = getY();
			MoveRight();
			this->direction = direction;
		}
		break;
	}
}

bool Snake::isCollideSelf()
{
	for (int i = 0; i < body.size(); i++)
	{
		if (getX() == body[i].getX() && getY() == body[i].getY()) return true;
	}
	return false;
}