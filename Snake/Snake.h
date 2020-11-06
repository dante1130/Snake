#pragma once
#include "Object.h"
#include "Direction.h"
#include <vector>
class Snake :
    public Object
{
private:
    int prevX;
    int prevY;
    std::string spriteHead = "O";
    std::string spriteBody = "o";
    std::vector<Object> body;
    Direction direction;
    void CreateBody(int x, int y);
    
public:
    Snake();
    Snake(int x, int y, Direction direction);
    std::string getSpriteHead();
    std::string getSpriteBody();
    std::vector<Object> getBody();
    Direction getDirection();
    void MoveBody();
    void Grow();
    void Move(Direction direction);
    bool isCollideSelf();
};