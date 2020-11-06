#include <iostream>
#include <conio.h>
#include <stdlib.h>

#include "Object.h"
#include "Snake.h"

void Draw(int height, int width, Object fruit, Snake snake)
{
    system("cls");
    // Top
    for (int i = 0; i < width+2; i++)
    {
        std::cout << "#";
    }
    std::cout << std::endl;

    // Canvas
    for (int i = 0; i < height; i++)
    {
        std::cout << "#";
        for (int j = 0; j < width; j++)
        {
            bool print = false;
            for (int k = 0; k < snake.getBody().size(); k++)
            {
                // If snake body
                if (j == snake.getBody()[k].getX()
                    && i == snake.getBody()[k].getY())
                {
                    std::cout << snake.getSpriteBody();
                    print = true;
                    break;
                }
            }
            if (print)
            {
                continue;
            }
            // If food
            else if (j == fruit.getX() && i == fruit.getY())
            {
                std::cout << "F";
            }
            // If snake head
            else if (j == snake.getX() && i == snake.getY())
            {
                std::cout << snake.getSpriteHead();
            }
            else
            {
                std::cout << " ";
            }
        }
        std::cout << "#" << std::endl;
    }
    
    // Bottom
    for (int i = 0; i < width + 2; i++)
    {
        std::cout << "#";
    }
}

void ControlSnake(Snake &snake)
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'w':
            snake.Move(Direction::UP);
            break;
        case 's':
            snake.Move(Direction::DOWN);
            break;
        case 'a':
            snake.Move(Direction::LEFT);
            break;
        case 'd':
            snake.Move(Direction::RIGHT);
            break;
        }
    }
    else
    {
        snake.Move(snake.getDirection());
    }
    snake.MoveBody();
}

bool isCollideFruit(Object fruit, Snake snake)
{
    return (fruit.getX() == snake.getX() && fruit.getY() == snake.getY());
}

bool isCollideWall(Snake snake, int height, int width)
{
    return (snake.getX() < 0 || snake.getY() < 0
        || snake.getY() > height || snake.getX() > width);
}

int main()
{
    bool gameOver = false;
    const int height = 24;
    const int width = 48;
    int score = 0;
    Object fruit(0 + rand() % width, 0 + rand() % height);
    Snake snake;
    snake.setX(5);
    snake.setY(5);
    while (!gameOver)
    {
        Draw(height, width, fruit, snake);
        ControlSnake(snake);
        if (isCollideFruit(fruit, snake))
        {
            snake.Grow();
            score++;
            fruit.setX(0 + rand() % width);
            fruit.setY(0 + rand() % height);
        }
        else if (isCollideWall(snake, height, width) || snake.isCollideSelf())
        {
            gameOver = true;
        }
        std::cout << std::endl << "Score: ";
    }
    std::cout << std::endl << "You lost!";
}
