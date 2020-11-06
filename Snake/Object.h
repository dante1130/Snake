#pragma once
#include <string>
class Object
{
private:
	int X;
	int Y;
public:
	Object();
	Object(int x, int y);
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
};

