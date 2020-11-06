#include "Object.h"
Object::Object()
{
	X = NULL;
	Y = NULL;
}

Object::Object(int x, int y)
{
	X = x;
	Y = y;
}

int Object::getX()
{
	return X;
}

int Object::getY()
{
	return Y;
}

void Object::setX(int x)
{
	X = x;
}

void Object::setY(int y)
{
	Y = y;
}

void Object::MoveUp()
{
	Y--;
}

void Object::MoveDown()
{
	Y++;
}

void Object::MoveLeft()
{
	X--;
}

void Object::MoveRight()
{
	X++;
}